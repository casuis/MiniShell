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

// int	parse_in_file(char *str, int pos, t_cmd *cmd)
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

// void	deffine_cmd_sep(char *str, int pos, t_cmd *cmd)
// {
// 	int		i;

// 	i = 0;
// 	if (str == NULL)
// 		return ;
// 	while (str[i] && i < pos && shell.error == 0)
// 	{
// 		while (str[i] && str[i] == ' ' && i < pos)
// 			i++;
// 		if (str[i] == '<')
// 			i = parse_in_file(&str[i], (pos - i), cmd);
// 		else if (str[i] == '>')
// 			i = parse_out_file(&str[i], (pos - i), cmd);
// 		if (str[i] != '\0')
// 			i++;
// 	}
// }

int	*parting(char *str)
{
	int		i;
	int		balise;
	t_cmd	*cmd;
	char	**taken;

	i = 0;
	balise = 0;
	cmd = NULL;
	taken = malloc(sizeof(char *) * 3);
	taken[2] = NULL;
	while (str[i] && shell.error == 0)
	{
		balise = get_next_pipe(&str[i]);
		if (shell.error == 1)
			break ;
		cmd = ft_add_list(cmd);
		// defini les fds
		deffine_cmd_sep(str, balise, cmd);
		// set cmd / arg
		while (i < balise)
		{
			shell.nb_cmd += create_cmd(taken[1]);
			taken = ft_set_taken(str, &i, taken, balise);
			create_args(taken[0], str, &i, balise);
		}
		//
	}
	return (shell.error);
}

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
