NAME			=	minishell

CC				=	clang

C_FLAG			=	-Wall -Wextra -Werror

R_FLAG			=	-lreadline

C_FILE			=	main.c

C_DIR			=	./src/

SRC				=	$(addprefix $(C_DIR), $(C_FILE)) 

OBJ				=	$(SRC: .c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(R_FLAG) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re