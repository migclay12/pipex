NAME = pipex
SRC = main.c

OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror

LIB = ../libft

all: ${NAME}

${NAME}: ${OBJ}
		make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a

$(OBJ): $(SRC)
		@gcc $(FLAGS) -c $(SRC)

exe: all
		@./$(NAME)

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
