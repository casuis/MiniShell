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


int	quote_closed(char c, int *bol)
{
	if (c == '\'' && *bol == 3)
		*bol = 1;
	else if (c == '\'' && *bol == 1)
		*bol = 3;
	else if (c == '"' && *bol == 3)
		*bol = 2;
	else if (c == '"' && *bol == 2)
		*bol = 3;
	return (1);
}

// Retour de la length de la variable d'env (value de key)
int	count_envl(int bol, int *count)
{
	int		ret;
	t_env	*buff;

	ret = 0;
	buff = shell.env;
	while (ft_comp(buff->key, )
	{
		buff = buff->next;
	}
	return (1);
}

int	get_size_arg(char *str)
{
	int		ret;
	int		bol;
	int		i;

	ret = 0;
	i = 0;
	bol = 3;
	while (str[i] && str[i] != ' ' && str[i] != '|')
	{
		if (str[i] == '\'' || str[i] == '"')
			i += quote_closed(str[i], &bol);
		else if (str[i] == '$' && bol != 1)
		// Attends la lenght de la variable d'env
			i += count_envl(&ret, &str[i]);
		else if (str[i] != '\'' && str[i] != '"')
		{
			i++;
			ret++;
		}
	}
	return (ret);
}


int	get_env_arg(char *str, char *new)
{
	int		ret;
	t_shell	buff;
	char	*cmp;
	int		i;

	ret = 1;
	i = 0;
	buff = shell;
	while (str[ret] && str[ret] != '\'' 
		&& str[ret] != '"' && str[ret] != ' ')
		ret++;
	cmp = malloc(sizeof(char))
	while (i < ret)
	{
		cmp[]
	}
}

char	*get_arg(char *str)
{
	int		ig[2];
	int		size;
	char	*ret;

	ig[0] = 0;
	ig[1] = 0;
	size = get_size_arg(str);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (ig[0] < size && str[ig[0] + ig[1]])
	{
		if (str[ig[0] + ig[1]] == '\'' || str[ig[0] + ig[1]] == '"')
			ig[1]++;
		else if (str[ig[0] + ig[1]] == '$')
		// Assignation de la variable d'env dans le ret - Devrai avoir une seule fctn pour sortir les va_env
			ig[1] += get_env_arg(&str[ig[0] + ig[1]], &ret[ig[0]]); 
		else
		{
			ret[ig[0]] = str[ig[0] + ig[1]];
			ig[0]++;
		}
	}
	ret[ig[0]] = '\0';
	return (ret);
}

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

// int	define_fd(char *str, char c)
// {
// 	int		i;
// 	int		fd;
// 	t_shell	buff;

// 	i = 0;
// 	buff = shell;
// 	else
// 	{
// 		fd = set_fd_in(str);
// 		if (c == '<')
// 		{
// 		}
// 	}
// }

int	parse_in_file(char *str, int pos)
{
	int			i;
	t_shell		buff;
	char		*cmd_buff;
	int			y;

	i = 0;
	y = 0;
	buff = shell;
	if (str[i + 1] == '>')
		ft_error("minishell", "operator '<>' does not have to be recreated\n");
	else if (str[i + 1] == '<')
		parse_herdoc();
	else
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '\0')
			ft_error("minishell", "syntax error near unexpected token 'newline'\n");
		else if (str[i] == '|')
			ft_error("minishell", "syntax error near unexpected token '|'\n");
		buff->cmds.fd_in = set_fd_in(&str[i]);
	}
}

void	deffine_cmd_sep(char *str, int pos)
{
	int		i;
	t_shell	buff;

	i = 0;
	buff = shell;
	if (str == NULL)
		return ;
	while (str[i] && i < pos && buff.error == 0)
	{
		while (str[i] && str[i] == ' ' && i < pos)
			i++;
		if (str[i] == '<')
			i = parse_in_file(&str[i], (pos - i));
		else if (str[i] == '>')
			i = parse_out_file(&str[i], (pos - i));
		else if (str[i] == '$')
			i = parse_var_env(&str[i], (pos - i));
		else if (str[i] == '\'' || str[i] == '"')
			i = parse_quotes(&str[i], (pos - i));
		else if (str[i] != ' ' && str[i] != '\0')
			i = create_cmd_arg(&str[i],(pos - i));
		if (str[i] != '\0')
			i++;
	}
}

t_cmd	*parting(char *str)
{
	int		i;
	int		balise;
	t_shell	buff;

	i = 0;
	balise = 1;
	buff = shell;
	buff.error = 0;
	while (balise > 0 && str[i] && buff.error == 0)
	{
		balise = get_next_pipe(&str[i]);
		write(1, &str[i], balise) ;
		i += balise;
		if (str[i] != '\0')
			i++;
		//printf("%s", &str[i]);
		// if (balise != -1)
		// 	deffine_cmd_sep(&str[i], balise);
		// else
		// 	ft_error("Error: unclosed quote\n");
	}
	return (NULL);
}

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
