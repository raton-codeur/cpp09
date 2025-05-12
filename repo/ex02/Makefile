NAME = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -fsanitize=address -g3
SRCS = $(addprefix src/, \
	main.cpp \
	PmergeMe.cpp \
)
OBJS = $(patsubst src/%.cpp, tmp/%.o, $(SRCS))

all : $(NAME)

tmp/%.o : src/%.cpp
	@ mkdir -p tmp
	c++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $@

clean :
	@ rm -rf tmp && echo "clean"

fclean : clean
	@ rm -f $(NAME) && echo "fclean"

re : fclean all

test : re
	./$(NAME) 2 6 4 8 10 11 5 14 9 18 13 19 20 22
	@ # ./$(NAME) 16 1 24 9 28 3 29 14 12 5 8 20 4 22 10 23 15 6 11 26 18 19 21 27 2 25 13 30 17 7

.PHONY: all clean fclean re test