/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:48:57 by arthur            #+#    #+#             */
/*   Updated: 2021/12/16 15:53:05 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

size_t	ft_ispath(char *str)
{
	int		i;
	char	*comp;

	i = 0;
	comp = "PATH";
	while (str[i] && comp[i])
	{
		if (str[i] != comp[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_set_path(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_ispath(str[i]))
			return (ft_strcpy(str[i], 0));
		i++;
	}
	return (NULL);
}

char	*ft_send_path(char *path, char *cmd)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (path)
	{
		ret = (char *)malloc(sizeof(char)
				* (ft_strlen(path) + ft_strlen(cmd) + 2));
		gb_col_add_list((void *)ret);
		while (path[i])
		{
			ret[i] = path[i];
			i++;
		}
		while (*cmd)
		{
			ret[i] = *cmd;
			i++;
			cmd++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

char	*ft_check_path(char **path, char *cmd)
{
	int		bol;
	char	*ret;
	int		i;

	bol = -1;
	ret = NULL;
	i = 0;
	if (path[i] != NULL)
	{
		while (path[i] != NULL)
		{
			ret = ft_send_path(path[i], cmd);
			printf("acces: %s\n", ret);
			if (access(ret, R_OK | X_OK) == 0)
			{
				printf("acces: %s\n", ret);
				return (ret);
			}
			i++;
		}
	}
	return (ret);
}
