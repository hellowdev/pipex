/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:37:01 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/24 15:37:18 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char *s, char **cmd)
{
	ft_printf("Error: command not found: %s\n", s, strerror(1));
	frtwo(cmd);
	exit(1);
}

void	exit_error(char *s)
{
	ft_printf("%s", s, strerror(1));
	exit(1);
}

void	close_fd(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	exit_error("fork error\n");
}
