/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:52 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:53 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../Header Files/ft_putnbrhelper.h"

void	minus_u_else(unsigned int n, t_flags flags, int *count, int *len)
{
	if (*count <= flags.precision)
	{
		whattowrite('0', *count, flags.precision, len);
		ft_putnbr_un(n, len);
		if (flags.width > flags.precision)
			whattowrite(' ', flags.precision, flags.width, len);
	}
	else
	{
		if (!n && !flags.precision && !flags.width)
			return ;
		else if (!n && !flags.precision)
			ft_putchar(' ', len);
		else
			ft_putnbr_un(n, len);
		whattowrite(' ', *count, flags.width, len);
	}
}

void	minus_u(unsigned int n, t_flags flags, int *count, int *len)
{
	if (flags.precision < 0)
	{
		ft_putnbr_un(n, len);
		if (*count < flags.width)
			whattowrite(' ', *count, flags.width, len);
	}
	else
	{
		minus_u_else(n, flags, count, len);
	}
}

void	no_minus_u_else(unsigned int n, t_flags flags, int *count, int *len)
{
	if (*count <= flags.precision)
	{
		whattowrite(' ', flags.precision, flags.width, len);
		whattowrite('0', *count, flags.precision, len);
	}
	else
	{
		if (flags.width > *count)
			whattowrite(' ', 0, flags.width - *count, len);
	}
	if (!n)
	{
		if (flags.precision >= 1)
			ft_putchar('0', len);
		else if (flags.width)
			ft_putchar(' ', len);
		return ;
	}
	ft_putnbr_un(n, len);
}

void	no_minus_u(unsigned int n, t_flags flags, int *count, int *len)
{
	if (flags.precision < 0)
	{
		if (flags.width > *count)
		{
			if (flags.zero)
				whattowrite('0', *count, flags.width, len);
			else
				whattowrite(' ', *count, flags.width, len);
		}
		ft_putnbr_un(n, len);
	}
	else
	{
		no_minus_u_else(n, flags, count, len);
	}
}

void	minus_if_negative(int n, t_flags flags, int *flag, int *len)
{
	int	count;

	count = countnbr(n, 0);
	ft_putchar('-', len);
	whattowrite('0', count - 1, flags.precision, len);
	*flag = 1;
	ft_putnbr(n, len, flag);
	whattowrite(' ', 1 + flags.precision, flags.width, len);
}
