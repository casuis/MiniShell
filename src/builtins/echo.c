# include "../includes/minishell.h"

static void	flag_ok(t_cmd *cmds)
{
	int		y;

	y = 2;
	while (cmds->args[y] != NULL)
	{
		write(cmds->fd_out, cmds->args[y], ft_strlen(cmds->args[y]));
		y++;
		if (cmds->args[y] != NULL)
			write(cmds->fd_out, " ", 1);
	}
}

static void	flag_not_ok(t_cmd *cmds)
{
	int		y;

	y = 1;
	while (cmds->args[y] != NULL)
	{
		write(cmds->fd_out, cmds->args[y], ft_strlen(cmds->args[y]));
		y++;
		if (cmds->args[y] != NULL)
			write(cmds->fd_out, " ", 1);
	}
	write(cmds->fd_out, "\n", 1);
}

static void	set_mod(int *mod, t_cmd *cmds)
{
	int		i;

	i = 1;
	if (cmds->args[1][0] == '-' && cmds->args[1][i] == 'n')
	{
		while (cmds->args[1][i] == 'n')
			i++;
		*mod = 1;
	}
}

void	built_echo(t_cmd *cmds)
{
	int		y;
	int		mod;

	y = 1;
	mod = 0;
	set_mod(&mod, cmds);
	if (mod == 1 && cmds->args[y] != NULL)
		flag_ok(cmds);
	else
		flag_not_ok(cmds);
	shell.last_return = 0;
}
