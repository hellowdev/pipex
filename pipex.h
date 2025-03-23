#ifndef PIPEX_H
#define PIPEX_H

#include "printf/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

// tools //
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//
char	**split_path(char *av);
char	**wich_path(char **env);
char	*valid_path(char **env, char *cmd);

//	
void	first_child(int *pipefd, char **av, char **envp);
void	seconde_child(int *pipefd, char **av, char **envp);
char	**awk_split(char *awk);
char	**param_join(char **firstawk, char *secawk);
char	*valid_path(char **env, char *cmd);
int     open_files(char *av);
int		rev_len(char *s);
void	frone(char *s, char *w);
void	frtwo(char **s);
#endif