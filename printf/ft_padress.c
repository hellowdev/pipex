/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:03:15 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/30 23:09:55 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recur(unsigned long p)
{
	if (p >= 0 && p <= 9)
		ft_putchar(p + '0');
	else if (p > 15)
	{
		recur(p / 16);
		recur(p % 16);
	}
	else if ((p % 16 >= 10) && (p % 16 <= 15))
		ft_putchar(p + 87);
}

int	len(unsigned long n)
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

int	ft_padress(void *c)
{
	unsigned long	p;
	int				t;

	p = (unsigned long)c;
	t = len(p);
	t += write(1, "0x", 2);
	recur(p);
	return (t);
}
