#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
	private:
		std::stack<long long> lifo;
		long long make_operation(long long first, long long second, char operation);
		bool is_operator( char c );

	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		long long calculate( std::string& expression );
};

#endif