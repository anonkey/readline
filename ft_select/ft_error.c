/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 05:34:37 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/13 14:21:29 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_error.h"
#define TAB_ERR_SIZE 13

void			ft_perror(const char *prog, const char *s, int errnum, int type)
{
	const char	*error;

	(void)error;
	if (errnum >= TAB_ERR_SIZE)
		errnum = 0;
	if (prog)
	{
		ft_putstr_fd(prog, 2);
		ft_putstr_fd(" : ", 2);
	}
	ft_putstr_fd("error", 2);
	if (s)
	{
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(s, 2);
	}
	ft_putstr_fd("\n", 2);
	if (type % 2 == 0)
		exit(1);
}
