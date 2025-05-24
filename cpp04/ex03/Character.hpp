#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

typedef struct s_garbage garbage;

struct s_garbage{
	AMateria *add;
	struct s_garbage *next;
};

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *items[4];
		static garbage *head;
	public:
		Character();
		Character(std::string name_arg);
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void keep_add(AMateria *removed);
		void use(int idx, ICharacter &target);
};


#endif