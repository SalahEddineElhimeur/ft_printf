/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:54:12 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:14 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef struct s_flags
{
	int	minus;
	int	plus;
	int	alternative;
	int	zero;
	int	width;
	int	precision;
	int	space;
	int	count;
	int	flag;

}		t_flags;

#endif
