/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:33:55 by asimon            #+#    #+#             */
/*   Updated: 2022/05/22 03:11:32 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_EXEC
# define MINISHELL_EXEC
# include "../../includes/minishell.h"

int		is_builtin(char	*cmd);
void	ft_core_exec();
char	**get_env_tab();
void	ft_pipe(int fd, char **env, char *cmd);
char	*set_cmd_path(t_cmd *cmd, char **path);
#endif