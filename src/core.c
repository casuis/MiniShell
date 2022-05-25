/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:50:32 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:37:43 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

t_shell		shell;

int		ft_core(char **penv)
{
	char            *str;
    const char		*prmpt;

	shell.env = set_env(penv);
	// ft_signaux();
    prmpt = "minishell ~ $ ";
    str = readline(prmpt);
    while (str != NULL)
    {
		init_gb_col();
		gb_col_add_list(str);
        if (ft_strlen(str) > 0)
            add_history(str);
		init_shell(penv);
        parsing(str);
		if (shell.error != 1)
			ft_core_exec();
		del_herdoc();
        free_gb_col();
        str = readline(prmpt);
    }
	init_shell(penv);
	return (0);
}

