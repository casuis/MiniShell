/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:01:03 by asimon            #+#    #+#             */
/*   Updated: 2022/03/02 16:01:04 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/minishell.h"

char    *prompt()
{
    char        *str;

    str = readline("minishell$ ");
    while (str != NULL)
    {
        if (ft_strlen(str) > 0)
            add_history(str);
        parting(str);
        // Fct teste
        while (shell.cmds != NULL)
        {
            printf("valeur des cmds: |%s|\n", shell.cmds->cmd);
            shell.cmds = shell.cmds->next;
        }
        str = readline("minishell$ ");
    }
    return (str);
}
