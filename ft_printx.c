/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:19:16 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:19:19 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	g_d;
int				g_spaces;
int				g_o;
char			*g_tmp;

int		ft_printx_width(unsigned int d, int *counter, int flag)
{
	if ((g_tmp = convert(d, 16, flag)) == NULL)
		return (-1);
	g_spaces = g_flags.width - ft_len2(d, 16);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
		{
			if (g_flags.zero == 1 && g_flags.precision <= ft_len2(d, 16)\
			&& g_flags.precision >= 0)
				ft_putchar(' ', counter);
			else if (g_flags.zero == 1)
				ft_putchar('0', counter);
			else
				ft_putchar(' ', counter);
		}
		ft_putstr(g_tmp, counter);
	}
	else
	{
		ft_putstr(g_tmp, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
	free(g_tmp);
	return (0);
}

void	ft_printxz_precz(int *counter)
{
	g_spaces = g_flags.width;
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}

void	ft_printx_prec(int *counter, unsigned int d, char *tmp)
{
	g_spaces = g_flags.precision - ft_len2(d, 16);
	while (g_spaces-- > 0)
		ft_putchar('0', counter);
	ft_putstr(tmp, counter);
	free(tmp);
}

void	ft_printx_precz(int *counter, char *tmp)
{
	if (g_d == 0 && g_flags.precision == 0)
		ft_printxz_precz(counter);
	else
		ft_putstr(tmp, counter);
	free(tmp);
}

int		ft_printx(va_list *args, int *counter, int flag)
{
	g_d = va_arg(*args, unsigned int);
	if ((g_tmp = convert(g_d, 16, flag)) == NULL)
		return (-1);
	if (g_flags.is_flags == 0 || (g_flags.width <= ft_len2(g_d, 16)\
	&& g_flags.precision <= ft_len2(g_d, 16)))
		ft_printx_precz(counter, g_tmp);
	else if (g_flags.width >= ft_len2(g_d, 16) \
	&& g_flags.precision > ft_len2(g_d, 16))
		ft_printx_both(g_d, counter, flag);
	else if (g_flags.width >= ft_len2(g_d, 16) \
	&& g_flags.precision <= ft_len2(g_d, 16))
	{
		if (g_d == 0 && g_flags.precision == 0)
			ft_printxz_precz(counter);
		else
			ft_printx_width(g_d, counter, flag);
	}
	else if (g_flags.width < ft_len2(g_d, 16) \
	&& g_flags.precision > ft_len2(g_d, 16))
		ft_printx_prec(counter, g_d, g_tmp);
	return (0);
}
