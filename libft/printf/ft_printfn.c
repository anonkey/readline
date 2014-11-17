/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:30:42 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/14 13:46:28 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printfn.h"
#include "libft.h"

t_printfn	g_printfn_tab[NB_PRINT_FN] =
{
	{"diouxX", &ft_printf_integer},
	{"s", &ft_printf_str},
	{"c", &ft_printf_char},
	{"p", &ft_printf_point},
	{"fe", &ft_printf_float}
};

t_printfn	*ft_getprint_fn(char c)
{
	int		i;

	i = 0;
	while (i < NB_PRINT_FN)
	{
		if (ft_strchr(g_printfn_tab[i].types, c))
			return (&(g_printfn_tab[i]));
		++i;
	}
	return (NULL);
}
