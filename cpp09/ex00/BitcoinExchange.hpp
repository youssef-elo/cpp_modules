#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> database;
		
		typedef std::map<std::string, double>::iterator database_it;
		enum error_code {
			BAD_INPUT,
			BAD_DATE,
			NEGATIVE,
			LARGE
		};
		
		bool check_date( const std::string& date );
		std::string check_date_input( std::string& line, bool& check,  size_t& last );
		void digest_input_line( std::string& line );
		void print_err( error_code code,  const std::string& line );
		bool check_database_line( const std::string& line );
		bool is_leap( int year );

		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );

		bool read_file( const std::string& file_name);
};


#endif