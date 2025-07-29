// #include <limits>
// #include <iostream>
// #include <iomanip>
// #include <sstream>

// int main(int ac, char **av)
// {
// 	std::string tmp;
// 	std::cin >> tmp;;
// 	int ntmp;
// 	// if ( tmp == "+inff")
// 	// 	tmp[4] = 0;
// 	double ftmp = 87;
// 	std::stringstream ss(tmp);
// 	std::stringstream si(tmp);
// 	ss >> ftmp;
// 	if ( ss.fail())
// 		std::cout << "sdjnvjsdvjsdvjbdsvjd" << std::endl;
// 	si >> ntmp;
// 	if ( si.fail())
// 		std::cout << "int" << std::endl;


// 	// try 
// 	// {
// 	// 	// ntmp = stoi(tmp);
// 	// 	// ftmp = stod(tmp);

// 	// }
// 	// catch(std::exception& ex)
// 	// {
// 	// 	std::cout << ex.what() << std::endl;
// 	// 	// return 0;
// 	// }
// 	// std::cout << std::setprecision(1);

// 	std::cout << " int " << static_cast<int>(ntmp) << std::endl;
// 	std::cout << " float " << static_cast<float>(ftmp) << std::endl;
// 	std::cout << " double " << static_cast<double>(ftmp) << std::endl;
// 	std::cout << " char " << static_cast<char>(ntmp) << std::endl;

// 	// float finity = -std::numeric_limits<float>::infinity();
// 	// int a  = static_cast<int>(finity);
// 	// std::cout << finity << std::endl;
// 	// std::cout << "int " << a << std::endl;
// }


#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if ( ac != 2)
	{
		std::cout << "invalid input"<< std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
}