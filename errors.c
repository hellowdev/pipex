/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:37:01 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/25 15:18:07 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fcmd_not_found(char *s, char **cmd, int *pipef, int file)
{
	close(pipef[0]);
	close(pipef[1]);
	close (file);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(s, 2);
	write(2, "\n", 1);
	frtwo(cmd);
	exit(0);
}

void	scmd_not_found(char *s, char **cmd, int *pipef, int file)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(s, 2);
	write(2, "\n", 1);
	frtwo(cmd);
	close(file);
	close_fd(pipef);
}

void	exit_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	close_fd(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	exit(1);
}
