/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:45 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:46 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

void	ft_putnbr(int n, int *len, int *flag)
{
	long	i;

	i = (long)n;
	if (i < 0)
	{
		if (*flag == 0)
		{
			ft_putchar('-', len);
			*flag = 1;
		}
		i = -i;
	}
	if (i > 9)
		ft_putnbr(i / 10, len, flag);
	ft_putchar((i % 10) + '0', len);
}
