/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:32:31 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/24 15:33:24 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	in_file(char *av)
{
	int	file;

	file = open(av, O_RDONLY);
	if (file < 0)
	{
		ft_printf("Error: no such file or directory : %s\n", av, strerror(1));
		exit(1);
	}
	return (file);
}

int	out_file(char *av)
{
	int	file;

	file = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
	{
		ft_printf("Error: no such file or directory : %s\n", av, strerror(1));
		exit(1);
	}
	return (file);
}
