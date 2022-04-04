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

int	uncorrect_name(char *file)
{
	if (access(file, F_OK))
		return (1);
	return (0);
}

char	*set_file_name(int count)
{
	char	*str;
	char	*ret;
	int		size;
	int		buff;

	buff = count;
	str = "herdocfile_";
	size = ft_strlen(str);
	while (buff / 10 > 0)
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	return (ret);
}

int	create_herdoc_fd(t_cmd *cmd)
{
	int		ret;
	char	*file;
	int		i;

	i = 1;
	file = set_file_name(i); 
	while (uncorrect_name(file) && i < 2147483647)
		file = find_correct_name(file, ++i);
	if (i == 2147483647)
		ft_error("minishell", "herdoc error, impossible to create\n");
	if (shell.error == 0)
		ret = open(file, O_CREAT);
	else
		return (-1);
	cmd->herdoc_file = ret;
	return (ret);
}