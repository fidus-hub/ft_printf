/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:19:10 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:19:11 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printx_both(unsigned int d, int *counter, int flag)
{
	char	*tmp;

	if ((tmp = convert(d, 16, flag)) == NULL)
		return (-1);
	g_spaces = g_flags.width - g_flags.precision;
	g_o = g_flags.precision - ft_len2(d, 16);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putstr(tmp, counter);
	}
	else
	{
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putstr(tmp, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
	free(tmp);
	return (0);
}
