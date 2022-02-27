/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:08:36 by asimon            #+#    #+#             */
/*   Updated: 2022/02/04 19:08:37 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/minishell.h" 
# include <unistd.h>
# include <stdlib.h>
int		main(int argc, char **argv, char **env)
{
	char **arg = (char **)malloc(1);

	arg[0] = malloc(9999);
	arg[0] = "~/42/Minishell";

	execve("../includes/cd", arg, env);
	return (0);
}