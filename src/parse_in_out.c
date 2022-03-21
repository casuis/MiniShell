/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:54:06 by asimon            #+#    #+#             */
/*   Updated: 2022/03/21 21:54:07 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	set_fd_in(char *str)
{
	int		ret;
	char	*file;

	file = get_arg(str);
	ret = open(file, O_RDONLY);
	if (ret < 0)
		perror(file);
	free(file);
	return (ret);
}

// PB - DOIT PRENDRE LES NOMS DE FICHIERS COMME TT AUTRES ARGS
int	parse_in_file(char *str, int pos, t_cmd *cmd)
{
	int			i;

	i = 0;
	if (str[i + 1] == '>')
		ft_error("minishell", "operator '<>' does not have to be recreated\n");
	else if (str[i + 1] == '<')
		parse_herdoc();
	else
	{
		while (str[i] && str[i] == ' ' && i < pos)
			i++;
		if (str[i] == '\0')
			ft_error("minishell", "syntax error near unexpected token 'newline'\n");
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			ft_error("minishell", "syntax error near unexpected token\n");
		cmd->fd_in = set_fd_in(&str[i]);
	}
}

int	parse_out_file(char *str, int pos, t_cmd *cmd)
{
	int		i;
	int		mod;

	i = 0;
	mod = 0;
	if (str[i + 1] == '<')
		ft_error("minishell", "syntax error\n");
	else if (str[i + 1] == '>')
		mod = 1;
	while (str[i] && str[i] != ' ' && i < pos)
		i++;
	if (str[i] == '<' || str[i] == '>' || str[i] == '\0')
		ft_error("minishell", "syntax syntax error near unexpected token\n");
	set_fd_out(mod, &str[i]);

}