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


# include "./includes/minishell.h"

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
        printf("Extend: %d\n", buff.cmds->herdoc_extend);
        printf("Valeur de herdoc_file: |%s|\n", buff.cmds->herdoc_file);
        printf("------------------------------------\n");
        buff.cmds = buff.cmds->next;
    }

}