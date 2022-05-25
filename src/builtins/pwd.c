/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:32:52 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:48:32 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void	built_pwd(t_cmd *cmds)
{
	char *str;
	str = getcwd(NULL, 0);
	write(cmds->fd_out, str, ft_strlen(str));
	write(cmds->fd_out, "\n", 1);
	free (str);
}
