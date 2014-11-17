/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ulen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:26:54 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/14 10:54:54 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_getnbr_ulen(unsigned long long nbr, int width, char fill)
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


int		ft_putnbr_ulen(unsigned long long nbr, int width, char fill)
{
	char	*nbstr;

	nbstr = ft_getnbr_ulen(nbr, width, fill);
	return (write(1, nbstr, ft_strlen(nbstr)));
}
