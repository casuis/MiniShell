# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 20:13:19 by asimon            #+#    #+#              #
#    Updated: 2022/05/23 04:05:56 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell

CC					=	clang

C_FLAG				=	-Wall -Wextra -Werror

DEBUG_FLAG			=	-g3

R_FLAG				=	-lreadline

CFILE_BUILTIN		=	cd.c			\
						echo.c			\
						env.c			\
						exit.c			\
						export.c		\
						pwd.c			\
						unset.c

CFILE_COR			=	main.c			\
						core.c			\
						prompt.c		\
						init.c			\
						signaux.c	

CFILE_PARS			=	add.c					\
						add_fctn.c				\
						functions_parsing.c		\
						list.c					\
						set_cmd.c				\
						va_env_fct.c			\
						var_env.c				\
						work_str.c				\
						herdoc_functions.c		\
						set_herdoc.c			\
						parsing.c				\
						parse_in_out.c			\
						ft_utils_parsing.c		\
						set_fd.c

CFILE_EXEC			=	exec.c					\
						functions_exec.c		\
						get_env_tab.c			\
						set_cmd_path.c

CFILE_GB			=	gb_collector_list.c

C_DIR				=	./src/

PARS_DIR_NAME		=	parsing/

EXEC_DIR_NAME		=	exec/

GB_DIR_NAME			=	garbage_collector/

BLTIN_DIR_NAME		=	builtins/

PARS_DIR			=	$(addprefix $(C_DIR), $(PARS_DIR_NAME))

EXEC_DIR			=	$(addprefix $(C_DIR), $(EXEC_DIR_NAME))

GB_DIR				=	$(addprefix $(C_DIR), $(GB_DIR_NAME))

BLTIN_DIR			=	$(addprefix $(C_DIR), $(BLTIN_DIR_NAME))

LIBFT_DIR			=	./libft/

LIBFT				=	$(LIBFT_DIR)libft.a

SRC					=	$(addprefix $(C_DIR), $(CFILE_COR))		\
						$(addprefix $(PARS_DIR), $(CFILE_PARS))	\
						$(addprefix $(EXEC_DIR), $(CFILE_EXEC))	\
						$(addprefix $(GB_DIR), $(CFILE_GB))		\
						$(addprefix $(BLTIN_DIR), $(CFILE_BUILTIN))

OBJ					=	$(SRC: .c=.o)

OBJS				=	$(C_DIR)*.o			\
						$(PARS_DIR)*.o		\
						$(EXEC_DIR)*.o		\
						$(GB_DIR)*.o		\
						$(BLTIN_DIR)*.o

all: $(NAME)

c.o:
	$(CC) $(C_FLAG) -c $< -o $@

lib:
	make -C $(LIBFT_DIR)

$(NAME): lib $(OBJ)
	$(CC) $(C_FLAG) $(OBJ) $(LIBFT) $(R_FLAG) -o $(NAME)

clean:
	rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)


debug: fclean lib $(OBJ)
	$(CC) $(C_FLAG) $(DEBUG_FLAG) $(OBJ) $(LIBFT) $(R_FLAG) -o $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
