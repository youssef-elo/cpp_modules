NAME=form

FLAGS= -Wall -Werror -Wextra -std=c++98
FLAGS += -fsanitize=address -g

FILES= AForm.cpp PresidentialPardonForm.cpp Bureaucrat.cpp RobotomyRequestForm.cpp main.cpp ShrubberyCreationForm.cpp Intern.cpp

OFILES= $(FILES:.cpp=.o)

INCLUDES = AForm.hpp RobotomyRequestForm.hpp Bureaucrat.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp Intern.hpp

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