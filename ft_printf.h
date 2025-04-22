/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:25 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:26 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Header Files/ft_putnbrhelper.h"
# include "Header Files/data_struct.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar_fg(char c, int *len, t_flags flags);
void	ft_puthex(unsigned int n, int *len, char x);
void	ft_puthex_fg(unsigned int n, int *len, char x, t_flags flags);
void	ft_putpointer(unsigned long n, int *len, int *flag);
void	ft_putpointer_fg(unsigned long n, int *len, int *flag, t_flags flags);
void	ft_putchar(char c, int *len);
size_t	ft_strlen(const char *s);

void	ft_putstr(char *s, int *len);
void	ft_putstr_fg(char *s, int *len, t_flags flags);
void	ft_putnbr(int n, int *len, int *flag);
void	check_flags(const char **format, t_flags *flags);
void	ft_putnbr_fg(int n, int *len, t_flags flags);
int		ft_atoi(const char *str);
int		ft_isdigit(int n);
void	ft_putnbr_un(unsigned int n, int *len);
void	ft_putnbr_un_fg(unsigned int n, int *len, t_flags flags);
int		specifier(char c);
int		is_flag(char c);
void	spaces(const char **format, t_flags *flags, int *flag);
void	check_flag1(const char **format, t_flags *flags);
void	check_flag2(const char **format, t_flags *flags);

void	whattowrite(char c, int start, int end, int *len);
int		countnbr(int n, int mode);

void	no_minus_u(unsigned int n, t_flags flags, int *count, int *len);
void	minus_u_else(unsigned int n, t_flags flags, int *count, int *len);
void	minus_u(unsigned int n, t_flags flags, int *count, int *len);
void	minus_u_else(unsigned int n, t_flags flags, int *count, int *len);

int		countnbr_p(unsigned long n);
void	no_minus_helper_p(unsigned long n, t_flags flags, int *flag, int *len);
void	no_minus_p(unsigned long n, t_flags flags, int *flag, int *len);
void	minus_p(unsigned long n, t_flags flags, int *flag, int *len);

int		countnbr_hex(unsigned int n);
#endif
