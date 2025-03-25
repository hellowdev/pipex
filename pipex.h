/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:37:34 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/25 01:23:26 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>

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

//	
void	first_child(int *pipefd, char **av, char **envp);
void	seconde_child(int *pipefd, char **av, char **envp);
char	**awk_split(char *awk);
char	**param_join(char **firstawk, char *secawk);
char	*valid_path(char **env, char *cmd, char *av);
int		in_file(char *av, int *pipfd);
int		out_file(char *av, int *pipfd);

int		rev_len(char *s);
void	frone(char *s, char *w);
void	frtwo(char **s);
void	exit_error(char *s);
void	fcmd_not_found(char *s, char **cmd, int *pipef);
void	scmd_not_found(char *s, char **cmd, int *pipef);
void	close_fd(int *pipe);
void	ft_putstr_fd(char *s, int fd);
#endif