/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:52:59 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/14 10:50:04 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static size_t	ft_compute_nbsize(int nb)
{
	if (nb / 10 == 0)
		return (1);
	return (1 + ft_compute_nbsize(nb / 10));
}

char			*ft_getnbr(int n)
{
	size_t		size;
	int			neg;
	static char	nbstr[MAX_INTSIZE];

	neg = (n < 0) ? 1 : 0;
	size = neg + ft_compute_nbsize(n);
	if (neg == 1)
		nbstr[0] = '-';
	while (size-- > (size_t)neg)
	{
		nbstr[size] = '0' + (char)((neg) ? (0 - n % 10) : (n % 10));
		n /= 10;
	}
	return (nbstr);
}
int		ft_putnbr(int n)
{
	char	*nbstr;

	nbstr = ft_getnbr(n);
	return (write(1, nbstr, ft_strlen(nbstr)));
}
