#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <limits>

class RPN {

	private:
		std::stack<long long> lifo;
		bool is_operator( char c );
		long long make_operation(long long first, long long second, char operation);

	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		long long calculate( std::string& expression );
};

#endif