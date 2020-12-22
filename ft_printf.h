/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:18:12 by mgrissen          #+#    #+#             */
/*   Updated: 2020/12/22 18:18:15 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define BASES_UP "0123456789ABCDEF"
# define BASES_LOW "0123456789abcdef"

typedef struct	s_flags
{
	int dash;
	int zero;
	int width;
	int precision;
	int is_flags;
} 				t_flags;

t_flags g_flags;

int				g_spaces;
int				g_o;
int				ft_printf(const char *format, ...);
void			ft_putchar(char c, int *counter);
void			ft_getflags(char *format, va_list *args, int *i);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
void			ft_printd(va_list *args, int *counter);
int				ft_len(long long n, int base);
int				ft_len2(unsigned long long n, int base);
void			ft_printd_noprec(int *counter);
void			ft_putnbr(int nb, int *counter);
void			ft_printd_both(int *counter, int d);
void			ft_printud_both(int d, int *counter);
void			ft_printsd_both(int d, int *counter);
void			ft_printsd_width(int d, int *counter);
void			ft_printud_width(int d, int *counter);
void			ft_printu(va_list *args, int *counter);
void			ft_put_unbr(unsigned int nb, int *counter);
void			ft_printu_both(unsigned int d, int *counter);
void			ft_printu_width(unsigned int d, int *counter);
void			ft_printc(va_list *args, int *counter);
void			ft_print_perc(int *counter);
int				ft_printx(va_list *args, int *counter, int flag);
void			ft_putstr(char *s, int *counter);
int				ft_printx_both(unsigned int d, int *counter, int flag);
char			*convert(size_t num, int base, int flag);
int				ft_printp(va_list *args, int *counter);
int				ft_putaddress(void *ptr, int *counter);
size_t			ft_slen(const char *str);
void			ft_prints(va_list *args, int *counter);
void			ft_prints(va_list *args, int *counter);
void			ft_prints_dash(int *counter, char *s, int p, int *i);
void			ft_prints_nodash(int *counter, char *s, int p, int *i);
#endif
