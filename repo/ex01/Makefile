NAME = RPN
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
SRCS = $(addprefix src/, \
	main.cpp \
	RPN.cpp \
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
	read arg ; ./$(NAME) "$$arg"

.PHONY: all clean fclean re test