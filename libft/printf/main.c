/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:10:45 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 21:57:22 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	long	a;
	size_t	toto;
	char	*buff;
	//char	buff[256];

	toto = 283932;
	a = 1000000;
	//printf(" \n A%dA", ft_printf("\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %10zo  |%7.6zx| %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x1F0UL, 12.42, 1.11111111, 1113.14127));
	//printf(" \n A%dA", printf("\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %10zo  |%7.6zx| %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x1F0UL, 12.42, 1.111111111, 1113.14127));
	//ft_printf("\n %p \n", NULL);
	//printf("\n %p \n", NULL);
	//printf(" \n A%dA", ft_sprintf(buff, "\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %10zo  |%7.6zx| %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x1F0UL, 12.42, 1.11111111, 1113.14127));
	//ft_putendl(buff);
	//printf(" \n A%dA", sprintf(buff, "\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %10zo  |%7.6zx| %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x1F0UL, 12.42, 1.111111111, 1113.14127));
	//ft_putendl(buff);
printf(" \n A%dA\n\n", ft_asprintf(&buff, "\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %10zo  |%7.6zx| %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x100UL, 12.42, 1.11111111, 1113.14127));
	ft_putendl(buff);
	printf(" \n A%dA\n\n", asprintf(&buff, "\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %10zo  |%7.6zx| %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x100UL, 12.42, 1.11111111, 1113.14127));
	ft_putendl(buff);
	return (0);
}
