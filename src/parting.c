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

int	need_to_be_take(char c, int bol)
{
	if (c == '\'' && (bol == 3 || bol == 1))
		return (0);
	else if (c == '$' && bol == 1)
		return (1);
	else if (c == '"' && (bol == 3 || bol == 2))
		return (0);
	else if (c == '$' && (bol == 3 || bol == 2))
		return (0);
	else
		return (1);
	return (0);
}

char	*get_va_env_value(char *str)
{
	t_env		*buff;

	buff = shell.env;
	while (buff != NULL)
	{
		if (ft_strcmp(str, buff->key) == 1)
			return (ft_strncpy(buff->value, ft_strlen(buff->value)));
		buff = buff->next;
	}
	return (NULL);
}

char	*get_va_env_key(char *str)
{
	char	*cmp;
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\''
		&& str[i] != '"' && str[i] != '|')
		i++;
	printf("1-i: %d\n", i);
	ret = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (str[i] == '$')
		str++;
	while (str[i] && str[i] != ' ' && str[i] != '\''
		&& str[i] != '"' && str[i] != '|')
	{
		ret[i] = str[i]; 
		i++;
	}
	printf("2-i: %d\n", i);
	ret[i] = '\0';
	return (ret);
}

int	count_va_envl(int *count, char *str)
{
	char	*key;
	char	*value;
	int		ret;
	int		i;

	i = -1;
	ret = 1;
	key = get_va_env_key(str);
	if (key == NULL)
		return (0);
	ret += ft_strlen(key);
	value = get_va_env_value(key);
	if (value == NULL)
	{
		free(key);
		return (ret);
	}
	*count += ft_strlen(value);
	free(key);
	free(value);
	return (ret);
}

int	set_instr_va_env(char *str, char *add)
{
	char	*key;
	char	*value;
	int		size;
	int		i;

	i = -1;
	size = 1;
	key = get_va_env_key(str);
	if (key == NULL)
		return (0);
	value = get_va_env_value(key);
	size += ft_strlen(key);
	if (value == NULL)
	{
		free(key);
		return (size);
	}
	while (++i < ft_strlen(value))
		add[i] = value[i];
	add[i] = '\0';
	free(key);
	free(value);
	return (size);
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
		if (str[i] == '\'' && bol == 1 || str[i] == '\'' && bol == 3)
			i += quote_closed(str[i], &bol);
		else if (str[i] == '"' && bol == 2 || str[i] == '"' && bol == 3)
			i += quote_closed(str[i], &bol);
		else if (str[i] == '$' && bol != 1)
			i += count_va_envl(&ret, &str[i]);
		else
		{
			i++;
			ret++;
		}
	}
	return (ret);
}

// Doit etre revu pour prendre les '"' et '\'' quand dans des quotes
char	*get_arg(char *str)
{
	int		in[2];
	int		size;
	char	*ret;
	int		bol;

	in[0] = 0;
	in[1] = 0;
	bol = 3;
	size = get_size_arg(str);
	if (size == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (in[1] < size && str[in[0]])
	{
		if (need_to_be_take(str[in[0]], bol))
		{
			ret[in[1]] = str[in[0]];
			ret[++in[1]] = '\0';
			in[0]++;
		}
		else if (str[in[0]] == '$')
			in[0] += set_instr_va_env(&str[in[0]], &ret[in[1]]);
		else
			in[0] += quote_closed(str[in[0]], &bol);
		in[1] = ft_strlen(ret);
	}
	return (ret);
}

// int	set_fd_in(char *str)
// {
// 	int		ret;
// 	char	*file;

// 	file = get_arg(str);
// 	ret = open(file, O_RDONLY);
// 	if (ret < 0)
// 		perror(file);
// 	free(file);
// 	return (ret);
// }

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

// int	parse_in_file(char *str, int pos)
// {
// 	int			i;
// 	t_cmd		*buff;
// 	char		*cmd_buff;
// 	int			y;

// 	i = 0;
// 	y = 0;
// 	buff = shell.cmds;
// 	if (str[i + 1] == '>')
// 		ft_error("minishell", "operator '<>' does not have to be recreated\n");
// 	else if (str[i + 1] == '<')
// 		parse_herdoc();
// 	else
// 	{
// 		while (str[i] && str[i] == ' ')
// 			i++;
// 		if (str[i] == '\0')
// 			ft_error("minishell", "syntax error near unexpected token 'newline'\n");
// 		else if (str[i] == '|')
// 			ft_error("minishell", "syntax error near unexpected token '|'\n");
// 		buff->fd_in = set_fd_in(&str[i]);
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

int		main(int argc, char **argv, char **penv)
{
	char 	*str;
	char	*str2;
	char	*value;
	char	*key;
	int		size[2];
	
	str = "$test\"'5678'9\"\"";
	value = malloc(sizeof(char) * 100);
	shell.env = set_env(penv);
	value = get_arg(str);
	printf("value: %s\n", value);
	return (0);
}
