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
	./$(NAME) 6 14 5 12 1 3 7 13 8 2 11 15 4 10 9 16

.PHONY: all clean fclean re test