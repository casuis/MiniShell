NAME			=	minishell

CC				=	clang

FLAG			=	-Wall -Wextra -Werror

C_FILE			=	main.c

C_DIR			=	./src/

SRC				=	$(addprefix $(C_DIR), $(C_FILE)) 

OBJ				=	$(SRC: .c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re