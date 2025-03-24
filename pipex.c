/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:20:33 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/24 15:26:29 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	rev_len(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (s[i] && 0 < i)
	{
		if (s[i] == 39)
			break ;
		i--;
	}
	return (i);
}

void	frtwo(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	frone(char *s, char *w)
{
	free(s);
	free(w);
}

void	creat_fork(int *pipefd, char **av, char **envp)
{
	int	j;
	int	state;
	int	status;
	int	p;

	j = fork();
	if (j == -1)
		close_fd(pipefd);
	if (j == 0)
		first_child(pipefd, av, envp);
	p = fork();
	if (p == -1)
		close_fd(pipefd);
	if (p == 0)
		seconde_child(pipefd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(j, &state, 0);
	if (WEXITSTATUS(state) > 0)
		exit(1);
	waitpid(p, &status, 0);
	if (WEXITSTATUS(status) > 0)
		exit(1);
}

int	main(int ac, char *av[], char **envp)
{
	int	pipefd[2];

	if (ac != 5)
	{
		ft_printf("Error: bad arguments\n", strerror(1));
		return (ft_printf("./pipex infile cmd1 cmd2 outfile\n", strerror(1)), 1);
	}
	if (pipe(pipefd) == -1)
		exit_error("not piped\n");
	creat_fork(pipefd, av, envp);
}
