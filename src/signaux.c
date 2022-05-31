/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 01:25:07 by asimon            #+#    #+#             */
/*   Updated: 2022/05/31 01:54:12 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_handler(int nb)
{
	int		test_fd;
	struct termios *test2;
	struct termios *old;

	test_fd = 1;
	test2 = malloc(sizeof(struct termios) * 1);
	old = malloc(sizeof(struct termios) * 1);
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
	{
		test_fd = ttyslot();
		if (isatty(test_fd))
		{

			if (tcgetattr(test_fd, test2) == 0)
			{
				tcgetattr(test_fd, old);
				test2->c_lflag = ECHO | ICANON;
				test2->c_cc[VQUIT] = 0;
				tcsetattr(test_fd, 0, test2);
				tcsetattr(test_fd, 0, old);
			}
		}
	}
}


void	ft_signaux(void)
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT,ft_handler);
}
