NAME=PmergeMe

WFLAGS= -Wall -Wextra -Werror 
FLAGS= $(WFLAGS) -std=c++98
FLAGS += -fsanitize=address -g3

FILES= main.cpp PmergeMe.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = PmergeMe.hpp

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