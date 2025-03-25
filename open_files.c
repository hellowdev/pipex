/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:32:31 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/25 14:48:56 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	in_file(char *av, int *pipfd)
{
	int	file;

	file = open(av, O_RDONLY);
	if (access(av, F_OK) != 0)
	{
		ft_putstr_fd("pipex: no such file or directory : ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	if (access(av, R_OK) != 0)
	{
		ft_putstr_fd("pipex: Permission denied: ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	if (file < 0)
	{
		perror("pipex");
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	return (file);
}

int	out_file(char *av, int *pipfd)
{
	int	file;

	file = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (access(av, F_OK) != 0)
	{
		ft_putstr_fd("pipex: No such file or directory : ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	if (access(av, W_OK) != 0)
	{
		ft_putstr_fd("pipex: Permission denied: ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	if (file < 0)
	{
		perror("pipex");
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	return (file);
}
