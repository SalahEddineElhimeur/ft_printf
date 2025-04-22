/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:17 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:21 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char **format, t_flags *flags)
{
	int	flag;

	flag = 0;
	while (**format && !specifier(**format))
	{
		if ((**format == ' ' || **format == 9) && flag == 1)
			(*format)++;
		if (!is_flag(**format))
			break ;
		spaces(format, flags, &flag);
		check_flag1(format, flags);
		check_flag2(format, flags);
		(*format)++;
	}
}

static void	print(const char format, va_list args, int *len, t_flags flags)
{
	int	flag;

	flag = 0;
	if (format == '%')
		ft_putchar('%', len);
	else if (format == 'd' || format == 'i')
		ft_putnbr_fg(va_arg(args, int), len, flags);
	else if (format == 'c')
		ft_putchar_fg(va_arg(args, int), len, flags);
	else if (format == 's')
		ft_putstr_fg(va_arg(args, char *), len, flags);
	else if (format == 'x')
		ft_puthex_fg(va_arg(args, unsigned int), len, 'x', flags);
	else if (format == 'X')
		ft_puthex_fg(va_arg(args, unsigned int), len, 'X', flags);
	else if (format == 'p')
		ft_putpointer_fg(va_arg(args, unsigned long), len, &flag, flags);
	else if (format == 'u')
		ft_putnbr_un_fg(va_arg(args, unsigned int), len, flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	t_flags	flags;

	if (!format)
		return (-1);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		flags = (t_flags){0};
		flags.precision = -1;
		if (*format == '%')
		{
			format++;
			check_flags(&format, &flags);
			print(*format, args, &len, flags);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
