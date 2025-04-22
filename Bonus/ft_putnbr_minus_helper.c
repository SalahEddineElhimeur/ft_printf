/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_minus_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:56:14 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:56:16 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

void	minus_plus(int n, t_flags flags, int *flag, int *len)
{
	int	count;

	count = countnbr(n, 0);
	ft_putchar('+', len);
	if (flags.width <= flags.precision)
		whattowrite('0', count, flags.precision, len);
	else if (flags.width > flags.precision)
		whattowrite('0', 0, flags.precision - count, len);
	ft_putnbr(n, len, flag);
	if (flags.width > flags.precision)
		whattowrite(' ', 1 + flags.precision, flags.width, len);
}

void	flag_minus_no_pre(int n, t_flags flags, int *len, int *flag)
{
	int	count;

	count = countnbr(n, 0);
	if (flags.plus && n >= 0)
	{
		ft_putchar('+', len);
		count++;
	}
	ft_putnbr(n, len, flag);
	if (count < flags.width)
	{
		if (flags.space)
		{
			if (n < 0)
				whattowrite(' ', count, flags.width, len);
			else
				whattowrite(' ', count, flags.width - 1, len);
		}
		else
			whattowrite(' ', count, flags.width, len);
	}
}

void	minus_count(int n, t_flags flags, int *len, int *flag)
{
	int	count;

	count = countnbr(n, 0);
	if (flags.space && n >= 0 && !flags.plus)
		count++;
	else if (flags.plus && n >= 0)
	{
		ft_putchar('+', len);
		count++;
	}
	if (!n && flags.width >= 1 && !flags.precision)
	{
		if (flags.width <= 1 && (flags.space || flags.plus))
			return ;
		else
			ft_putchar(' ', len);
	}
	else if (!n && !flags.precision)
		return ;
	else
		ft_putnbr(n, len, flag);
	whattowrite(' ', count, flags.width, len);
}

void	minus_if_else(int n, t_flags flags, int *count, int *len)
{
	int	flag;
	int	space;

	space = 0;
	flag = 0;
	if (flags.space)
		space = 1;
	if (flags.width < flags.precision)
	{
		whattowrite('0', *count, flags.precision + space, len);
		ft_putnbr(n, len, &flag);
	}
	else
	{
		whattowrite('0', 0, flags.precision - *count + space, len);
		ft_putnbr(n, len, &flag);
		whattowrite(' ', flags.precision, flags.width - space, len);
	}
}

void	minus_if(int n, t_flags flags, int *count, int *len)
{
	int	flag;

	flag = 0;
	if (n < 0)
		minus_if_negative(n, flags, &flag, len);
	else
	{
		if (flags.plus)
			minus_plus(n, flags, &flag, len);
		else
		{
			minus_if_else(n, flags, count, len);
		}
	}
}
