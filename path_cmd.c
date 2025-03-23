#include "pipex.h"

int	open_files(char *av)
{
	int f;

	f = open(av, O_RDONLY);
	
	if (f < 0)
	{
		perror("invalid Fd");
		exit(1);
	}
	return (f);
}

char **split_path(char *av)
{
	char **p;
	int i = 0;

	while (av[i] != '/')
		i++;
	
	p = ft_split(&av[i], ':');
	return (p);
}


char	**wich_path(char **env)
{
	int t = 0;
	char **mypath = NULL;


	while (env[t])
	{
		if (ft_strnstr(env[t], "PATH", 5))
		{
			mypath = split_path(env[t]);
			break ;
		}
		t++;
	}
	return (mypath);
}
char	*valid_path(char **env, char *cmd)
{
	char **p;
	char *g;
	int i;
	p = wich_path(env);
	i = 0;

	while (p[i])
	{
		g = ft_strjoin(p[i], cmd);
		if (access(g, F_OK & X_OK) == 0)
			return (frtwo(p), g);
		free(g);
		i++;
	}	
	frtwo(p);
	return (NULL);
}
