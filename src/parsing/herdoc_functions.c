/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:16:50 by asimon            #+#    #+#             */
/*   Updated: 2022/04/04 02:16:51 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

char	*find_correct_name(char *file, int count)
{
	char	*buff;
	char	*str;
	char	*ret;

	str = "herdocfile_";
	buff = ft_itoa(count);
	ret = ft_strjoin(str, buff);
	free(file);
	free(buff);
	return (ret);
}

int	create_herdoc_fd(t_cmd *cmd)
{
	int		ret;
	char	*file;
	int		i;

	i = 1;
	file = ft_strdup("");
	file = find_correct_name(file, i); 
	while (access(file, F_OK) != -1 && i < 2147483647)
		file = find_correct_name(file, ++i);
	if (i == 2147483647)
		ft_error("minishell", "herdoc error, impossible to create\n");
	if (shell.error == 0)
		ret = open(file, O_CREAT | O_WRONLY, 0777);
	else
		return (-1);
	cmd->herdoc_file = file;
	return (ret);
}

char	*reajust_prompt(char *str, t_cmd *cmd)
{
	char	*ret;
	char	*buff_ret;

	ret = NULL;
	if (cmd->herdoc_extend == 1)
	{
		ret = ft_strjoin(str, "\n");
		free(str);
		return (ret);
	}
	while (*str != '\0')
	{
		if (*str == '$')
		{
			str++;
			ret = ft_add_var_env(ret, &str);
		}
		else
			ret = ft_add_char(ret, &str);
	}	
	buff_ret = ret;
	ret = ft_strjoin(ret, "\n");
	free(buff_ret);
	return (ret);
}

int	parse_herdoc(char **str, t_cmd *cmd)
{
	int 	fd;
	char	*del;
	char	*prompt;

	fd = create_herdoc_fd(cmd);
	*str += 1;
	while (**str == ' ' && **str)
		*str += 1;
	if (**str == '\0')
		return (ft_error("minishell", "herdoc need a delimiter\n"));
	del = set_herdoc_del(cmd, str);
	if (del != NULL)
	prompt = readline("> ");
	while (ft_strcmp(prompt, del) != 1 && prompt != NULL)
	{
		prompt = reajust_prompt(prompt, cmd); 
		ft_putstr_fd(prompt, fd);
		printf("valeur du prompt: |%s|\nValeur de fd: |%d|\n", prompt, fd);
		free(prompt);
		prompt = readline("> ");
	}
	return (fd);
}