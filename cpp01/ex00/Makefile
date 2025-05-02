NAME=zombie

FLAGS= -Wall -Werror -Wextra -std=c++98
# FLAGS += -fsanitize=address

FILES= main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = Zombie.hpp

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