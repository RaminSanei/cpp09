NAME = btc

FLAGS = -Wall -Wextra -Werror -std=c++17

SRC = main.cpp  BitcoinExchange.cpp

CXX = c++

all: $(NAME)

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

fclean:
	$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: all fclean re