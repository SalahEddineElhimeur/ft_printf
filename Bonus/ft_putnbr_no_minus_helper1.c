/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_no_minus_helper1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:56:24 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:56:25 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

void	no_minus(int n, t_flags flags, int *count, int *len)
{
	int	flag;

	flag = 0;
	if (flags.precision < 0)
	{
		no_minus_no_precesion_if(n, flags, count, len);
	}
	else
	{
		if (*count <= flags.precision)
		{
			if (n < 0)
				flagspre_negative_n(n, flags, &flag, len);
			else
				flagspre_positive_n(n, flags, len);
		}
		else
			flag = flag_wid_no_pre(n, flags, count, len);
		if (!n)
		{
			if (!flag_no_minus_zero(flags, len))
				return ;
		}
		ft_putnbr(n, len, &flag);
	}
}

void	no_minus_no_precesion_if(int n, t_flags flags, int *count, int *len)
{
	int	flag;

	flag = 0;
	if (flags.zero)
		flag_no_minus_no_precesion_zero(n, len, flags, &flag);
	else
	{
		if (flags.width > *count)
		{
			if (flags.plus && n >= 0)
				(*count)++;
			whattowrite(' ', *count, flags.width, len);
		}
		flag_no_minus_no_precesion_zero_width(n, len, flags, &flag);
	}
	ft_putnbr(n, len, &flag);
}

void	flagspre_negative_n(int n, t_flags flags, int *flag, int *len)
{
	int	count;

	count = countnbr(n, 0);
	if (flags.width > flags.precision)
	{
		if (flags.precision <= 0)
			whattowrite(' ', 1, flags.width, len);
		else
			whattowrite(' ', flags.precision, flags.width - 1, len);
	}
	ft_putchar('-', len);
	*flag = 1;
	whattowrite('0', count - 1, flags.precision, len);
}

void	flagspre_positive_n(int n, t_flags flags, int *len)
{
	int	count;

	count = countnbr(n, 0);
	if (flags.plus)
	{
		whattowrite(' ', flags.precision, flags.width - 1, len);
		ft_putchar('+', len);
		if (flags.width <= flags.precision)
			whattowrite('0', count, flags.precision, len);
		else
			whattowrite('0', count, flags.precision, len);
	}
	else
	{
		if (flags.space)
			whattowrite(' ', flags.precision, flags.width - 1, len);
		else
			whattowrite(' ', flags.precision, flags.width, len);
		whattowrite('0', countnbr(n, 0), flags.precision, len);
	}
}

int	flag_wid_no_pre_helper(int n, t_flags flags, int *count, int *len)
{
	int	flag;

	flag = 0;
	if (flags.width > *count)
	{
		if (flags.plus && n >= 0)
			(*count)++;
		whattowrite(' ', 0, flags.width - *count, len);
		if (n < 0)
		{
			ft_putchar('-', len);
			flag = 1;
		}
	}
	return (flag);
}
