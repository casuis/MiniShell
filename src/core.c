/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:50:32 by asimon            #+#    #+#             */
/*   Updated: 2022/03/02 16:50:33 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_core(char **argv, int argc, char **penv)
{
	char	*prpt;

	prpt = prompt();
	return (0);
}

int		main(int argc, char **argv, char **penv)
{
	ft_core(argv, argc, penv);
	return (0)
}
