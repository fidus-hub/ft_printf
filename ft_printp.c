/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:18:21 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:18:25 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printp_width(void *d, int *counter)
{
	int	spaces;

	spaces = g_flags.width - ft_len2((size_t)d, 16) - 2;
	if (g_flags.dash == 0)
	{
		while (spaces-- > 0)
			ft_putchar(' ', counter);
		if (ft_putaddress(d, counter) == -1)
			return (-1);
	}
	else
	{
		if (ft_putaddress(d, counter) == -1)
			return (-1);
		while (spaces-- > 0)
			ft_putchar(' ', counter);
	}
	return (0);
}

void	ft_noprecision(int *counter, int spaces)
{
	if (g_flags.width > 2)
	{
		spaces = g_flags.width - 2;
		if (g_flags.dash == 0)
		{
			while (spaces-- > 0)
				ft_putchar(' ', counter);
			ft_putstr("0x", counter);
		}
		else
		{
			ft_putstr("0x", counter);
			while (spaces-- > 0)
				ft_putchar(' ', counter);
		}
	}
	else
		ft_putstr("0x", counter);
}

int		ft_printp(va_list *args, int *counter)
{
	void	*d;
	int		spaces;

	spaces = 0;
	d = va_arg(*args, char *);
	if (g_flags.precision == 0 && d == (void*)0)
	{
		ft_noprecision(counter, spaces);
		return (0);
	}
	if (g_flags.is_flags == 0 || g_flags.width <= ft_len2((size_t)d, 16))
	{
		if (ft_putaddress(d, counter) == -1)
			return (-1);
	}
	if (g_flags.width > ft_len2((size_t)d, 16))
		ft_printp_width(d, counter);
	return (0);
}
