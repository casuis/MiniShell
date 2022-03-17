/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:46:20 by asimon            #+#    #+#             */
/*   Updated: 2022/03/02 16:46:27 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


char	*ft_strncpy(char *str, int nb)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (nb + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i] && i < nb)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	get_next_pipe(char *str)
{
	int		i;
	int		bol;

	i = 0;
	bol = 3;
	while (str[i])
	{
		if (str[i] == '"' && bol > 2)
			bol = 1;
		else if (str[i] == '\'' && bol > 2)
			bol = 2;
		else if (str[i] == '"' && bol == 1)
			bol = 3;
		else if (str[i] == '\'' && bol == 2)
			bol = 3;
		else if (bol > 2 && str[i] == '|')
			break ;
		i++;
	}
	if ((bol == 3 && (str[i] == '\0' || str[i + 1] != '|')))
		return (i);
	ft_error("minishell", "syntax error unclosed quotes\n");
	shell.error = 1;
	return (-1);
}

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (*s1 && *s2)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
	}
	return (0);
}

void	ft_error(char *prog, char *msg)
{
	t_shell		buff;

	buff = shell;
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	buff.error = 1;
}

char	*ft_create(int size)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	return (ret);
}

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