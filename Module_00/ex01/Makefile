CXX = c++ 
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = phonebook

SRC = main.cpp\
	Contact.cpp\
	PhoneBook.cpp\
	PhoneBook_utils.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re