/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 11:28:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 19:39:02 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "t_format.h"

char		*ft_getnbr_base(unsigned long long nb, char *base,
							unsigned int baselen)
{
	static char	buff[MAX_ULL_BIN_SIZE + 3];
	char		*act;

	act = buff + MAX_ULL_BIN_SIZE;
	*act-- = '\0';
	while ((nb >= baselen))
	{
		*act-- = base[nb % baselen];
		nb /= baselen;
	}
	*act = base[nb];
	return (act);
}

int			ft_putnbr_base_f(unsigned long long nbr, char *base, t_format fmt)
{
	char			*res;
	char			fill;
	int				len;

	fill = fmt->flags & FORMATF_ZERO ? '0' : ' ';
	res = ft_getnbr_base(nbr, base, ft_strlen(base));
	len = ft_strlen(res);
	if (fmt->flags & FORMATF_ALT)
	{
		len += 2;
		if (fill == ' ')
			ft_strncpy((res -= 2), "0x", 2);
	}
	while ((int)len++ < fmt->width)
		*--res = fill;
	if ((fmt->flags & FORMATF_ALT) && fill == '0')
			ft_strncpy((res -= 2), "0x", 2);
	if (fmt->output)
		return (ft_strlen(ft_strcpy(fmt->output, res)));
	else if (fmt->allocout)
		return (ft_dynstradd(fmt->allocout, res));
	return (write(fmt->fd, res, ft_strlen(res)));
}

int			ft_putsize_base_f(unsigned long long nbr, char *base, t_format fmt)
{
	char			*res;
	int				len;

	res = ft_getnbr_base(nbr, base, ft_strlen(base));
	len = ft_strlen(res);
	if (fmt->flags & FORMATF_ALT)
		len += 2;
	while ((int)len++ < fmt->prec)
		*--res = '0';
	if (fmt->flags & FORMATF_ALT)
			ft_strncpy((res -= 2), "0x", 2);
	while ((int)len++ <= fmt->width)
		*--res = ' ';
	if (fmt->output)
		return (ft_strlen(ft_strcpy(fmt->output, res)));
	else if (fmt->allocout)
		return (ft_dynstradd(fmt->allocout, res));
	return (write(fmt->fd, res, ft_strlen(res)));
}
