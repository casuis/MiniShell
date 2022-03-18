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

t_shell		shell;

// char	*ft_add_single_quote(char *old, char **str)
// {
// 	int			i;
// 	char		*ret;
// 	int			size;

// 	i = -1;
// 	size = ft_strlen(old) + get_size(*str, '\'');
// 	ret = set_new_ret(old, size, &i);
// 	while (**str && **str != '\'')
// 	{
// 		ret[++i] = **str;
// 		*str += 1;
// 	}
// 	if (**str == '\'')
// 		*str += 1;
// 	ret[++i] = '\0';
// 	return (ret);
// }

// char	*ft_add_double_quote(char *old, char **str)
// {
// 	char		*ret;
// 	ret = set_new_ret(old, str, &i);
// 	while (**str && **str != '"')
// 	return (ret);
// // }

// Doit faire le tri post recuperation de l'arg (full espace ne compte pas comme  arg)
char	*ft_add_var_env(char *old, char **str)
{
	char	*ret;
	char	*va_env;
	char	*buff;
	int		i;

	i = 0;
	va_env = get_va_env(*str);
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
		send_new_arg()
	free(buff);
	return (ret);
}

// char	*ft_add(char *old, char **str)
// {
// 	char	*ret;

// 	return (ret);
// }

int			main(int argc, char **argv, char **penv)
{
	char	*str;
	char	*new;
	t_env	*env;
	int		i;

	i = 0;
	shell.env = set_env(penv);
	env = shell.env;
	str = malloc(sizeof(char) * 30);
	while (argv[1][i] != 0)
	{
		str[i] = argv[1][i];
		i++;
	}
	str[i] = '\0';
	new = NULL;
	new = ft_add_var_env(new, &str);
	printf("valeur de new: |%s\n", new);
	printf("Valeur de str: |%s", str);
	return (0);
}