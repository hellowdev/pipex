/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:07:01 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/23 17:51:30 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	rev_len(char *s)
{
	int i;
	i = ft_strlen(s) - 1;

	while (s[i] && 0 < i)
	{
		if (s[i] == 39)
		{
			break ;
		}
		i--;
	}
	
	return (i);
}
char	**awk_split(char *awk)
{
    int i;
	char **firstcmd;
	char **splited;
	char *get;
	char *secawk;

	secawk = NULL;
	splited = NULL;
	firstcmd = NULL;
    i = 0;
    while (awk[i])
    {
		if (awk[i] == 39)
		{
			secawk = ft_substr(awk, i + 1, rev_len(awk) - i - 1);
			break ;
		}
		i++;
    }
	get = ft_substr(awk, 0, i);
	firstcmd = ft_split(get, 32);
	splited = param_join(firstcmd, secawk);
	free(get);
	free(firstcmd);
	return (splited);
}

char	**param_join(char **firstcmd, char *seccmd)
{
	int i;
	int j;
	i = 0;
	j = 0;
	char **p; 
	while (firstcmd[i])
		i++;
	if (seccmd)
		p = malloc((i + 2) * sizeof(char *));
	else
		p = malloc((i + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = firstcmd[j];
		j++;
	}
	if (seccmd)
		p[j++] = seccmd;
	p[j] = NULL;
	return (p);
}

void	first_child(int *pipefd, char **av, char **envp)
{
	char **cmd;
	char *path;
	int infile;
    cmd = awk_split(av[2]);
	path = valid_path(envp, cmd[0]);
	infile = open_files(av[1]);
	
	// int k = 0;
	// while (cmd[k])
	// {
	// 	printf("first child cmd > [%s]\n", cmd[k]);
	// 	k++;
	// }
	// system("leaks -q pipex");
	dup2(infile, 0);
	close(pipefd[0]);
	close(infile);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	execve(path, cmd, NULL);
	frtwo(cmd);
	exit(1);
}

void	seconde_child(int *pipefd, char **av, char **envp)
{	
	char **cmd;
	char *path;
	int outfile;
	cmd = awk_split(av[3]);
	path = valid_path(envp, cmd[0]);
	outfile = open(av[4], O_CREAT|O_WRONLY|O_TRUNC, 0644);
	// int k = 0;
	// while (cmd[k])
	// {
	// 	printf("sec child cmd > [%s]\n", cmd[k]);
	// 	k++;
	// }
	
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(outfile, 1);
	close(outfile);
	execve(path, cmd, NULL);
	frtwo(cmd);
	exit(1);
}
