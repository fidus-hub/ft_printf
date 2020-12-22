/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:18:41 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:18:45 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints_both(char *s, int *counter)
{
	int	p;
	int	i;

	i = 0;
	p = g_flags.precision;
	if (g_flags.precision >= (int)ft_slen(s))
		g_spaces = g_flags.width - (int)ft_slen(s);
	else
		g_spaces = g_flags.width - g_flags.precision;
	if (g_flags.dash == 0)
		ft_prints_nodash(counter, s, p, &i);
	else
		ft_prints_dash(counter, s, p, &i);
}

void	ft_prints_width(char *s, int *counter)
{
	g_spaces = g_flags.width - (int)ft_slen(s);
	if (g_flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		ft_putstr(s, counter);
	}
	else
	{
		ft_putstr(s, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_prints_prec(char *s, int *counter)
{
	int	p;
	int	i;

	i = 0;
	g_spaces = g_flags.width - g_flags.precision;
	p = g_flags.precision;
	if (g_flags.precision == 0)
	{
		g_spaces = g_flags.width;
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
	else
	{
		if (g_flags.dash == 0)
			ft_prints_nodash(counter, s, p, &i);
		else
			ft_prints_dash(counter, s, p, &i);
	}
}

void	ft_prints(va_list *args, int *counter)
{
	char	*s;
	int		size_s;

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	size_s = (int)ft_slen(s);
	if (g_flags.is_flags == 0 || (g_flags.width <= size_s \
	&& (g_flags.precision >= size_s || g_flags.precision == -1)))
	{
		ft_putstr(s, counter);
		return ;
	}
	if (g_flags.width >= size_s && (g_flags.precision < size_s \
	&& g_flags.precision >= 0))
		ft_prints_both(s, counter);
	if (g_flags.width >= size_s && (g_flags.precision >= size_s\
	|| g_flags.precision == -1))
		ft_prints_width(s, counter);
	if (g_flags.width < size_s && (g_flags.precision < size_s\
	&& g_flags.precision >= 0))
		ft_prints_prec(s, counter);
}
