NAME=DiamondTrap

FLAGS= -Wall -Werror -Wextra -std=c++98
# FLAGS += -fsanitize=address

FILES= ClapTrap.cpp ScavTrap.cpp main.cpp FragTrap.cpp DiamondTrap.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

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