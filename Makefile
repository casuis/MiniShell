# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 20:13:19 by asimon            #+#    #+#              #
#    Updated: 2022/03/19 20:13:20 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

CC				=	clang

C_FLAG			=	-Wall -Wextra -Werror

R_FLAG			=	-lreadline

C_FILE			=	main.c			\
					add_fctn.c		\
					add.c			\
					command.c		\
					core.c			\
					functions.c		\
					init.c			\
					list.c			\
					prompt.c		\
					set_cmd.c		\
					va_env_fct.c	\
					var_env.c		\
					work_str.c		\
					parting.c		

C_DIR			=	./src/

SRC				=	$(addprefix $(C_DIR), $(C_FILE)) 

OBJ				=	$(SRC: .c=.o)

OBJS			=	$(C_DIR)*.o

all: $(NAME)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(R_FLAG) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
