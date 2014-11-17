/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readformat.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:04:43 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 02:58:05 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READFORMAT_H
# define FT_READFORMAT_H

# include <stdarg.h>
# include "libft.h"
# include "t_format.h"
# include "ft_printfn.h"
# include "ft_printfarg.h"
# define HEXBASE_MAJ "0123456789ABCDEF"
# define HEXBASE "0123456789abcdef"
# define OCTBASE "01234567"
# define NULLPTR_STR "0x0"
# define DFL_FLOAT_PREC 6
# define PRINTF_FLAGS "#0- +"


typedef int			(*t_print)(long long, t_format);

typedef int			(*t_printu)(unsigned long long, t_format);

typedef int			(*t_printbase)(unsigned long long, char *, t_format);

typedef int			(*t_parsefunc)(t_printf_arg *);

int					ft_inttype(t_printf_arg *arg);

int					ft_zlen(t_printf_arg *arg);

int					ft_hlen(t_printf_arg *arg);

int					ft_hhlen(t_printf_arg *arg);

int					ft_llen(t_printf_arg *arg);

int					ft_dllen(t_printf_arg *arg);

int					ft_lllen(t_printf_arg *arg);

int					ft_strtype(t_printf_arg *arg);

int					ft_chartype(t_printf_arg *arg);

int					ft_pointtype(t_printf_arg *arg);

int					ft_floattype(t_printf_arg *arg);

#endif
