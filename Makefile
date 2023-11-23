NAME = pipex

SRC = source/main.c source/pipex.c source/path.c source/child.c

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
		@./$(NAME) file1 "ls" "cat -e" file2
		< file1 ls | cat -e > file3
		cmp file2 file3

#cmd << LIMITER | cmd1 >> file

exe2: all
		@./$(NAME) file1 "ls" "wc -l" "cat -e" "cat -e" "cat -e" file2
		< file1 ls | wc -l | cat -e | cat -e | cat -e > file3
		cmp file2 file3

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
