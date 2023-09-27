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

#exe: all
#		@./$(NAME) file1 "ls" "grep file" file2

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
