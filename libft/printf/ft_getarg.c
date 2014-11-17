#include <stdlib.h>
#include "ft_readarg.h"
#include "libft.h"

t_printf_arg	ft_getarg(int *index_p, char *format)
{
	t_printf_arg	arg;

	arg.output = NULL;
	arg.fd = 1;
	if (-1 == (arg.flags = ft_readflags(index_p, format)))
		arg.state = STATE_ERROR;
	else if (-1 == (arg.width = ft_readwidth(index_p, format)))
		arg.state = STATE_ERROR;
	else if (-2 == (arg.prec = ft_readprec(index_p, format)))
		arg.state = STATE_ERROR;
	else if (-1 == ft_readtype(&arg, index_p, format))
		arg.state = STATE_ERROR;
	arg.fd = 1;
	arg.output = NULL;
	arg.allocout = NULL;
	return (arg);
}
