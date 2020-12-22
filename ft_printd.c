/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:17:02 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:17:03 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printd_precision(int *counter, int d)
{
	if (d >= 0)
	{
		g_spaces = g_flags.precision - ft_len(d, 10);
		while (g_spaces-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
	else
	{
		d *= -1;
		g_spaces = g_flags.precision - ft_len(d, 10);
		ft_putchar('-', counter);
		while (g_spaces-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
}

void	ft_printd_noprec(int *counter)
{
	g_spaces = g_flags.width;
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}

void	ft_printd_both(int *counter, int d)
{
	if (d >= 0)
		ft_printud_both(d, counter);
	else
		ft_printsd_both(d, counter);
}

void	ft_printd(va_list *args, int *counter)
{
	int d;

	d = va_arg(*args, int);
	if (g_flags.is_flags == 0 || (g_flags.width <= ft_len(d, 10)\
	&& g_flags.precision <= ft_len(d, 10)))
	{
		if (d == 0 && g_flags.precision == 0)
			ft_printd_noprec(counter);
		else
			ft_putnbr(d, counter);
		return ;
	}
	if (g_flags.width >= ft_len(d, 10) && g_flags.precision > ft_len(d, 10))
		ft_printd_both(counter, d);
	if (g_flags.width >= ft_len(d, 10) && g_flags.precision <= ft_len(d, 10))
	{
		if (d == 0 && g_flags.precision == 0)
			ft_printd_noprec(counter);
		else if (d >= 0)
			ft_printsd_width(d, counter);
		else
			ft_printud_width(d, counter);
	}
	if (g_flags.width < ft_len(d, 10) && g_flags.precision > ft_len(d, 10))
		ft_printd_precision(counter, d);
}
