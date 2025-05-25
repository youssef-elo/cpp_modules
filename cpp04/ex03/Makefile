NAME=interfaces

FLAGS=  -std=c++98
# FLAGS= -Wall -Werror -Wextra -std=c++98
FLAGS += -fsanitize=address -g

FILES= main.cpp AMateria.cpp   Cure.cpp  MateriaSource.cpp Character.cpp  Ice.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = AMateria.hpp Ice.hpp MateriaSource.hpp Character.hpp ICharacter.hpp Cure.hpp IMateriaSource.hpp

all : $(NAME)

$(NAME) : $(OFILES)
	c++ $(FLAGS) $(OFILES) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all