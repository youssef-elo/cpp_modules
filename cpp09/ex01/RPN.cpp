#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	if ( &other == this)
		return *this;
	return *this;
}

bool RPN::is_operator( char c )
{
	if ( c == '/' || c == '-' || c == '+' || c == '*')
		return true;
	return false;
}

long long RPN::make_operation(long long first, long long second, char operation)
{
	switch (operation)
	{
		case '+' :
			return first + second;
		case '-' :
			return first - second;
		case '/' :
		{
			if ( second == 0 )
				throw std::runtime_error("Error: Division by zero is invalid.");
			return first / second;
		}
	}
	return first * second;

}

long long RPN::calculate(std::string &expression)
{
	std::string buffer;
	std::stringstream ss(expression);
	long long first, second, result;

	while ( !lifo.empty() )
		lifo.pop();
	while ( ss >> buffer )
	{
		if (buffer.length() == 1 && isdigit(buffer[0]) )
		{
			lifo.push(buffer[0] - '0');
		}
		else if ( buffer.length() == 2 && buffer[0] == '-' && isdigit(buffer[1]) )
		{
			lifo.push((buffer[1] - '0') * (-1));
		}
		else if ( buffer.length() == 2 && buffer[0] == '+' && isdigit(buffer[1]) )
		{
			lifo.push(buffer[1] - '0');
		}
		else if ( buffer.length() == 1 && is_operator(buffer[0]))
		{
			if ( lifo.size() < 2)
			{
				throw std::runtime_error("Error: Not enough elements in the stack to make the operation.");
			}
			second = lifo.top();
			lifo.pop();
			first = lifo.top();
			lifo.pop();
			result = make_operation(first, second, buffer[0]);
			if ( result > std::numeric_limits<int>::max())
				throw std::range_error("Integer Overflow detected.");
			if ( result < std::numeric_limits<int>::min())
				throw std::range_error("Integer Underflow detected.");
			lifo.push(result);
		}
		else
		{
			throw std::invalid_argument("Error : invalid argument (arguments should either a single digit integer or an operator \"=-*/\") => " + buffer);
		}
	}
	if (lifo.size() != 1)
	{
		throw std::runtime_error("Error: Invalid expression, not enough operators.");
	}
	return lifo.top();
}