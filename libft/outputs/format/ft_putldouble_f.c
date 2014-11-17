/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldouble_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:53:47 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 19:37:40 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "t_format.h"

static int	ft_printradix(long double nb, int prec, char *buf)
{
	char	digit;
	int		size;

	size = prec + 1;
	*buf++ = RADIX_CHAR;
	while (prec > 0)
	{
		if (nb != 0)
		{
			digit = (char)(nb *= 10);
			nb -= (long double)digit;
			*buf++ = digit + '0';
		}
		else
			*buf++ = '0';
		--prec;
	}
	return (size);
}
static void		fillres(long double nb, t_format fmt, char *out)
{
	int				size;
	long double		mask;
	char			digit;

	size = 0;
	mask = 1.0;
	if (nb < 0 || fmt->flags & FORMATF_SIGN)
	{
		out[size++] = nb < 0 ? '-' : '+';
		if (nb < 0)
			nb = 0 - nb;
	}
	while (nb / mask > 10.0)
		mask *= 10.0;
	while (mask >= 1.0)
	{
		nb -= mask * (long double)(digit = (char)(nb / mask));
		mask /= 10.0;
		out[size++] = digit + '0';
	}
	if (fmt->prec > 0)
		size += ft_printradix(nb, fmt->prec, out + size);
	else if (fmt->flags == FORMATF_ALT)
		out[size++] = RADIX_CHAR;
	out[size] = '\0';
}

int			ft_putldouble_f(long double nb, t_format fmt)
{
	char			buf[MAX_DBLSIZE];
	char			*output;

	output = fmt->output ? fmt->output : buf;
	fillres(nb, fmt, output);
	if (fmt->output)
		return (ft_strlen(output));
	else if (fmt->allocout)
		return (ft_dynstradd(fmt->allocout, output));
	else
		return (write(fmt->fd, output, ft_strlen(output)));
}
