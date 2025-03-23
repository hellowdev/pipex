/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:24:11 by ychedmi           #+#    #+#             */
/*   Updated: 2024/12/01 12:07:45 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenght(unsigned int elen)
{
	int	i;

	i = 0;
	if (elen == 0)
		i++;
	while (elen != 0)
	{
		elen = elen / 10;
		i++;
	}
	return (i);
}

int	ft_undecimal(unsigned int n)
{
	int	i;

	i = lenght(n);
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	if (n > 9)
	{
		ft_undecimal(n / 10);
		ft_undecimal(n % 10);
	}
	return (i);
}
