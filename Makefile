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
					parsing.c		\
					parse_in_out.c			

C_DIR			=	./src/

LIBFT_DIR		=	./libft/

LIBFT			=	$(LIBFT_DIR)libft.a

SRC				=	$(addprefix $(C_DIR), $(C_FILE)) 

OBJ				=	$(SRC: .c=.o)

OBJS			=	$(C_DIR)*.o

all: $(NAME)

c.o:
	$(CC) $(FLAG) -c $< -o $@

lib:
	make -C $(LIBFT_DIR)

$(NAME): lib $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBFT) $(R_FLAG) -o $(NAME)

clean:
	rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
