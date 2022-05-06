/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_collector_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:36:18 by asimon            #+#    #+#             */
/*   Updated: 2022/05/04 10:36:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/gb_collector.h"

void	gb_col_add_list(void *ptr)
{
	t_gb_col	*list;
	t_gb_col	*current;

	if (shell.list == NULL)
		return ;
	current = shell.list;
	while (current->next != NULL)
		current = current->next;
	if (current->ptr == NULL)
		current->ptr = ptr;
	else
	{
		list = malloc(sizeof(t_gb_col) * 1);
		list->ptr = ptr;
		current->next = list;
		current = list;
	}
	current->next = NULL;
}

void	free_gb_col(void)
{
	t_gb_col	*buff;

	buff = shell.list;
	while (buff != NULL)
	{
		if (buff->ptr != NULL)
			free(buff->ptr);
		buff = shell.list->next;
		free(shell.list);
		shell.list = buff;
	}
}
