#include "../includes/minishell.h"

void	built_cd(t_cmd *cmds)
{
	t_env		*buff;
	t_env		*tmp;

	buff = shell.env;
	tmp = shell.env;
	if (cmds->args[1] == NULL || cmds->args[2] != NULL)
	{
		ft_error("minishell", " cd: Wrong number of argument", 1);
		return ;
	}
	while (ft_strcmp(tmp->key, "OLDPWD"))
		tmp = tmp->next;
	if (chdir(cmds->args[1]))
	{
		while (ft_strcmp(buff->key, "PWD"))
			buff = buff->next;
		free(tmp->value);
		tmp->value = ft_strdup(buff->value);
		free(buff->value);
		buff->value = getcwd(NULL, 0);
		shell.last_return = 0;
	}
	else
		shell.last_return = 1;
}
