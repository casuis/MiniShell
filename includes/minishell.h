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
	struct	s_cmd	*next;
	// int	aucune gestion pour << et >> pour l'instant
}	t_cmd;

// structure global
typedef struct s_shell
{
	t_env			*env;
	t_cmd			*cmds;
	int				error;
}	t_shell;


extern t_shell		shell;

// Chained list
t_cmd		*ft_add_list(t_cmd *start);
t_cmd		*get_last_elem();

// Functions
int			ft_strlen(char *str);
char		*prompt();
void		ft_error(char *prog, char *msg);
int			ft_strcmp(char *s1, char *s2);
int			quote_closed(char c, int *bol);
char		*ft_strncpy(char *str, int nb);
int			get_next_pipe(char *str);

// Env
char		*set_key_env(char *str);
char		*set_value_env(char *str);
t_env		*set_env(char **penv);
char		*get_va_env_value(char *str);
char		*get_va_env_key(char *str);
char		*get_va_env(char *str);
int			count_va_envl(int *count, char *str);

// Work_str
int			pass_file(char *str, int i, int balise, int bol);
static int	get_work_str_size(char *str, int i, int balise);
char		*set_work_str(char *str, int i, int balise);

// Set Cmd
void		set_cmd_arg(char **work_str, t_cmd *cmds);
char		*get_cmd(char **str, t_cmd *cmds);

// Add
char		*set_new_ret(char *old, int size, int *i);
int			get_size(char *str, char del);
char		**add_arg(char *str, t_cmd *cmd);
void		send_new_arg(char *str, t_cmd *cmd);
char		*ft_add_var_env(char *old, char **str, t_cmd *cmd);
char		*ft_add_single_quote(char *old, char **str);
char		*ft_add_double_quote(char *old, char **str);
int			get_ldbl_quote(char *str);
int			ft_add(char *str, char *ret);
char		*ft_add_char(char *ret, char **str);

// Core
int			ft_core(char **argv, int argc, char **penv);
void		parsing(char *str);
void		deffine_cmd_sep(char *str, int pos, t_cmd *cmd);

// Prompt
char    	*prompt();

// Init
void		init_shell(char **penv);
t_cmd		*init_cmd(t_cmd	*cmd);

// +
char		*ft_strjoin(char *s1, char *s2);
#endif