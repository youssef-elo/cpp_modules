NAME=Animals

FLAGS= -Wall -Werror -Wextra -std=c++98
FLAGS += -fsanitize=address

FILES= Animal.cpp Cat.cpp Dog.cpp main.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Animal.hpp Cat.hpp Dog.hpp

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