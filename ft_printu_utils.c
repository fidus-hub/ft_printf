/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:18:51 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:18:54 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu_both(unsigned int d, int *counter)
{
	g_spaces = g_flags.width - g_flags.precision;
	g_o = g_flags.precision - ft_len2(d, 10);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_put_unbr(d, counter);
	}
	else
	{
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_put_unbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_printu_width(unsigned int d, int *counter)
{
	g_spaces = g_flags.width - ft_len2(d, 10);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
		{
			if (g_flags.zero == 1 && g_flags.precision <= ft_len2(d, 10)\
			&& g_flags.precision >= 0)
				ft_putchar(' ', counter);
			else if (g_flags.zero == 1)
				ft_putchar('0', counter);
			else
				ft_putchar(' ', counter);
		}
		ft_put_unbr(d, counter);
	}
	else
	{
		ft_put_unbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
