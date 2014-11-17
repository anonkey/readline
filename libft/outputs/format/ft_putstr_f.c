/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:50:31 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 21:46:14 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_format.h"
#include "libft.h"

static int		ft_putnull_f(t_format fmt)
{
	int		i;

	i = 7 > fmt->prec ? fmt->prec : 7;
	if (!fmt->output)
		return (write(1, "(NULL)", i));
	else if (fmt->allocout)
		return (ft_dynstradd_len(fmt->allocout, "(NULL)", i));
	ft_strncpy(fmt->output, "(NULL)", i);
	fmt->output[i] = '\0';
	return (i);
}

int				ft_putstr_f(char const *s, t_format fmt)
{
	unsigned long	size;
	int				i;
	char			fill;

	fill = fmt->flags & FORMATF_ZERO ? '0' : ' ';
	i = 0;
	if (!s)
		return (ft_putnull_f(fmt));
	size = ft_strlen(s);
	if (fmt->prec > 0)
		size = ((long)size > fmt->prec) ? (unsigned long)fmt->prec : size;
	if ((long)size < fmt->width)
	{
		while ((long)size + i < fmt->width)
		{
			if (fmt->output)
				fmt->output[i] = fill;
			else if (fmt->allocout)
				ft_dynstradd_len(fmt->allocout, &fill, 1);
			else
				write(fmt->fd, &fill, 1);
			++i;
		}
	}
	if (fmt->output)
		return (i + ft_strlen(ft_strncpy(fmt->output + i, s, size)));
	else if (fmt->allocout)
		return (ft_dynstradd_len(fmt->allocout, (char *)s, size));
	return (i + write(fmt->fd, s, size));
}
