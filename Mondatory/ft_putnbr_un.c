/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:58 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:59 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

void	ft_putnbr_un(unsigned int n, int *len)
{
	if (n > 9)
		ft_putnbr_un(n / 10, len);
	ft_putchar((n % 10) + '0', len);
}

void	ft_putnbr_un_fg(unsigned int n, int *len, t_flags flags)
{
	int	count;

	count = countnbr(n, 1);
	if (!flags.minus)
	{
		no_minus_u(n, flags, &count, len);
	}
	else
	{
		minus_u(n, flags, &count, len);
	}
}
