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
	./$(NAME) 52 26 19 32 11 51 55 94 71 1 48 21 40 30 75 17 97 2 14 46 41 95 31 68 84 23 79 50 6 22 59 39 3 61 10 89 16 49 93 67 43 12 47 4 53 57 65 37 5 36 18 70 91 62 15 96 100 66 88 69 25 20 76 98 90 8 9 74 13 34 27 58 33 77 72 99 87 86 85 44 83 24 80 45 73 7 64 78 60 54 42 92 63 35 29 56 82 38 28 81

.PHONY: all clean fclean re test