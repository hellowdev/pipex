/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:58:01 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/30 23:00:14 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	re(unsigned int p)
{
	if (p >= 0 && p <= 9)
		ft_putchar(p + '0');
	else if (p > 15)
	{
		re(p / 16);
		re(p % 16);
	}
	else if ((p % 16 >= 10) && (p % 16 <= 15))
		ft_putchar(p + 87);
}

int	count(unsigned int n)
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

int	ft_lowerad(unsigned int c)
{
	int	t;

	t = count(c);
	re(c);
	return (t);
}
