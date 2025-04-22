/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:04 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:55:06 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	countnbr_p(unsigned long n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	ft_putpointer(unsigned long n, int *len, int *flag)
{
	if (!n)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	if (!*flag)
	{
		ft_putstr("0x", len);
		*flag = 1;
	}
	if (n >= 16)
		ft_putpointer(n / 16, len, flag);
	if ((n % 16) > 9)
		ft_putchar((n % 16) - 10 + 'a', len);
	else
		ft_putchar((n % 16) + '0', len);
}

void	ft_putpointer_fg(unsigned long n, int *len, int *flag, t_flags flags)
{
	if (!n)
	{
		ft_putstr_fg("(nil)", len, flags);
		return ;
	}
	flags.width -= 2;
	if (flags.space || flags.plus)
		flags.width--;
	if (!flags.minus)
	{
		no_minus_p(n, flags, flag, len);
	}
	if (flags.minus)
	{
		minus_p(n, flags, flag, len);
	}
}
