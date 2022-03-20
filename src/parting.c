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

// int	parse_in_file(char *str, int pos, t_cmd *cmd)
// {
// 	int			i;
// 	int			y;

// 	i = 0;
// 	y = 0;
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
// 		cmd->fd_in = set_fd_in(&str[i]);
// 	}
// }

// void	deffine_cmd_sep(char *str, int pos, t_cmd *cmd)
// {
// 	int		i;
// 	int		bol;

// 	i = 0;
// 	bol = 3;
// 	if (str == NULL)
// 		return ;
// 	while (str[i] && i < pos && shell.error == 0)
// 	{
// 		while (str[i] && str[i] == ' ' && i < pos)
// 			i++;
// 		if (str[i] == '<' && bol == 3)
// 			i = parse_in_file(&str[i], (pos - i), cmd);
// 		else if (str[i] == '>' && bol == 3)
// 			i = parse_out_file(&str[i], (pos - i), cmd);
// 		else if (str[i] == '\'' || str[i] == '"')
// 			i += quote_closed(str[i], &bol);
// 		if (str[i] != '\0')
// 			i++;
// 	}
// }

void	parting(char *str)
{
	int		y;
	int		balise[2];
	char	*work_str;
	char	*buff;
	t_cmd	*cmd;

	y = 0;
	balise[0] = 0;
	balise[1] = 0;
	cmd = NULL;
	work_str = NULL;
	while (str[balise[0]] && shell.error == 0)
	{
		balise[1] += get_next_pipe(&str[balise[1]]);
		if (shell.error == 1)
			break ;

		// creer une nouvelle cmd - DONE
		cmd = ft_add_list(cmd);
		
		// defini les fds - MISSING DEF
		//deffine_cmd_sep(str, balise, cmd);

		// set la work str - DONE
		work_str = set_work_str(str, balise[0], balise[1]);
		buff = work_str;
		
		// set les cmd & args
		// set_cmd_arg(work_str, cmd);

		// Affichage Test
		printf("workstr: |%s|\n", work_str);
		// ---------------------------------------------		
		cmd->cmd = ft_add_var_env(NULL, &work_str, cmd);

		// Affichage test
		printf("valeur de cmd: |%s|\n", cmd->cmd);
		if (cmd->args != NULL)
		{
			while (cmd->args[y] != NULL)
			{
				printf("valeur de args: |%s|\n", cmd->args[y]);
				y++;
			}
			printf("valeur de fd_in: %d\nValeur de fd_out: %d\n", cmd->fd_in, cmd->fd_out);
		}
		// -------------------------------------------------------------------------------
		free(buff);
		// avance i jusqu'au prochain tour
		if (str[balise[1]] != '\0')
			balise[1]++;
		balise[0] = balise[1];
	}
}
