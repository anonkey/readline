/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldouble_sci.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:53:29 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 19:37:53 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "t_format.h"

static int		ft_printradix(long double nb, int prec, int mask, char *out)
{
	char	digit;
	int		size;

	size = prec + 1;
	*out++ = RADIX_CHAR;
	while (mask >= 1.0)
	{
		digit = (char)(nb / mask);
		nb -= mask * (long double)digit;
		mask /= 10.0;
		*out++ = digit + '0';
	}
	while (prec > 0)
	{
		if (nb != 0)
		{
			digit = (char)(nb *= 10);
			nb -= (long double)digit;
			*out++ = digit + '0';
		}
		else
			*out++ = '0';
		--prec;
	}
	return (size);
}

static void				fillres(long double nb, t_format fmt, char *out)
{
	int				size;
	int				pow;
	long double		mask;
	char			digit;
	char			*tmp;

	size = 0;
	mask = 1.0;
	pow = 0;
	if (nb < 0 || fmt->flags & FORMATF_SIGN || fmt->flags & FORMATF_BLANK)
	{
		nb = 0 - nb;
		if (nb > 0)
			out[size++] = fmt->flags & FORMATF_SIGN ? '+' : ' ';
		else
			out[size++] = '-';
	}
	while (nb / mask > 10.0 && ++pow)
		mask *= 10.0;
	digit = (char)(nb / mask);
	nb -= mask * (long double)digit;
	mask /= 10.0;
	out[size++] = digit + '0';
	if (fmt->prec > 0)
		size += ft_printradix(nb, fmt->prec, mask, out + size);
	out[size++] = 'e';
	tmp = ft_getnbr_len(pow, 1, 3, '0');
	ft_strcpy(out + size, tmp);
}

int			ft_putldouble_sci_f(long double nb, t_format fmt)
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
