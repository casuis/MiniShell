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


#include "./include/minishell_parsing.h"

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
	else
		shell.cmds = new;
	new->next = NULL;
	new = init_cmd(new);
	return (new);
}


t_cmd	*get_last_elem()
{
	t_cmd	*buff;

	buff = shell.cmds;
	if (buff != NULL)
		while (buff->next != NULL)
			buff = buff->next;
	return (buff);
}