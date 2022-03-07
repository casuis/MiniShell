/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:53:04 by asimon            #+#    #+#             */
/*   Updated: 2022/02/27 14:53:06 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_size_arg(char *str)
{
	int		ret;
	int		bol;
	int		i;

	ret = 0;
	i = 0;
	bol = 3;
	while (str[ret + i])
	{
		if (str[ret + i] == '\'' && bol == 3)
			bol = 1;
		else if (str[ret + i] == '\'' && bol == 1)
			bol = 3;
		else if (str[ret + i] == '"' && bol == 3)
			bol = 2;
		else if (str[ret + i] == '"' && bol == 2)
			bol = 3;
		else if (str[ret + i] == ' ' && bol == 3)
			return (ret);
		if (str[ret + i] != '\'' && str[ret + i] != '"' && str[ret + i])
			ret++;
		else
			i++;
	}
	return (ret);
}

char	*get_arg(char *str)
{
	int		quote[2];
	int		size;
	char	*ret;

	quote[0] = 0;
	quote[1] = 0;
	size = get_size_arg(str);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (quote[0] < size && str[quote[0] + quote[1]])
	{
		if (str[quote[0] + quote[1]] == '\'' || str[quote[0] + quote[1]] == '"')
			quote[1]++;
		else
		{
			ret[quote[0]] = str[quote[0] + quote[1]];
			quote[0]++;
		}
	}
	ret[quote[0]] = '\0';
	return (ret);
}

int	set_fd_in(char *str)
{
	int		ret;
	char	*file;

	file = get_arg(str);
	ret = open(file, O_RDONLY);
	free(file);
	if (ret < 0)
		perror("open:");
	fd = dup2(, fd)
	return (ret);
}

// int	define_fd(char *str, char c)
// {
// 	int		i;
// 	int		fd;
// 	t_shell	buff;

// 	i = 0;
// 	buff = shell;
// 	if (str[i] == '\0')
// 		ft_error("minishell", "syntax error near unexpected token 'newline'\n");
// 	else if (str[i] == '|')
// 		ft_error("minishell", "syntax error near unexpected token '|'\n");
// 	else
// 	{
// 		fd = set_fd_in(str);
// 		if (c == '<')
// 		{
// 		}
// 	}
// }

// int	parse_in_file(char *str, int pos)
// {
// 	int			i;
// 	t_shell		buff;
// 	char		*cmd_buff;
// 	int			y;

// 	i = 0;
// 	y = 0;
// 	buff = shell;
// 	if (str[i + 1] == '>')
// 		ft_error("minishell", "operator '<>' does not have to be recreated\n");
// 	else if (str[i + 1] == '<')
// 		parse_herdoc();
// 	else
// 	{
// 		while (str[i] && str[i] == ' ')
// 			i++;
// 		define_fd(&str[i], '<');
// 	}
// }

// void	deffine_cmd_sep(char *str, int pos)
// {
// 	int		i;
// 	t_shell	buff;

// 	i = 0;
// 	buff = shell;
// 	if (str == NULL)
// 		return ;
// 	while (str[i] && i < pos && buff.error == 0)
// 	{
// 		while (str[i] && str[i] == ' ' && i < pos)
// 			i++;
// 		if (str[i] == '<')
// 			i = parse_in_file(&str[i], (pos - i));
// 		else if (str[i] == '>')
// 			i = parse_out_file(&str[i], (pos - i));
// 		else if (str[i] == '$')
// 			i = parse_var_env(&str[i], (pos - i));
// 		else if (str[i] == '\'' || str[i] == '"')
// 			i = parse_quotes(&str[i], (pos - i));
// 		else if (str[i] != ' ' && str[i] != '\0')
// 			i = create_cmd_arg(&str[i],(pos - i));
// 		if (str[i] != '\0')
// 			i++;
// 	}
// }

// t_cmd	*parting(char *str)
// {
// 	int		i;
// 	int		balise;
// 	t_shell	buff;

// 	i = 0;
// 	balise = 1;
// 	buff = shell;
// 	buff.error = 0;
// 	while (balise > 0 && str[i] && buff.error == 0)
// 	{
// 		balise = get_next_pipe(&str[i]);
// 		write(1, &str[i], balise) ;
// 		i += balise;
// 		if (str[i] != '\0')
// 			i++;
// 		//printf("%s", &str[i]);
// 		// if (balise != -1)
// 		// 	deffine_cmd_sep(&str[i], balise);
// 		// else
// 		// 	ft_error("Error: unclosed quote\n");
// 	}
// 	return (NULL);
// }

int		main(int argc, char **argv)
{
	char 	*str;
	int		size = 0;
	int		fd = 0;

	str = "l\"is\"t.\'c\' t";
	fd = set_fd_in(str);
	printf("fd: %d\n", fd);
	return (0);
}
