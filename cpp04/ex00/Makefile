NAME=zoo

FLAGS= -Wall -Werror -Wextra -std=c++98
# FLAGS += -fsanitize=address

FILES= Animal.cpp Dog.cpp WrongAnimal.cpp Cat.cpp main.cpp WrongCat.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Animal.hpp Dog.hpp WrongCat.hpp Cat.hpp WrongAnimal.hpp

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