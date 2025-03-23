/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:26:43 by ychedmi           #+#    #+#             */
/*   Updated: 2024/12/01 22:05:51 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(const char *form, va_list p)
{
	int	j;
	int	o;

	j = 0;
	o = 0;
	if (form[j] == '%' && form[j + 1] == 'c')
		o = ft_putchar(va_arg(p, int));
	else if (form[j] == '%' && form[j + 1] == 's')
		o = ft_putstr(va_arg(p, char *));
	else if (form[j] == '%' && (form[j + 1] == 'd' || form[j + 1] == 'i'))
		o = ft_putnbr(va_arg(p, int));
	else if (form[j] == '%' && form[j + 1] == 'u')
		o = ft_undecimal(va_arg(p, unsigned int));
	else if (form[j] == '%' && form[j + 1] == 'p')
		o = ft_padress(va_arg(p, void *));
	else if (form[j] == '%' && form[j + 1] == 'x')
		o = ft_lowerad(va_arg(p, long));
	else if (form[j] == '%' && form[j + 1] == 'X')
		o = ft_upperad(va_arg(p, long));
	else if (form[j] == '%')
		o = write(1, &form[j + 1], 1);
	else 
		o = write(1, &form[j], 1);
	return (o);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		b;
	va_list	p;

	i = 0;
	b = 0;
	va_start(p, format);
	while (format[i])
	{
		b += checker(&format[i], p);
		if (format[i] == '%')
			i++;
		i++;
	}
	va_end(p);
	return (b);
}
