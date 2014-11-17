#include "ft_printfarg.h"

int				ft_printarg(t_printf_arg arg, char *format, va_list *args_p)
{
	t_printfn	*printfunc;

	if (arg.state == STATE_ERROR)
		return (-1);
	if (!(printfunc = ft_getprint_fn(arg.type)))
		return (0);
	return (printfunc->print(&arg, format, args_p));
}
