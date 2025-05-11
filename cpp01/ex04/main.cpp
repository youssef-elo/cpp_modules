#include <iostream>
#include <fstream>
#include <string>

int error_exit(std::string err_msg)
{
	std::cerr << err_msg << std::endl;
	return 1;
}

void replace_instances(std::string& r_buffer, std::string s1, std::string s2)
{
	size_t index;
	size_t pre = 0;
	std::string str = r_buffer;

	r_buffer.clear();
	index = str.find(s1);
	while(index != std::string::npos)
	{
		r_buffer += str.substr(0, index);
		r_buffer += s2;
		if (pre)
			pre = index + s1.length() - 1;
		str = str.substr(index + s1.length());
		index = str.find(s1);
	}
	if (str.length())
		r_buffer += str;
}

int mygetline(std::ifstream& input_f, std::string& line)
{
	char rc;
	int i = 0;

	line.clear();
	while(input_f.get(rc))
	{
		line += rc;
		if (rc == '\n')
			return 1;
		i++;
	}
	if (i == 0)
		return 0;
	return 1;
}

int main(int ac, char **av)
{
	std::string replace_file;
	std::string r_buffer;
	int i = 0;

	if (ac != 4)
		return (error_exit("Program takes these parameters: a filename and two strings, s1 and s2."));
	replace_file = av[1] + std::string(".replace");
	if (!av[1][0] || !av[2][0] || !av[3][0])
		return (error_exit("Enter a valid string"));
	std::ifstream input_f(av[1]);
	if (!input_f)
		return (error_exit("Cannot open file for reading"));
	std::ofstream output_f(replace_file.c_str());
	if (!output_f)
		return (error_exit("Cannot open file for writing"));
	while(mygetline(input_f, r_buffer))
	{
		replace_instances(r_buffer, av[2], av[3]);
		output_f << r_buffer;
		i++;
	}
}
