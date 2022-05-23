/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:44:39 by asimon            #+#    #+#             */
/*   Updated: 2022/05/23 03:49:25 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_gb_col
{
	void			*ptr;
	struct s_gb_col	*next;
}	t_gb_col;

// Structure pour les variables environement
typedef struct s_env
{
	char			*key;
	char			*value;
	int				no_value;
	struct s_env	*next;
}	t_env;

// Structure des commandes
typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				fd_in;
	int				fd_out;
	// Je dois gerer le parsing du '$?'
	char			*herdoc_file;
	int				herdoc_extend;
	struct	s_cmd	*next;
}	t_cmd;

// structure global
typedef struct s_shell
{
	t_env			*env;
	char			**builtins;
	t_cmd			*cmds;
	int				last_return;
	int				error;
	t_gb_col		*list;
	int				pid;
}	t_shell;

#endif