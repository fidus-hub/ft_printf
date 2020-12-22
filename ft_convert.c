/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:14:52 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:14:56 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexlen(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*convert(size_t num, int base, int flag)
{
	char	*ptr;
	int		i;

	i = hexlen(num);
	if ((ptr = malloc(hexlen(num) + 1)) == NULL)
		return (NULL);
	ptr[i--] = '\0';
	if (num == 0)
		ptr[i] = '0';
	while (num != 0 && flag == 0)
	{
		ptr[i] = BASES_LOW[num % base];
		num /= base;
		i--;
	}
	while (num != 0 && flag == 1)
	{
		ptr[i] = BASES_UP[num % base];
		num /= base;
		i--;
	}
	return (ptr);
}
