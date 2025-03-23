/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:20:35 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/30 23:36:52 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tol(int elen)
{
	int	i;

	i = 0;
	if (elen == 0)
		i++;
	if (elen < 0)
		i++;
	while (elen != 0)
	{
		elen = elen / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(long int n)
{
	int	count;

	count = tol(n);
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		ft_putnbr(n);
	}
	return (count);
}
