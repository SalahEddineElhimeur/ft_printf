/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_no_minus_helper2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:56:30 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:56:31 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

int	flag_no_minus_zero(t_flags flags, int *len)
{
	if (!flags.precision)
	{
		if (flags.plus)
		{
			if (flags.width > 1)
				ft_putchar(' ', len);
			ft_putchar('+', len);
		}
		else if (flags.width > 1 || (!flags.space && flags.width == 1))
			ft_putchar(' ', len);
		return (0);
	}
	return (1);
}

int	flag_wid_no_pre(int n, t_flags flags, int *count, int *len)
{
	int	flag;

	flag = 0;
	if (flags.precision < 0)
	{
		if (flags.width > *count)
		{
			if (flags.zero)
				whattowrite('0', 0, flags.width - *count, len);
			else
				whattowrite(' ', 0, flags.width - *count, len);
			if (n < 0)
			{
				ft_putchar('-', len);
				flag = 1;
			}
		}
	}
	else
		flag = flag_wid_no_pre_helper(n, flags, count, len);
	if (flags.plus && n > 0)
		ft_putchar('+', len);
	return (flag);
}

void	flag_no_minus_no_precesion_zero(int n, int *len, t_flags flags,
		int *flag)
{
	int	count;
	int	space;

	space = 0;
	if (flags.space)
		space = 1;
	count = countnbr(n, 0);
	if (n < 0)
	{
		ft_putchar('-', len);
		whattowrite('0', count, flags.width, len);
		*flag = 1;
	}
	else
	{
		if (flags.plus)
		{
			ft_putchar('+', len);
			whattowrite('0', count + 1, flags.width - space, len);
		}
		else
			whattowrite('0', count, flags.width - space, len);
	}
}

void	flag_no_minus_no_precesion_zero_width(int n, int *len, t_flags flags,
		int *flag)
{
	int	count;

	count = countnbr(n, 0);
	if (flags.plus)
	{
		if (n < 0)
		{
			ft_putchar('-', len);
			count++;
			*flag = 1;
		}
		else
		{
			if (flags.plus)
			{
				ft_putchar('+', len);
				if (flags.precision >= count)
					count++;
			}
		}
	}
	whattowrite('0', count, flags.precision, len);
}
