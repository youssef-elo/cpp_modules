NAME=serialize

FLAGS= -Wall -Werror -Wextra -std=c++98
# FLAGS += -fsanitize=address -g

FILES= Serializer.cpp main.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Serializer.hpp Data.hpp

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