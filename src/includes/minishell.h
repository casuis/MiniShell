/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:56 by asimon            #+#    #+#             */
/*   Updated: 2022/02/04 19:09:57 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"

# include <readline/readline.h>
# include <readline/history.h>

// Structure pour les variables environement
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// Structure des commandes
typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				fd_in;
	int				fd_out;
	char			*herdoc_file;
	struct	s_cmd	*next;
	// int	aucune gestion pour << et >> pour l'instant
}	t_cmd;

// structure global
typedef struct s_shell
{
	t_env			*env;
	char			**builtins;
	t_cmd			*cmds;
	int				error;
}	t_shell;


extern t_shell		shell;

// Functions
char		*prompt();
void		ft_error(char *prog, char *msg);
int			ft_strcmp(char *s1, char *s2);

// Chained list
t_cmd		*ft_add_list(t_cmd *start);
t_cmd		*get_last_elem();

// Core
int			ft_core(char **argv, int argc, char **penv);
void		parsing(char *str);
void		deffine_cmd_sep(char *str, int i, int pos, t_cmd *cmd);
void		ft_exec();

// Env
char		*set_key_env(char *str);
char		*set_value_env(char *str);
t_env		*set_env(char **penv);
char		*get_va_env_value(char *str);
char		*get_va_env_key(char *str);
char		*get_va_env(char *str);
int			count_va_envl(int *count, char *str);

// Init
void		init_shell(char **penv);
t_cmd		*init_cmd(t_cmd	*cmd);
void		reinit_shell();

// +
void		ft_test();

#endif