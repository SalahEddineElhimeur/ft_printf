/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:53:50 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:53:51 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	specifier(char c)
{
	return (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'p' || c == 'x'
		|| c == 'X');
}

int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#' || c == '.'
		|| ft_isdigit(c));
}

void	spaces(const char **format, t_flags *flags, int *flag)
{
	if (**format == ' ')
	{
		if (flags->plus == 0)
			flags->space = 1;
		*flag = 1;
	}
}

void	check_flag1(const char **format, t_flags *flags)
{
	if (**format == '#')
		flags->alternative = 1;
	else if (**format == '+')
	{
		flags->plus = 1;
		flags->space = 0;
	}
	else if (**format == '-')
	{
		flags->zero = 0;
		flags->minus = 1;
	}
	else if (**format == '0' && flags->width == 0 && !flags->minus
		&& flags->precision == -1)
		flags->zero = 1;
}

void	check_flag2(const char **format, t_flags *flags)
{
	if (ft_isdigit(**format) && **format != '0')
	{
		if (!flags->width || flags->precision >= 0)
		{
			flags->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
	}
	else if (**format == '.')
	{
		(*format)++;
		flags->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
}
