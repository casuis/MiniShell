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
    char            *str;
    t_shell        buff;
    int         y = 0; // Test

    str = readline("minishell$ ");
    while (str != NULL)
    {
        buff = shell;
        if (ft_strlen(str) > 0)
            add_history(str);
        parsing(str);
        shell.error = 0;
        // Fct teste
		// Affichage test
        // ---------------------------------------------	
		while (buff.cmds->args[y] != NULL)
        {
            printf("valeur de args: |%s|\n", buff.cmds->args[y]);
            y++;
        }
        printf("valeur de fd_in: %d\nValeur de fd_out: %d\n", buff.cmds->fd_in, buff.cmds->fd_out);
        while (buff.cmds != NULL)
        {
            printf("valeur des cmds: |%s|\n", buff.cmds->cmd);
            buff.cmds = buff.cmds->next;
        }
		// -------------------------------------------------------------------------------
        str = readline("minishell$ ");
    }
    return (str);
}
