/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:02:58 by asimon            #+#    #+#             */
/*   Updated: 2022/03/26 18:03:01 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_exec.h"


void	ft_exec()
{
	char	**path;
	t_cmd	*cmd;
	int		i;

	cmd = shell.cmds;
	path = ft_split(get_va_env_value("PATH"), ':');
	i = 0;
	if (cmd == NULL)
		return ;
	if (is_builtin(cmd->cmd))
	{
		printf("yes\n");
	}
	else
		printf("no\n");
	// Verification de si builtin ou pas
 
	// Si oui: 
		
		// Lancement du builtin associe avec les commandes

	// Si Non:

		// Creation du path complet en cmd
		// FORK de l'environement pour execution
	if (path != NULL)
	{
		while (path[i] != NULL)
		{
			printf("|%s|\n", path[i]);
			i++;
		}
	}
}