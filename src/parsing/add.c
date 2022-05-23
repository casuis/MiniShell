/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:49:34 by asimon            #+#    #+#             */
/*   Updated: 2022/05/23 05:54:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

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

char	*ft_add_var_env(char *old, char **str)
{
	char	*ret;
	char	*va_env;
	int		i;

	i = 0;
	va_env = get_va_env(*str);
	while (**str && **str != ' ' && **str != '\''
		&& **str != '"' && **str != '$')
		*str += 1;
	if (va_env == NULL)
		return (NULL);
	ret = set_new_ret(old, ft_strlen(va_env), &i);
	while (*va_env && *va_env != ' ')
	{
		ret[i] = *va_env;
		va_env++;
		i++;
	}
	ret[i] = '\0';
	if (*va_env == ' ')
		*str = ft_strjoin((char const *)va_env, *str);
	return (ret);
}

char	*ft_add_char(char *ret, char **str)
{
	int		i;

	i = 0;
	ret = set_new_ret(ret, ft_strlen(ret) + 1, &i);
	ret[i] = **str;
	ret[++i] = '\0';
	*str += 1;
	return (ret);
}
