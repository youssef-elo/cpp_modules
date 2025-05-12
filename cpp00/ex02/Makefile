NAME= GlobalBanksters

FLAGS= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

FILES= Account.cpp tests.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Account.hpp

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