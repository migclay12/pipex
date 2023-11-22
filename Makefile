NAME = pipex
SRC = anything/main.c anything/path.c anything/stuff.c

OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror

LIB = libft

all: ${NAME}

${NAME}: ${OBJ}
		make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a

#$(OBJ): $(SRC)
#		@gcc $(FLAGS) -c $(SRC)

exe: all
		@./$(NAME) file1 "ls" "wc -l" "cat -e" "cat -e" "cat -e" file2
#< file1 ls | wc -l | cat -e > file3
#cmd << LIMITER | cmd1 >> file
exe2:
		cmp file2 file3

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
