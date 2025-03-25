/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:07:01 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/25 01:20:03 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_seccmd(char *awk)
{
	int		i;
	char	*secawk;

	i = 0;
	while (awk[i])
	{
		if (awk[i] == 39)
		{
			secawk = ft_substr(awk, i + 1, rev_len(awk) - i - 1);
			if (!secawk)
				return (NULL);
			return (secawk);
		}
		i++;
	}
	return (NULL);
}

char	**awk_split(char *awk)
{
	int		i;
	char	**firstcmd;
	char	**splited;
	char	*firstawk;
	char	*secawk;

	i = 0;
	secawk = NULL;
	splited = NULL;
	firstcmd = NULL;
	secawk = check_seccmd(awk);
	if (!secawk && rev_len(awk) > 0)
		return (NULL);
	while (awk[i] && awk[i] != 39)
		i++;
	firstawk = ft_substr(awk, 0, i);
	if (!firstawk)
		return (free(secawk), NULL);
	firstcmd = ft_split(firstawk, 32);
	if (!firstcmd)
		return (frone(firstawk, secawk), NULL);
	splited = param_join(firstcmd, secawk);
	if (!splited)
		return (frone(firstawk, secawk), frtwo(firstcmd), NULL);
	return (frone(firstawk, secawk), frtwo(firstcmd), splited);
}

char	**param_join(char **firstcmd, char *seccmd)
{
	int		i;
	char	**p;

	i = 0;
	while (firstcmd[i])
		i++;
	(seccmd) && (i++);
	p = malloc((i + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = -1;
	while (firstcmd[++i])
	{
		p[i] = ft_strdup(firstcmd[i]);
		if (!p[i])
			return (frtwo(p), NULL);
	}
	if (seccmd)
	{
		p[i] = ft_strdup(seccmd);
		if (!p[i++])
			return (frtwo(p), NULL);
	}
	p[i] = NULL;
	return (p);
}

void	first_child(int *pipefd, char **av, char **envp)
{
	char	**cmd;
	char	*path;
	int		infile;

	cmd = awk_split(av[2]);
	if (!cmd)
		close_fd(pipefd);
	path = valid_path(envp, cmd[0], av[2]);
	if (!path)
		fcmd_not_found(cmd[0], cmd, pipefd);
	infile = in_file(av[1], pipefd);
	dup2(infile, 0);
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(infile);
	close(pipefd[1]);
	execve(path, cmd, envp);
	frtwo(cmd);
	free(path);
	exit(1);
}

void	seconde_child(int *pipefd, char **av, char **envp)
{
	char	**cmd;
	char	*path;
	int		outfile;

	cmd = awk_split(av[3]);
	if (!cmd)
		close_fd(pipefd);
	path = valid_path(envp, cmd[0], av[3]);
	if (!path)
		scmd_not_found(cmd[0], cmd, pipefd);
	outfile = out_file(av[4], pipefd);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(outfile, 1);
	close(outfile);
	execve(path, cmd, envp);
	frtwo(cmd);
	free(path);
	exit(1);
}
