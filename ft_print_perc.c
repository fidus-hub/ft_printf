/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:16:15 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:16:20 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_perc(int *counter)
{
	int spaces;

	spaces = g_flags.width - 1;
	if (g_flags.dash == 0)
	{
		if (g_flags.zero == 1)
		{
			while (spaces-- > 0)
				ft_putchar('0', counter);
		}
		else
		{
			while (spaces-- > 0)
				ft_putchar(' ', counter);
		}
		ft_putchar('%', counter);
	}
	else
	{
		ft_putchar('%', counter);
		while (spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
