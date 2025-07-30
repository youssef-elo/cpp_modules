#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

enum TYPE
{
	CHARACHTER,
	INVALID,
	VALID,
	EDGES
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public :
		static void convert(std::string arg);
};

TYPE parse( std::string arg );
void FromCharacter( std::string arg );
void FromEdges( std::string arg );
void From_int_float_double( std::string arg );

#endif