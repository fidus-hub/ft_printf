/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_dash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:18:32 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:18:35 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints_nodash(int *counter, char *s, int p, int *i)
{
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
	while (p-- > 0 && s[*i] != '\0')
	{
		ft_putchar(s[*i], counter);
		(*i)++;
	}
}

void	ft_prints_dash(int *counter, char *s, int p, int *i)
{
	while (p-- > 0 && s[*i] != '\0')
	{
		ft_putchar(s[*i], counter);
		(*i)++;
	}
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}
