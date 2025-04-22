/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:40:02 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:34 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putchar_fg(char c, int *len, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.minus)
	{
		ft_putchar(c, len);
		while (i < flags.width - 1)
		{
			ft_putchar(' ', len);
			i++;
		}
	}
	else
	{
		while (i < flags.width - 1)
		{
			ft_putchar(' ', len);
			i++;
		}
		ft_putchar(c, len);
	}
}
