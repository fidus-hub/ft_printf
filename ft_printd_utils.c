/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:16:37 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:16:40 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printsd_width(int d, int *counter)
{
	g_spaces = g_flags.width - ft_len(d, 10);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
		{
			if (g_flags.zero == 1 && g_flags.precision <= ft_len(d, 10)\
			&& g_flags.precision >= 0)
				ft_putchar(' ', counter);
			else if (g_flags.zero == 1)
				ft_putchar('0', counter);
			else
				ft_putchar(' ', counter);
		}
		ft_putnbr(d, counter);
	}
	else
	{
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_printud_prec(int *counter, int d)
{
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
	ft_putchar('-', counter);
	ft_putnbr(d * -1, counter);
}

void	ft_printud_zero(int *counter, int d)
{
	ft_putchar('-', counter);
	while (g_spaces-- > 0)
		ft_putchar('0', counter);
	ft_putnbr(d * -1, counter);
}

void	ft_printud_width(int d, int *counter)
{
	g_spaces = g_flags.width - ft_len((d * -1), 10) - 1;
	if (g_flags.dash == 0)
	{
		if (g_flags.zero == 1 && g_flags.precision <= ft_len(d, 10)\
		&& g_flags.precision >= 0)
			ft_printud_prec(counter, d);
		else if (g_flags.zero == 1)
			ft_printud_zero(counter, d);
		else
		{
			while (g_spaces-- > 0)
				ft_putchar(' ', counter);
			ft_putnbr(d, counter);
		}
	}
	else if (g_flags.dash == 1)
	{
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
