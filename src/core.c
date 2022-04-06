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

#include "./includes/minishell.h"
#define CYELLOW "\001\e[0;31m\002"
#define RESET   "\001\e[0m\002"

t_shell		shell;

int		ft_core(char **argv, int argc, char **penv)
{
	char            *str;
    t_shell        buff;
    const char           *prmpt;

	shell.env = set_env(penv);
    prmpt = "minishell ~ $ ";
    str = readline(prmpt);
    while (str != NULL)
    {
        if (ft_strlen(str) > 0)
            add_history(str);
		init_shell(penv);
        parsing(str);
        // Fct teste
		// Affichage test
        ft_test();
        ft_exec();
        // reinit_shell();

        str = readline(prmpt);
    }
	init_shell(penv);
	return (0);
}

