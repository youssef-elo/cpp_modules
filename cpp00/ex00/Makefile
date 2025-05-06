NAME= megaphone

FLAGS= -Wall -Werror -Wextra -std=c++98

FILES= megaphone.cpp

OFILES= $(FILES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	c++ $(FLAGS) $(OFILES) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all