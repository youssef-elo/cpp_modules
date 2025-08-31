#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> database;
		bool check_date( const std::string& date );
		bool digest_input_line( std::string& line );
		bool check_database_line( const std::string& line );
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );
};

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
	while ( data_stream >> buffer )
	{
		if ( !check_database_line(buffer) )
			throw std::runtime_error(std::string("Invalid line in data.csv file ") + std::to_string(line));
		line++;
	}
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
	for ( int i = 0; i < value.length(); i++)
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

bool BitcoinExchange::digest_input_line( std::string& line )
{
	
}

#endif