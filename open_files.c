/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:32:31 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/25 00:56:42 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	in_file(char *av, int *pipfd)
{
	int	file;

	file = open(av, O_RDONLY);
	if (file < 0)
	{
		ft_putstr_fd("Error: no such file or directory : ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	return (file);
}

int	out_file(char *av, int *pipfd)
{
	int	file;

	file = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file < 0)
	{
		ft_putstr_fd("Error: no such file or directory : ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
		close_fd(pipfd);
	}
	return (file);
}
