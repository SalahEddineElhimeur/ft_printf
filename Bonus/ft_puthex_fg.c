/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:29:51 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/26 19:29:52 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	check_alternative(unsigned int n, t_flags flags, char x, int *len)
{
	if (flags.alternative && n > 0)
	{
		if (x == 'x')
		{
			ft_putstr("0x", len);
		}
		else
			ft_putstr("0X", len);
	}
}

static void	no_minus_hex_else(unsigned int n, int *len, char x, t_flags *flags)
{
	flags->flag = 0;
	if (flags->precision >= 0)
	{
		if (flags->count <= flags->precision)
		{
			whattowrite(' ', flags->precision, flags->width, len);
			check_alternative(n, *flags, x, len);
			whattowrite('0', flags->count, flags->precision, len);
		}
		else
		{
			whattowrite(' ', 0, flags->width - flags->count, len);
			check_alternative(n, *flags, x, len);
			flags->flag = 1;
		}
		if (!n && !flags->precision && flags->width)
			return (ft_putchar(' ', len));
		if (!n && !flags->precision && !flags->width)
			return ;
	}
	if ((!flags->precision && !flags->flag))
		check_alternative(n, *flags, x, len);
	ft_puthex(n, len, x);
}

static void	no_minus_hex(unsigned int n, int *len, char x, t_flags flags)
{
	if (flags.precision < 0)
	{
		if (flags.zero)
		{
			check_alternative(n, flags, x, len);
			whattowrite('0', flags.count, flags.width, len);
		}
		else
		{
			if (flags.width > flags.count)
			{
				whattowrite(' ', flags.count, flags.width, len);
			}
			check_alternative(n, flags, x, len);
			whattowrite('0', flags.count, flags.precision, len);
		}
	}
	no_minus_hex_else(n, len, x, &flags);
}

static void	minus_hex_else(unsigned int n, int *len, char x, t_flags flags)
{
	if (flags.count <= flags.precision)
	{
		whattowrite('0', flags.count, flags.precision, len);
		ft_puthex(n, len, x);
		if (flags.width >= flags.precision)
			whattowrite(' ', flags.precision, flags.width, len);
	}
	else
	{
		if (!n && !flags.precision && !flags.width)
			return ;
		else if (!n && !flags.precision)
			ft_putchar(' ', len);
		else
		{
			if (n > 0)
				ft_puthex(n, len, x);
		}
		whattowrite(' ', flags.count, flags.width, len);
	}
}

void	ft_puthex_fg(unsigned int n, int *len, char x, t_flags flags)
{
	flags.count = countnbr_hex(n);
	if (flags.alternative && n > 0)
		flags.width -= 2;
	if (!flags.minus)
		no_minus_hex(n, len, x, flags);
	else
	{
		check_alternative(n, flags, x, len);
		if (flags.precision < 0)
		{
			ft_puthex(n, len, x);
			if (flags.count < flags.width)
				whattowrite(' ', flags.count, flags.width, len);
		}
		else
		{
			minus_hex_else(n, len, x, flags);
		}
	}
}
