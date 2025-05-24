#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	private:
		std::string ideas[100];
		int index_of_thoughts;
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		void set_idea(std::string thought);
		const std::string& get_idea(int index) const;
};


#endif