#include "ScalarConverter.hpp"

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
