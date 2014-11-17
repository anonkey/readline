/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ulen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:26:54 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 19:41:06 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "t_format.h"

char	*ft_getnbr_ull_len(unsigned long long nbr, int width, char fill)
{
	int			size;
	static char	strout[MAX_LLSIZE + 1];
	char		*act;

	size = 0;
	act = strout + MAX_LLSIZE;
	*act-- = '\0';
	while (nbr >= 10)
	{
		*act = '0' + (char)(nbr % 10);
		--act;
		++size;
		nbr /= 10;
	}
	*act = '0' + nbr;
	while (++size <= width)
		*--act = fill;
	return (act);
}

int		ft_putnbr_ull_f(unsigned long long nbr, t_format fmt)
{
	char	*nbstr;
	char	fill;

	fill = fmt->flags & FORMATF_ZERO ? '0' : ' ';
	nbstr = ft_getnbr_ull_len(nbr, fmt->width, fill);
	if (fmt->output)
		return (ft_strlen(ft_strcpy(fmt->output, nbstr)));
	else if (fmt->allocout)
		return (ft_dynstradd(fmt->allocout, nbstr));
	return (write(fmt->fd, nbstr, ft_strlen(nbstr)));
}

int			ft_putsize_f(unsigned long long nbr, t_format fmt)
{
	char	*nbstr;
	int		len;

	nbstr = ft_getnbr_ull_len(nbr, 0, '\0');
	len = ft_strlen(nbstr);
	while (len++ < fmt->prec)
		*--nbstr = '0';
	while (len++ <= fmt->width)
		*--nbstr = ' ';
	if (fmt->output)
		return (ft_strlen(ft_strcpy(fmt->output, nbstr)));
	else if (fmt->allocout)
		return (ft_dynstradd(fmt->allocout, nbstr));
	return (write(fmt->fd, nbstr, ft_strlen(nbstr)));
}
