/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:16:49 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:16:51 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printud_both(int d, int *counter)
{
	g_spaces = g_flags.width - g_flags.precision;
	g_o = g_flags.precision - ft_len(d, 10);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
	else
	{
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_printsd_both(int d, int *counter)
{
	d *= -1;
	g_spaces = g_flags.width - g_flags.precision - 1;
	g_o = g_flags.precision - ft_len(d, 10);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		ft_putchar('-', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
	else
	{
		ft_putchar('-', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
