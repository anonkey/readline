/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:29:24 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/14 15:09:42 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char			*ft_getnbr_len(long long nbr, int sign, int width, char fill)
{
	int			size;
	static char	strout[MAX_LLSIZE + 1] = {'\0'};
	char		*act;

	size = 1;
	act = strout + MAX_LLSIZE;
	if (nbr < 0 || sign)
	{
		if (sign == ' ')
			sign = nbr < 0 ? '-' : ' ';
		else
			sign = nbr < 0 ? '-' : '+';
		++size;
		nbr = nbr > 0 ? nbr : 0 - nbr;
	}
	while (nbr >= 10)
	{
		*act-- = '0' + (char)(nbr % 10);
		nbr /= 10;
		++size;
	}
	*act = '0' + nbr;
	if (sign && fill != '0')
		*--act = (char)sign;
	while (++size <= width)
		*--act = fill;
	if (sign && fill == '0')
		*--act = (char)sign;
	return (act);
}

int			ft_putnbr_len(long long nbr, int sign, int width, char fill)
{
	char	*nbstr;

	nbstr = ft_getnbr_len(nbr, sign, width, fill);
	return (write(1, nbstr, ft_strlen(nbstr)));
}
