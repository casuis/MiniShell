/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 01:25:07 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 01:08:05 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_handler(int nb)
{
//	char	*prmpt;

//	prmpt = "minishell ~ $ ";
	if (nb == SIGINT)
	{
		if (shell.pid != 0)
		{
			// printf("\b");
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			shell.error = 1;
		}
	}
	else if (nb == SIGQUIT)
		exit(EXIT_SUCCESS);
}


void	ft_signaux(void)
{
	struct sigaction sa;

	sa.sa_handler = ft_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
