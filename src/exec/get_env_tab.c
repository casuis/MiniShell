/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:46:58 by asimon            #+#    #+#             */
/*   Updated: 2022/04/05 12:46:59 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_exec.h"

void	ft_putstr_in(char *ret, char *s1)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		*ret = s1[i];
		i++;
		ret++;
	}
	*ret = '\0';
}

char	*ft_strjoinc(char *s1, char *s2, char c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (s1)
		ft_putstr_in(ret, s1);
	if (c)
	{
		i = ft_strlen(ret);
		ret[i] = c;
		i++;
	}
	if (s2)
		ft_putstr_in(&ret[i], s2);
	i = ft_strlen(ret);
	return (ret);
}

char	**get_env_tab()
{
	t_env	buff;
	char	**ret;
	int		i;

	i = 0;
	buff = shell.env;
	while (buff->next != NULL)
	{
		i++;
		buff = buff->next;
	}
	ret = malloc(sizeof(char *) * (i + 1);
	buff = shell.env;
	i = 0;
	while (buff != NULL)
	{
		ret[i] = ft_strjoinc(buff->key, buff->value, '=');
		i++;
		buff = buff->next;
	}
}