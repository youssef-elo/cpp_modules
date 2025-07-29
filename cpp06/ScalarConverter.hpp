#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <string>
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
		static TYPE parse(std::string arg);
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public :
		static void convert(std::string arg);

};
ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

TYPE ScalarConverter::parse(std::string arg)
{
	if ( arg == "nan" || arg == "-inf" || arg == "+inf" || arg == "-inff" || arg == "+inff" || arg == "nanf")
		return EDGES;
	if (arg.length() == 1 && !isdigit(arg[0]))
		return CHARACHTER;
	int f = -1;
	int d = -1;
	int f_count = 0;
	int d_count = 0;
	int n = arg.length();
	for ( size_t i = 0; i < arg.length(); i++)
	{
		if (arg[i] == '.')
		{
			d = i;
			d_count++;
		}
		else if ( arg[i] == 'f')
		{
			f = i;
			f_count++;
		}
		else if (!isdigit(arg[i]))
			return INVALID;
	}
	if ( d_count > 1 || f_count > 1 ||  ( f != -1 && f != n - 1 ))
		return INVALID;
	if ( d_count && !f_count)
		return VALID;
	if ( (d_count && f_count) || f_count )
		return VALID;
	if ( !d_count && !f_count)
		return VALID;
	return INVALID;
}

void FromCharacter( std::string arg)
{
	int i;
	char c;
	float f;
	double d;

	c = arg[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if ( c < 127 && c > 31)
		std::cout << "char: '" << c << "'" << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::setprecision(1) << "double: " << d << std::endl;
}

void FromEdges( std::string arg)
{
	float f;
	double d;

	std::cout << "char: impossible\nint: impossible" << std::endl;

	if ( arg == "nanf")
		arg[3] = 0;
	if ( arg == "+inff" || arg == "-inff")
		arg[4] = 0;

	std::stringstream ss(arg);

	ss >> d;
	f = static_cast<float>(d);
	std::cout << "float: " << f  << "f" << std::endl << "double: " << d << std::endl;
}

void From_int_float_double( std::string arg )
{
	double d;

	if (arg[arg.length() - 1] == 'f')
		arg[arg.length() - 1] = 0;
	std::stringstream ss(arg);
	ss >> d;
	if ( d >= 0 && d <= 255)
	{
		if ( d >= 32 && d <= 126)
			std::cout << "char : '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else 
		std::cout << "char: impossible" << std::endl;
	if (std::isfinite(d) && d < INT_MAX && d > INT_MIN)
	{
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
	if ((arg.find(".") == std::string::npos) || (arg.find(".") == arg.length() - 1))
		std::cout << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string arg)
{
	TYPE ret = parse(arg);

	if ( ret == INVALID)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::showpoint;
	if ( ret == CHARACHTER)
	{
		FromCharacter(arg);
	}
	else if ( ret == EDGES)
	{
		FromEdges(arg);
	}
	else if ( ret == VALID)
	{
		From_int_float_double(arg);
	}
}

#endif