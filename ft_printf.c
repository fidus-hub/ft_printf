/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:17:51 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:18:01 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_init(void)
{
	g_flags.dash = 0;
	g_flags.zero = 0;
	g_flags.width = 0;
	g_flags.precision = -1;
	g_flags.is_flags = 0;
}

int		ft_check_format(char c, int *count, va_list *args)
{
	if (c == 'd' || c == 'i')
		ft_printd(args, count);
	if (c == 'u')
		ft_printu(args, count);
	if (c == 'p')
		if (ft_printp(args, count) == -1)
			return (-1);
	if (c == 'X')
		if (ft_printx(args, count, 1) == -1)
			return (-1);
	if (c == 'x')
		if (ft_printx(args, count, 0) == -1)
			return (-1);
	if (c == 's')
		ft_prints(args, count);
	if (c == 'c')
		ft_printc(args, count);
	if (c == '%')
		ft_print_perc(count);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		flags_init();
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i], &count);
			i++;
		}
		if (format[i] != '\0')
			i++;
		ft_getflags((char *)format, &args, &i);
		if (ft_check_format((char)format[i], &count, &args))
			return (-1);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}
