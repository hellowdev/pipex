/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:33:56 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/24 15:35:42 by ychedmi          ###   ########.fr       */
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

char	*valid_path(char **env, char *cmd)
{
	char	**p;
	char	*g;
	int		i;

	i = 0;
	p = wich_path(env);
	if (!p)
		return (NULL);
	while (p[i])
	{
		g = ft_strjoin(p[i], cmd);
		if (!g)
			return (frtwo(p), NULL);
		if (access(g, F_OK & X_OK) == 0)
			return (frtwo(p), g);
		free(g);
		i++;
	}
	frtwo(p);
	return (NULL);
}
