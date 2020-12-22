/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:16:26 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:16:29 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printc(va_list *args, int *counter)
{
	char	c;
	int		spaces;

	spaces = g_flags.width - 1;
	c = va_arg(*args, int);
	if (g_flags.dash == 0)
	{
		while (spaces-- > 0)
			ft_putchar(' ', counter);
		ft_putchar(c, counter);
	}
	else
	{
		ft_putchar(c, counter);
		while (spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
