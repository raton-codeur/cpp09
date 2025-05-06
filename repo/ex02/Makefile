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
	./$(NAME) 3 4 1 6 2 7 5 9 8 10 

.PHONY: all clean fclean re test