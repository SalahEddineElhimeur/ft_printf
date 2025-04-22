/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:50 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:55:51 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

static int	count_nbr_else(int n)
{
	unsigned int	positive;
	int				count;

	count = 1;
	positive = (unsigned int)n;
	while (positive >= 10)
	{
		count++;
		positive /= 10;
	}
	return (count);
}

int	countnbr(int n, int mode)
{
	int long	nb;
	int			count;

	count = 1;
	if (mode == 0)
	{
		nb = (long)n;
		if (n < 0)
		{
			count++;
			nb = -nb;
		}
		while (nb >= 10)
		{
			count++;
			nb /= 10;
		}
	}
	else
		count = count_nbr_else(n);
	return (count);
}

void	whattowrite(char c, int start, int end, int *len)
{
	while (start < end)
	{
		ft_putchar(c, len);
		start++;
	}
}

void	minus(int n, t_flags flags, int *count, int *len)
{
	int	flag;

	flag = 0;
	if (flags.precision < 0)
		flag_minus_no_pre(n, flags, len, &flag);
	else
	{
		if (*count <= flags.precision)
		{
			minus_if(n, flags, count, len);
		}
		else
			minus_count(n, flags, len, &flag);
	}
}

void	ft_putnbr_fg(int n, int *len, t_flags flags)
{
	int	count;

	count = countnbr(n, 0);
	if (flags.space && n >= 0 && !flags.plus)
	{
		ft_putchar(' ', len);
		count++;
	}
	if (!flags.minus)
	{
		no_minus(n, flags, &count, len);
	}
	else
	{
		minus(n, flags, &count, len);
	}
}
