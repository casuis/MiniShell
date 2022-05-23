# include "../includes/minishell.h"

void	built_pwd(t_cmd *cmds)
{
	char *str;
	str = getcwd(NULL, 0);
	write(cmds->fd_out, str, ft_strlen(str));
	free (str);
}
