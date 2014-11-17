/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:16:06 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 08:43:33 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readformat.h"

#define INTFUNCS 0
#define SIZFUNCS 1

static const void*		g_printtab[2][3] =
{
	{
		&ft_putnbr_f,
		&ft_putnbr_base_f,
		&ft_putnbr_ull_f
	},
	{
		&ft_putssize_f,
		&ft_putsize_base_f,
		&ft_putsize_f
	}
};

int		ft_inttype(t_printf_arg *arg)
{
	arg->type = arg->act;
	arg->state = STATE_END;
	return (0);
}

int		ft_printf_integer(t_printf_arg *arg, char *format, va_list *args_p)
{
	long long		res;
	int				size;
	int				printind;

	printind = INTFUNCS;
	(void)format;
	size = 0;
	if (arg->len == 0 || arg->len == PRINTF_HLEN || arg->len == PRINTF_HHLEN)
		res = (long long)va_arg(*args_p, int);
	else if (arg->len == PRINTF_LLEN)
		res = (long long)va_arg(*args_p, long);
	else if (arg->len == PRINTF_LLLEN)
		res = va_arg(*args_p, long long);
	else if (arg->len == PRINTF_ZLEN)
	{
		res = (long long)va_arg(*args_p, size_t);
		printind = SIZFUNCS;
	}
	if (arg->type == 'd' || arg->type == 'i')
		size = ((t_print)g_printtab[printind][0])(res, (t_format)arg);
	else if (arg->type == 'x' || arg->type == 'X')
		size = ((t_printbase)g_printtab[printind][1])(res, arg->type == 'X' ?
				HEXBASE_MAJ : HEXBASE,
				(t_format)arg);
	else if (arg->type == 'o')
		size = ((t_printbase)g_printtab[printind][1])(res, OCTBASE,
					(t_format)arg);
	else if (arg->type == 'u')
		size = ((t_printu)g_printtab[printind][2])(res, (t_format)arg);
	return (size);
}
