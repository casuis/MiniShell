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

int		main(int argc, char **argv, char **env)
{
	ft_core(argv, argc, env);
	return (0);
}