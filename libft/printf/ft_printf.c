/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:31:45 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 21:54:51 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_readarg.h"
#include "libft.h"

int		ft_printf(char *format, ...)
{
	va_list			args;
	int				index;
	ULONG			size;
	t_printf_arg	arg;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
			arg = ft_getarg(&index, format);
			arg.fd = 1;
			size += ft_printarg(arg, format, &args);
		}
		else
		{
			ft_putchar(format[index++]);
			++size;
		}
	}
	va_end(args);
	return (size);
}

int		ft_asprintf(char **out_p, char *format, ...)
{
	va_list			args;
	int				index;
	char			tmp[2];
	t_printf_arg	arg;
	t_dynstr		output;

	index = 0;
	tmp[1] = '\0';
	if (!format || !out_p)
		return (-1);
	if (!(output = ft_dynstrnew(1024)))
		return (-2);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
			arg = ft_getarg(&index, format);
			arg.allocout = output;
			if (0 > ft_printarg(arg, format, &args))
				return (-3);
		}
		else
		{
			*tmp = format[index++];
			if (0 > ft_dynstradd(output, tmp))
				return (-3);
		}
	}
	*out_p = ft_dynstrflush(output);
	ft_dynstrdel(&output);
	va_end(args);
	return (ft_strlen(*out_p));
}

int		ft_sprintf(char *out, char *format, ...)
{
	va_list			args;
	int				index;
	ULONG			size;
	t_printf_arg	arg;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
				arg = ft_getarg(&index, format);
				arg.output = out + size;
				size += ft_printarg(arg, format, &args);
		}
		else
		{
			out[size++] = format[index++];
		}
	}
	out[size] = '\0';
	va_end(args);
	return (size);
}

int		ft_dprintf(int fd, char *format, ...)
{
	va_list			args;
	int				index;
	ULONG			size;
	t_printf_arg	arg;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
				arg = ft_getarg(&index, format);
				arg.fd = fd;
				size += ft_printarg(arg, format, &args);
		}
		else
			size += write(fd, format + index++, 1);
	}
	va_end(args);
	return (size);
}
