#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange {
	private:
		enum error_code {
			BAD_INPUT,
			NEGATIVE,
			LARGE
		};
		std::map<std::string, double> database;
		typedef std::map<std::string, double>::iterator database_it;
		bool check_date( const std::string& date );
		void digest_input_line( std::string& line );
		void print_err( error_code code,  const std::string& line );
		bool check_database_line( const std::string& line );
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );

		bool read_file( const std::string& file_name);
};

bool BitcoinExchange::read_file( const std::string& file_name)
{
	int line = 1;
	std::string buffer;
	std::ifstream input_file(file_name);

	if (!input_file.is_open())
	{
		std::cerr << "Error: could not open file: " << file_name << '.' << std::endl;
		return false;
	}
	while (std::getline(input_file, buffer))
	{
		if ( (line == 1 && buffer == "date | value") || buffer == "")
		{
			line++;
			continue;
		}
		digest_input_line(buffer);
		line++;
	}
	input_file.close();
	return true;
}


BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if ( this == &other)
		return *this;
	database = other.database;
	return *this;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
{
	database = other.database;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange()
{
	int line = 1;
	std::string buffer;
	std::ifstream data_stream("data.csv");

	if ( !data_stream.is_open() )
		throw std::runtime_error("Cannot open database file data.csv");
	while ( std::getline(data_stream, buffer))
	{
		if ( line == 1 && buffer == "date,exchange_rate")
		{
			line++;
			continue;
		}
		else if ( !check_database_line(buffer) )
			throw std::runtime_error(std::string("Invalid line in data.csv file ") + std::to_string(line));
		line++;
	}
	data_stream.close();
}

bool is_leap( int year )
{
	if ( year % 4 == 0 && year % 100 != 0 )
		return true;
	if ( year % 400 == 0)
		return true;
	return false;
}

bool BitcoinExchange::check_date( const std::string& date )
{
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = 0, month = 0, day = 0;
	size_t line_length = date.length();

	if ( line_length != 10)
		return false;
	if ( date[4] != '-' || date[7] != '-')
		return false;
	for ( size_t i = 0 ; i < line_length; i++)
	{
		if ( !isdigit(date[i]) && i != 4 && i != 7)
			return false;
	}
	year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	month = (date[5] - '0') * 10 + (date[6] - '0');
	day = (date[8] - '0') * 10 + (date[9] - '0');
	if (is_leap(year))
		months[1] = 29;
	if ( year == 0 || month == 0 || month > 12)
		return false;
	if ( day == 0 || day > months[month - 1] )
		return false;
	return true;
}


bool BitcoinExchange::check_database_line(const std::string& line )
{
	if ( line.length() < 12)
		return false;
	double d_value;
	std::string date;
	std::string value;
	size_t comma_position = line.find_first_of(',');

	if ( comma_position == std::string::npos )
		return false;
	date = line.substr(0, comma_position);
	if ( !check_date(date) || comma_position == line.length() - 1 )
		return false;

	value = line.substr(comma_position + 1);
	for ( size_t i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.')
			return false;
	}

	std::stringstream ss(value);
	ss >> d_value;
	if ( d_value < 0 || ss.fail() || !ss.eof())
		return false;
	database[date] = d_value;
	return true;
}



void BitcoinExchange::print_err( error_code code, const std::string& line )
{
	if ( code == BAD_INPUT )
		std::cerr << "Error: bad_input => " << line << std::endl;
	if ( code == NEGATIVE )
		std::cerr << "Error: not a positive number." << std::endl;
	if ( code == LARGE )
		std::cerr << "Error: too large a number." << std::endl;
}

void BitcoinExchange::digest_input_line( std::string& line )
{
	float f_value;
	std::string date; 
	std::string value;
	double final_price;
	database_it database_value;

	if ( line.length() < 14)
		return print_err(BAD_INPUT, line);

	size_t seperator_position = line.find_first_of('|');
	if ( seperator_position == std::string::npos  || seperator_position == line.length() - 1  || seperator_position != 11)
		return print_err(BAD_INPUT, line);
	if ( line[seperator_position - 1] != ' ' || line[seperator_position + 1] != ' ')
		return print_err(BAD_INPUT, line);
	date = line.substr(0, seperator_position - 1 );
	if ( !check_date(date))
		return print_err(BAD_INPUT, line);
	value  = line.substr(seperator_position + 2);
	std::stringstream ss(value);
	ss >> f_value;
	if ( ss.fail() || !ss.eof() )
		return print_err(BAD_INPUT , line);
	if ( f_value < 0 )
		return print_err(NEGATIVE, line);
	if ( f_value > 1000 )
		return print_err( LARGE, line);
	if ( database.size() == 0)
	{
		std::cerr << "Error: Database is empty cannot retrieve any price." << std::endl;
	}
	database_value = database.lower_bound(date);
	final_price = (database_value->second) * f_value;
	std::cout << date << " => " << f_value << " = " << final_price << std::endl;
}

#endif