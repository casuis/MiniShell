/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:33:55 by asimon            #+#    #+#             */
/*   Updated: 2022/03/30 00:33:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_EXEC
# define MINISHELL_EXEC
# include "../../includes/minishell.h"

int		is_builtin(char	*cmd);
#endif