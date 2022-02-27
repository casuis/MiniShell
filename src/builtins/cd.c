#include "../../includes/minishell.h"

char	*ft_create(size_t nb, size_t size)
{
	char	*str;

	str = malloc(size * (nb + 1));
	return (str);
}

char	*ft_pwd()
{
	char	*path;
	size_t	len = 1;

	path = ft_create(len, sizeof(char));
	if (path == NULL)
		return (NULL) ;
	path = getcwd(path, len);
	while (path == NULL)
	{
		free(path);
	  	path = getcwd(path, ++len);
	}
	return (path);
}

char	*ft_cd(const char *path)
{
	char	*pwd;

	chdir(path);
	pwd = ft_pwd();
	return (pwd);
}

int		main(int argc, const char **argv)
{
	char	*pwd;

	(void)argc;
	pwd = ft_cd(argv[1]);
	printf("%s \n", pwd);
	return (0);
}