/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 01:25:07 by asimon            #+#    #+#             */
/*   Updated: 2022/05/26 21:47:27 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_handler(int nb)
{
	if (nb == SIGINT)
	{
		if (shell.pid == 1)
		{
			write(2, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			shell.error = 1;
		}
	}
	else if (nb == SIGQUIT)
		printf("\b\b  \b\b");
}


void	ft_signaux(void)
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT,ft_handler);
}
