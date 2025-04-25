NAME= PhoneBook

FLAGS= -Wall -Werror -Wextra -std=c++98
FILES= Contact.cpp main.cpp PhoneBook.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Contact.hpp PhoneBook.hpp

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