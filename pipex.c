#include "pipex.h"

void	frtwo(char **s)
{
	int i;
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
void	creat_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe not found");
		exit(1);
	}
}
void	creat_fork(int *pipefd, char **av, char **envp)
{
	int j;
	int p;
	j = fork();
	if (j == 0)
		first_child(pipefd, av, envp);
	p = fork();
	if (p == 0)
		seconde_child(pipefd, av, envp);
	
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(j, NULL, 0);
	waitpid(p, NULL, 0);
}
int main(int ac, char *av[], char **envp)
{
	
    if (ac <= 5)
    {	
		// int j;
		int pipefd[2];
		creat_pipe(pipefd);

		creat_fork(pipefd, av, envp);
		// j = fork();
		// if (j == 0)
		// 	first_child(pipefd, av, envp);
		// int p;
		// p = fork();
		// if (p == 0)
		// 	seconde_child(pipefd, av, envp);
		// close(pipefd[0]);
		// close(pipefd[1]);
		// waitpid(j, NULL, 0);
		// waitpid(p, NULL, 0);
	}
}
