# include "../includes/minishell.h"

void    free_env(void)
{
	t_env		*env;
	t_env		*tmp;

	env = shell.env;
	tmp = env->next;
	free(env->key);
	free(env->value);
	free(env);
	while (tmp != NULL)
	{
		env = tmp;
		tmp = env->next;        
		free(env->key);
		free(env->value);
		free(env);
	}
}

void	built_exit(t_cmd *cmds)
{
	int		i;
	int		mod;

	i = 0;
	mod = 0;
	if (cmds->args[1] != NULL)
	{
		while (cmds->args[1][i])
			if (!ft_isdigit(cmds->args[1][i++]))
				ft_error("minishell", "numeric argument required\n", 2);
		if (cmds->args[1][i] == '\0')
		{
			shell.last_return = ft_atoi(cmds->args[1]);
			mod = 1;
		}
	}
	if (cmds->args[1] != NULL && cmds->args[2] != NULL)
		ft_error("minishell", "too many arguments", 2);
	free_gb_col();
	free_env();
	if (mod == 0)
		shell.last_return = 0;
	exit(EXIT_SUCCESS);
}
