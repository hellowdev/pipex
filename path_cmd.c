/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:33:56 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/25 01:22:50 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char *av)
{
	char	**p;
	int		i;

	i = 0;
	while (av[i] != '/')
		i++;
	p = ft_split(&av[i], ':');
	if (!p)
		return (NULL);
	return (p);
}

char	**wich_path(char **env)
{
	int		t;
	char	**mypath;

	t = 0;
	mypath = NULL;
	while (env[t])
	{
		if (ft_strnstr(env[t], "PATH", 5))
		{
			mypath = split_path(env[t]);
			if (!mypath)
				return (NULL);
			break ;
		}
		t++;
	}
	return (mypath);
}

char	*valid_path(char **env, char *cmd, char *av)
{
	char	**p;
	char	*path;
	int		i;

	i = 0;
	p = wich_path(env);
	if (!p)
		return (NULL);
	if (access(av, F_OK & X_OK) == 0)
		return (frtwo(p), ft_strdup(av));
	while (p[i])
	{
		path = ft_strjoin(p[i], cmd);
		if (!path)
			return (frtwo(p), NULL);
		if (access(path, F_OK & X_OK) == 0)
			return (frtwo(p), path);
		free(path);
		i++;
	}
	frtwo(p);
	return (NULL);
}
