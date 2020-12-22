/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:17:13 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:17:14 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putnbr(int nb, int *counter)
{
	unsigned int n;

	if (nb < 0)
	{
		n = nb * -1;
		ft_putchar('-', counter);
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10, counter);
		ft_putchar(n % 10 + '0', counter);
	}
	else
		ft_putchar(n + '0', counter);
}

void	ft_put_unbr(unsigned int nb, int *counter)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, counter);
		ft_putchar(nb % 10 + '0', counter);
	}
	else
		ft_putchar(nb + '0', counter);
}

void	ft_putstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != 0)
	{
		ft_putchar(s[i], counter);
		i++;
	}
}

int		ft_putaddress(void *ptr, int *counter)
{
	char	*hex_add;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		*counter += 3;
		return (0);
	}
	ft_putstr("0x", counter);
	if ((hex_add = convert((size_t)ptr, 16, 0)) == NULL)
		return (-1);
	ft_putstr(hex_add, counter);
	free(hex_add);
	return (0);
}
