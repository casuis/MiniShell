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

    y = 0;
    str = readline("minishell$ ");
    while (str != NULL)
    {
        if (ft_strlen(str) > 0)
            add_history(str);
        parsing(str);
        shell.error = 0;
        // Fct teste
		// Affichage test
        ft_test();
        
        str = readline("minishell$ ");
    }
    return (str);
}

void    ft_test()
{
    t_shell    buff;
    int         y;

    y = 0;
    buff = shell;
    while (buff.cmds != NULL)
    {
        printf("------------------------------------\n");
        printf("valeur des cmds: |%s|\n", buff.cmds->cmd);
        if (buff.cmds->args != NULL)
        {
            while (buff.cmds->args[y] != NULL)
            {
                printf("valeur de args: |%s|\n", buff.cmds->args[y]);
                y++;
            }
            y = 0;
        }
        printf("valeur de fd_in: %d\nValeur de fd_out: %d\n", buff.cmds->fd_in, buff.cmds->fd_out);
        printf("------------------------------------\n");
        buff.cmds = buff.cmds->next;
    }

}