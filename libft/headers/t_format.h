/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/16 21:04:26 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 21:05:09 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FORMAT_H
# define T_FORMAT_H
# include "ft_dynstr.h"

# define PRINTF_FLAGS "#0- +"
# define FORMATF_NONE 0
# define FORMATF_ALT 1
# define FORMATF_ZERO 2
# define FORMATF_LEFT 4
# define FORMATF_BLANK 8
# define FORMATF_SIGN 16

typedef struct		s_format
{
	char			*output;
	t_dynstr		allocout;
	int				fd;
	char			flags;
	int				width;
	int				prec;
	char			type;
}					t_format_s;

typedef t_format_s	*t_format;

#endif
