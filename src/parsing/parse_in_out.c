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

#include "./include/minishell_parsing.h"

int	set_fd_in(char **str)
{
	int		ret;
	char	*file;

	file = get_cmd_fd(str);
	ret = open(file, O_RDONLY);
	if (ret < 0)
	{
		perror(file);
		shell.error = 1;
	}
	free(file);
	return (ret);
}

int	set_fd_out(char **str, int mod)
{
	char	*file;
	int		ret;

	file = get_cmd_fd(str);
	if (mod == 0)
		ret = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	else
		ret = open(file, O_CREAT | O_WRONLY | O_APPEND);
	if (ret < 0)
	{
		perror(file);
		shell.error = 1;
	}
	free(file);
	return (ret);

}

void	parse_in_file(char **str, t_cmd *cmd)
{
	int			i;

	i = 0;
	*str += 1;
	if (**str == '>')
		ft_error("minishell", "operator '<>' does not have to be recreated\n");
	else if (**str == '<')
		cmd->fd_in = parse_herdoc(str, cmd);
	else
	{
		while (**str && **str == ' ')
			*str += 1;
		if (**str == '\0')
			ft_error("minishell", "syntax error near unexpected token 'newline'\n");
		else if (**str == '|' || **str == '<' || **str == '>')
			ft_error("minishell", "syntax error near unexpected token\n");
		cmd->fd_in = set_fd_in(str);
	}
}

void	parse_out_file(char **str, t_cmd *cmd)
{
	int		mod;

	mod = 0;
	*str += 1;
	if (**str == '<')
		ft_error("minishell", "syntax error\n");
	else if (**str == '>')
	{
		mod = 1;
		*str += 1;
	}
	while (**str && **str == ' ' && shell.error == 0)
		*str += 1;
	if (**str == '<' || **str == '>' || **str == '\0')
		ft_error("minishell", "syntax syntax error near unexpected token\n");
	if (shell.error == 0)
		cmd->fd_out = set_fd_out(str, mod);
}

char	*set_in_out_work_str(char *str, int i, int pos)
{
	char	*ret;
	int		y;

	y = 0;
	if (str == NULL)
		return (NULL);
	ret = malloc(sizeof(char) * ((pos - i) + 1));
	while (str[i] && i < pos)
	{
		ret[y] = str[i];
		i++;
		y++;
	}
	ret [i] = '\0';
	return (ret);
}

char	*get_cmd_fd(char **str)
{
		char	*ret;
		char	**buff;

	ret = NULL;
	buff = malloc(sizeof (char *) * 3);
	buff[2] = NULL;
	while (**str && **str != ' ')
	{
		if (**str == '\'')
		{
			*str += 1;
			ret = ft_add_single_quote(ret, str);
		}
		else if (**str == '"')
		{
			*str += 1;
			ret = ft_add_double_quote(ret, str);
			*str += 1;
		}
		else if (**str == '$')
		{
			*str +=1;
			buff[0] = get_va_env(*str);
			buff[1] = ret;
			ret = ft_strjoin(ret, buff[0]);
			free(buff[0]);
			free(buff[1]);
		}
		else
			ret = ft_add_char(ret, str);
	}
	return (ret);
}