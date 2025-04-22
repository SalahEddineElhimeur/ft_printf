/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:39 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:40 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	countnbr_hex(unsigned int n)
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

void	ft_puthex(unsigned int n, int *len, char x)
{
	if (n >= 16)
		ft_puthex(n / 16, len, x);
	if ((n % 16) > 9)
	{
		if (x == 'x')
			ft_putchar((n % 16) - 10 + 'a', len);
		else if (x == 'X')
			ft_putchar((n % 16) - 10 + 'A', len);
	}
	else
		ft_putchar((n % 16) + '0', len);
}
