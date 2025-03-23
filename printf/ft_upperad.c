/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:16:55 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/30 23:19:59 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	revien(unsigned int p)
{
	if (p >= 0 && p <= 9)
		ft_putchar(p + '0');
	else if (p > 15)
	{
		revien(p / 16);
		revien(p % 16);
	}
	else if ((p % 16 >= 10) && (p % 16 <= 15))
		ft_putchar(p + 55);
}

int	counter(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_upperad(unsigned int c)
{
	int	t;

	t = counter(c);
	revien(c);
	return (t);
}
