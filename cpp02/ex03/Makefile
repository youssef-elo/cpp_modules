NAME=triangle

FLAGS= -Wall -Werror -Wextra -std=c++98
FLAGS += -fsanitize=address

FILES= bsp.cpp Fixed.cpp main.cpp Point.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Point.hpp Fixed.hpp 

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