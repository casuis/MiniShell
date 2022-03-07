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
typedef struct s_venv
{
	char			*key;
	char			*value;
	struct s_venv	*next;
}	t_venv;

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
	t_venv			env;
	t_cmd			cmds;
	int				error;
	struct s_shell	*next;
}	t_shell;

t_shell		shell;

int		ft_strlen(char *str);
char	*prompt();
void	ft_error(char *prog, char *msg);

#endif