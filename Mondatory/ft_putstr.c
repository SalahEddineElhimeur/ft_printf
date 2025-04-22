/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:20 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:55:21 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	writespace(size_t *spaces, size_t slen, t_flags flags, int *len)
{
	size_t	i;

	i = 0;
	*spaces = flags.width - slen;
	while (i < *spaces)
	{
		ft_putchar(' ', len);
		i++;
	}
}

static void	minus_right(char *s, t_flags flags, size_t *spaces, int *len)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(s);
	if (flags.precision >= 0)
	{
		if ((int)slen > flags.precision)
			slen = flags.precision;
	}
	if (slen < (size_t)flags.width)
	{
		writespace(spaces, slen, flags, len);
		while (s[i] && (i + *spaces < (size_t)flags.width))
			ft_putchar(s[i++], len);
	}
	else
	{
		while (s[i] && i < slen)
		{
			ft_putchar(s[i], len);
			i++;
		}
	}
}

static void	minus_left(char *s, t_flags flags, size_t *spaces, int *len)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	if (flags.precision >= 0)
	{
		if ((int)slen > flags.precision)
			slen = flags.precision;
	}
	while (s[i] && (i < slen))
	{
		ft_putchar(s[i], len);
		i++;
	}
	if (slen < (size_t)flags.width)
	{
		writespace(spaces, slen, flags, len);
	}
}

void	ft_putstr(char *s, int *len)
{
	int	i;
	int	slen;

	if (!s)
		return ;
	slen = ft_strlen(s);
	i = 0;
	while (i < slen)
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_putstr_fg(char *s, int *len, t_flags flags)
{
	size_t	spaces;

	spaces = 0;
	if (!s)
	{
		if (flags.precision > 0 && flags.precision < 6)
			s = "";
		else
			s = "(null)";
	}
	if (flags.space)
		spaces = 1;
	if (!flags.minus)
	{
		minus_right(s, flags, &spaces, len);
	}
	else
	{
		minus_left(s, flags, &spaces, len);
	}
}
