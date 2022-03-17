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

// int	need_to_be_take(char c, int bol)
// {
// 	if (c == '\'' && (bol == 3 || bol == 1))
// 		return (0);
// 	else if (c == '$' && bol == 1)
// 		return (1);
// 	else if (c == '"' && (bol == 3 || bol == 2))
// 		return (0);
// 	else if (c == '$' && (bol == 3 || bol == 2))
// 		return (0);
// 	else
// 		return (1);
// 	return (0);
// }



// int	set_instr_va_env(char *str, char *add)
// {
// 	char	*key;
// 	char	*value;
// 	int		size;
// 	int		i;

// 	i = -1;
// 	size = 1;
// 	key = get_va_env_key(str);
// 	if (key == NULL)
// 		return (0);
// 	value = get_va_env_value(key);
// 	size += ft_strlen(key);
// 	if (value == NULL)
// 	{
// 		free(key);
// 		return (size);
// 	}
// 	while (++i < ft_strlen(value))
// 		add[i] = value[i];
// 	add[i] = '\0';
// 	free(key);
// 	free(value);
// 	return (size);
// }


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

int	parse_in_file(char *str, int pos, t_cmd *cmd)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
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
		cmd->fd_in = set_fd_in(&str[i]);
	}
}

void	*deffine_cmd_sep(char *str, int pos, t_cmd *cmd)
{
	int		i;
	int		bol;

	i = 0;
	bol = 3;
	if (str == NULL)
		return ;
	while (str[i] && i < pos && shell.error == 0)
	{
		while (str[i] && str[i] == ' ' && i < pos)
			i++;
		if (str[i] == '<' && bol == 3)
			i = parse_in_file(&str[i], (pos - i), cmd);
		else if (str[i] == '>' && bol == 3)
			i = parse_out_file(&str[i], (pos - i), cmd);
		else if (str[i] == '\'' || str[i] == '"')
			i += quote_closed(str[i], &bol);
		if (str[i] != '\0')
			i++;
	}
}

int	*parting(char *str)
{
	int		i;
	int		balise;
	char	*work_str;
	t_cmd	*cmd;

	i = 0;
	balise = 0;
	cmd = NULL;
	work_str = NULL;
	while (str[i] && shell.error == 0)
	{
		balise = get_next_pipe(&str[i]);
		if (shell.error == 1)
			break ;

		// creer une nouvelle cmd - DONE
		cmd = ft_add_list(cmd);
		
		// defini les fds - MISSING DEF
		deffine_cmd_sep(str, balise, cmd);

		// set la work str - DONE
		work_str = set_work_str(str, i, balise);
		
		// set les cmd & args
		set_cmd_arg(work_str, cmd);

		// avance i jusqu'au prochain tour
		i = balise;
		if (str[i] != '\0')
			i++;
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
