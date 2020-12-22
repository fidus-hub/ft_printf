/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:19:02 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:19:03 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu_noprec(int *counter)
{
	g_spaces = g_flags.width;
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}

void	ft_printu_prec(int *counter, unsigned int d)
{
	g_spaces = g_flags.precision - ft_len2(d, 10);
	while (g_spaces-- > 0)
		ft_putchar('0', counter);
	ft_put_unbr(d, counter);
}

void	ft_printu(va_list *args, int *counter)
{
	unsigned int	d;

	d = va_arg(*args, unsigned int);
	if (g_flags.is_flags == 0 || (g_flags.width <= ft_len2(d, 10) \
	&& g_flags.precision <= ft_len2(d, 10)))
	{
		if (d == 0 && g_flags.precision == 0)
			ft_printu_noprec(counter);
		else
			ft_put_unbr(d, counter);
		return ;
	}
	if (g_flags.width >= ft_len2(d, 10) && g_flags.precision > ft_len2(d, 10))
		ft_printu_both(d, counter);
	if (g_flags.width >= ft_len2(d, 10) && g_flags.precision <= ft_len2(d, 10))
	{
		if (d == 0 && g_flags.precision == 0)
			ft_printu_noprec(counter);
		else
			ft_printu_width(d, counter);
	}
	if (g_flags.width < ft_len2(d, 10) && g_flags.precision > ft_len2(d, 10))
		ft_printu_prec(counter, d);
}
