/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:49:34 by asimon            #+#    #+#             */
/*   Updated: 2022/03/17 22:49:35 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


char	*ft_add_single_quote(char *old, char **str)
{
	int			i;
	char		*ret;
	int			size;

	i = 0;
	size = ft_strlen(old) + get_size(*str, '\'');
	ret = set_new_ret(old, size, &i);
	while (**str && **str != '\'')
	{
		ret[i++] = **str;
		*str += 1;
	}
	if (**str == '\'')
		*str += 1;
	ret[i] = '\0';
	return (ret);
}

// need to do when single quote after double
char	*ft_add_double_quote(char *old, char **str)
{
	char		*ret;
	char		*value;
	int			i;

	i = 0;
	ret = set_new_ret(old, ft_strlen(old) + get_ldbl_quote(*str), &i);
	while (**str && **str != '"')
	{
		if (**str == '$')
		{
			*str += 1;
			value = get_va_env(*str);
			while (**str && **str != ' ' && **str != '"')
				*str += 1;
			i += ft_add(value, &ret[i]);
			free(value);
		}
		else
		{
			ret[i++] = **str;
			*str += 1;
		}
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_add_var_env(char *old, char **str, t_cmd *cmd)
{
	char	*ret;
	char	*va_env;
	char	*buff;
	int		i;

	i = 0;
	va_env = get_va_env(*str);
	if (va_env == NULL)
		return (NULL);
	buff = va_env;
	ret = set_new_ret(old, ft_strlen(va_env), &i);
	while (**str && **str != ' ' && **str != '\'' 
		&& **str != '"' && **str != '$')
		*str += 1;
	while (*va_env && *va_env != ' ')
	{
		ret[i] = *va_env;
		va_env++;
		i++;
	}
	ret[i] = '\0';
	if (*va_env == ' ')
		send_new_arg(va_env, cmd);
	free(buff);
	return (ret);
}

