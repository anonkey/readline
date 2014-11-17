/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:25:57 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 21:56:49 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_readformat.h"

int		ft_chartype(t_printf_arg *arg)
{
	arg->type = arg->act;
	arg->state = STATE_END;
	return (0);
}

int		ft_printf_char(t_printf_arg *arg, char *format, va_list *args_p)
{
	char	c;

	(void)format;
	c = (char)va_arg(*args_p, int);
	if (arg->output)
		*arg->output = c;
	else if (arg->allocout)
		return (ft_dynstradd_len(arg->allocout, &c, 1));
	else
		return (write(arg->fd, &c, 1));
	return (1);
}
