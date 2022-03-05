/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:36:59 by asimon            #+#    #+#             */
/*   Updated: 2022/02/27 22:37:01 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include <readline/readline.h>
# include <readline/history.h>


t_cmd	*ft_add_list(t_cmd *start)
{
	t_cmd	*buff;
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	if (start != NULL)
	{
		buff = start->next;
		while (buff != NULL)
		{
			start = start->next;
			buff = start->next;
		}
		start->next = new;
	}
	new->next = NULL;
	return (new);
}

int		main(int argc, char **argv, char **penv)
{
	(void)argc;
	(void)argv;
	t_cmd	*start;
	t_cmd	*cmd;
	char	*str;
	int		i = 0;

	start = ft_add_list(NULL);
	cmd = start;
	while (i < 4)
	{
		cmd = ft_add_list(cmd);
		i++;
	}
	i = 0;
	while (start != NULL)
	{
		printf("Creation de list | %p\n", start);
		start = start->next;
	}
	readline("minishell$ ");
	return (0);
}
