/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:15:34 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:15:36 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_width(char *ptr, int *i)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((ptr[*i] >= 9 && ptr[*i] <= 13) || ptr[*i] == ' ')
		(*i)++;
	if (ptr[*i] == '+' || ptr[*i] == '-')
	{
		if (ptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (ptr[*i] && ptr[*i] >= '0' && ptr[*i] <= '9')
	{
		res = res * 10 + (ptr[*i] - '0');
		(*i)++;
	}
	return (res * sign);
}

void	ft_width_star(va_list *args, int *i)
{
	(*i)++;
	g_flags.width = va_arg(*args, int);
	if (g_flags.width < 0)
	{
		g_flags.dash = 1;
		g_flags.width *= -1;
	}
}

void	ft_precision(char *format, va_list *args, int *i)
{
	(*i)++;
	if (!ft_isdigit(format[*i]) && format[*i] != '*')
	{
		g_flags.precision = 0;
		(*i)--;
	}
	if (ft_isdigit(format[*i]) || format[*i] == '-')
		g_flags.precision = ft_atoi_width(format, i);
	else if (format[(*i)++] == '*')
	{
		g_flags.precision = va_arg(*args, int);
		if (g_flags.precision < 0)
			g_flags.precision = -1;
	}
}

void	ft_getflags(char *format, va_list *args, int *i)
{
	while (ft_strchr("cspduixX%", format[*i]) == NULL)
	{
		if (format[*i] == '-')
		{
			g_flags.dash = 1;
			(*i)++;
		}
		if (format[*i] == '0')
		{
			g_flags.zero = 1;
			(*i)++;
		}
		if (ft_isdigit(format[*i]))
			g_flags.width = ft_atoi_width(format, i);
		else if (format[*i] == '*')
			ft_width_star(args, i);
		if (format[*i] == '.')
		{
			ft_precision(format, args, i);
		}
	}
	if (g_flags.dash != 0 || g_flags.zero != 0 \
	|| g_flags.width > 0 || g_flags.precision >= 0)
		g_flags.is_flags = 1;
}
