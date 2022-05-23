/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:46:20 by asimon            #+#    #+#             */
/*   Updated: 2022/05/23 05:53:41 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

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
	ft_error("minishell", "syntax error\n", 2);
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
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

int	ft_error(char *prog, char *msg, int nb)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	shell.error = 1;
	shell.last_return = nb;
	return (-1);
}

char	*ft_create(int size)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
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
