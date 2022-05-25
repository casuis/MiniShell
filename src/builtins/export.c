/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:32:46 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:32:50 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

static char	*set_env_key(char *arg, int *mod)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = 0;
	while (arg[size] && arg[size] != '=' && arg[size] != ' ')
		size++;
	if (arg[size] == ' ')
	{
		ft_error("minishell", "not a valid identifier\n", 1);
		return (NULL);
	}
	else if (arg[size] != '=')
		*mod = 1;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (i < size)
	{
		ret[i] = arg[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*set_env_value(char *arg)
{
	int		i;
	int		size;
	char	*ret;
	char	*tmp;

	i = 0;
	size = 0;
	tmp = arg;
	while (*tmp && *tmp != '=')
		tmp++;
	if (*tmp == '=')
		tmp++;
	while (tmp[size])
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (i < size)
	{
		ret[i] = tmp[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	create_new_key(char *key, char *value, int	mod)
{
	t_env		*buff;
	t_env		*new;

	buff = shell.env;
	while (buff->next != NULL)
		buff = buff->next;
	new = malloc(sizeof(t_env));
	if (new == NULL)
		exit(EXIT_FAILURE);
	buff->next = new;
	new->next = NULL;
	new->key = key;
	new->value = value;
	new->no_value = mod;
}

static void	print_all_export(t_cmd *cmds)
{
	t_env	*buff;

	buff = shell.env;
	while (buff != NULL)
	{
		write(cmds->fd_out, "export ", 7);
		write(cmds->fd_out, buff->key, ft_strlen(buff->key));
		if (buff->no_value != 1)
			write(cmds->fd_out, "=", 1);
		if (buff->value != NULL)
		{
			write(cmds->fd_out, "\"", 1);
			write(cmds->fd_out, buff->value, ft_strlen(buff->value));
			write(cmds->fd_out, "\"", 1);
		}
		write(cmds->fd_out, "\n", 1);
		buff = buff->next;
	}
}
 // rajouter condition pour les chars en dehors des alpha num

void	built_export(t_cmd *cmds)
{
	t_env	*buff;
	char	*key;
	char	*value;
	int		mod;

	mod = 0;
	buff = shell.env;
	if (buff == NULL)
		return ;
	if (cmds->args[1] == NULL)
		return (print_all_export(cmds));
	key = set_env_key(cmds->args[1], &mod);
	value = set_env_value(cmds->args[1]);
	if (!ft_strcmp(key, "_") && !ft_isalphanum(key))
	{
		ft_error("minishell", "not a valid identifier\n", 1);
		return ;
	}
	while (buff != NULL && !ft_strcmp(buff->key, key))
		buff = buff->next;
	if (buff == NULL)
		return (create_new_key(key, value, mod));
	free(buff->value);
	free(key);
	buff->value = value;
}