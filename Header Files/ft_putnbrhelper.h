/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhelper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:55 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:55:56 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTNBRHELPER_H
# define FT_PUTNBRHELPER_H

# include "data_struct.h"

void	no_minus(int n, t_flags flags, int *count, int *len);
void	no_minus_no_precesion_if(int n, t_flags flags, int *count, int *len);
void	flagspre_negative_n(int n, t_flags flags, int *flag, int *len);
void	flagspre_positive_n(int n, t_flags flags, int *len);
int		flag_wid_no_pre_helper(int n, t_flags flags, int *count, int *len);
int		flag_no_minus_zero(t_flags flags, int *len);
int		flag_wid_no_pre(int n, t_flags flags, int *count, int *len);
void	flag_no_minus_no_precesion_zero(int n, int *len, t_flags flags,
			int *flag);
void	flag_no_minus_no_precesion_zero_width(int n, int *len, t_flags flags,
			int *flag);

void	minus_plus(int n, t_flags flags, int *flag, int *len);
void	flag_minus_no_pre(int n, t_flags flags, int *len, int *flag);
void	minus_count(int n, t_flags flags, int *len, int *flag);
void	minus_if_negative(int n, t_flags flags, int *flag, int *len);
void	minus_if(int n, t_flags flags, int *count, int *len);
void	minus(int n, t_flags flags, int *count, int *len);

#endif
