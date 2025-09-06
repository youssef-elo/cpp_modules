NAME=RPN

FLAGS= -Wall -Werror -Wextra -std=c++98
# FLAGS += -fsanitize=address -g

FILES= main.cpp RPN.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = RPN.hpp

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