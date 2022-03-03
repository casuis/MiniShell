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
    printf(str);
    while (str != NULL)
    {
        printf(str);
        if (ft_strlen(str) > 0)
            add_history(str);
        // parting();
        str = readline("minishell$ ");
    }
    return (str);
}

int     main(int argc, char **argv, char **penv)
{
    char *str;
    prompt();
    return (0);
}
