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

NAME				=	minishell

CC					=	clang

C_FLAG				=	-Wall -Wextra -Werror

R_FLAG				=	-lreadline

CFILE_COR			=	main.c			\
						core.c			\
						prompt.c		\
						init.c			

CFILE_PARS			=	add.c					\
						add_fctn.c				\
						functions_parting.c		\
						list.c					\
						set_cmd.c				\
						va_env_fct.c			\
						var_env.c				\
						work_str.c				\
						parsing.c				\
						parse_in_out.c

CFILE_EXEC			=	exec.c					\
						functions_exec.c

C_DIR				=	./src/

PARS_DIR_NAME		=	parsing/

EXEC_DIR_NAME		=	exec/

PARS_DIR			=	$(addprefix $(C_DIR), $(PARS_DIR_NAME))

EXEC_DIR			=	$(addprefix $(C_DIR), $(EXEC_DIR_NAME))

LIBFT_DIR			=	./libft/

LIBFT				=	$(LIBFT_DIR)libft.a

SRC					=	$(addprefix $(C_DIR), $(CFILE_COR))		\
						$(addprefix $(PARS_DIR), $(CFILE_PARS))	\
						$(addprefix $(EXEC_DIR), $(CFILE_EXEC))	

OBJ					=	$(SRC: .c=.o)

OBJS				=	$(C_DIR)*.o			\
						$(PARS_DIR)*.o		\
						$(EXEC_DIR)*.o

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
