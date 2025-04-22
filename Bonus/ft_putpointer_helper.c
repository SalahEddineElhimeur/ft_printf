/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:11 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:55:12 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	check_before(t_flags flags, int *len, int *flag)
{
	if (*flag == 0)
	{
		if (flags.plus)
			ft_putchar('+', len);
	}
}

static void	check_before_extra(t_flags flags, int *len, int *flag)
{
	if (flags.plus)
		ft_putchar('+', len);
	ft_putstr("0x", len);
	*flag = 1;
}

void	no_minus_helper_p(unsigned long n, t_flags flags, int *flag, int *len)
{
	int	count;

	count = countnbr_p(n);
	if (flags.width > flags.precision)
	{
		if (count > flags.precision)
			whattowrite(' ', count, flags.width, len);
		else
			whattowrite(' ', flags.precision, flags.width, len);
	}
	check_before_extra(flags, len, flag);
	whattowrite('0', count, flags.precision, len);
}

void	no_minus_p(unsigned long n, t_flags flags, int *flag, int *len)
{
	int	count;

	count = countnbr_p(n);
	if (flags.precision < 0)
	{
		if (flags.width > count)
		{
			if (flags.zero)
			{
				check_before_extra(flags, len, flag);
				whattowrite('0', count, flags.width, len);
			}
			else
				whattowrite(' ', count, flags.width, len);
		}
	}
	else
		no_minus_helper_p(n, flags, flag, len);
	check_before(flags, len, flag);
	ft_putpointer(n, len, flag);
}

void	minus_p(unsigned long n, t_flags flags, int *flag, int *len)
{
	int	count;

	count = countnbr_p(n);
	check_before_extra(flags, len, flag);
	whattowrite('0', count, flags.precision, len);
	ft_putpointer(n, len, flag);
	if (flags.width > count)
	{
		if (count > flags.precision)
			whattowrite(' ', count, flags.width, len);
		else
		{
			whattowrite(' ', flags.precision, flags.width, len);
		}
	}
}
