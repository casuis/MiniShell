/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_collector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:35:12 by asimon            #+#    #+#             */
/*   Updated: 2022/05/06 14:35:14 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GB_COLLECTOR_H
# define GB_COLLECTOR_H
# include "../../includes/minishell.h"

typedef struct s_gb_col
{
	void			*ptr;
	struct s_gb_col	*next;
}	t_gb_col;

void	gb_col_add_list(void *ptr);
void	free_gb_col(void);
#endif
