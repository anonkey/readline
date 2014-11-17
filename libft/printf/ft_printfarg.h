#ifndef FT_PRINTFARG_H
# include <stdarg.h>
# include "ft_dynstr.h"
# define FT_PRINTFARG_H
# define PRINTF_HLEN 1
# define PRINTF_HHLEN 2
# define PRINTF_LLEN 3
# define PRINTF_LLLEN 4
# define PRINTF_DLLEN 5
# define PRINTF_ZLEN 6
# define STATE_ERROR -1
# define STATE_START 0
# define STATE_HLEN 1
# define STATE_HHLEN 2
# define STATE_LLEN 3
# define STATE_LLLEN 4
# define STATE_DLLEN 5
# define STATE_ZLEN 6
# define STATE_END 7

typedef struct		s_printf_arg
{
	char			*output;
	t_dynstr		allocout;
	int				fd;
	char			flags;
	int				width;
	int				prec;
	char			type;
	int				len;
	int				state;
	char			act;
}					t_printf_arg;

typedef int			(*t_printfunc)(t_printf_arg *, char *format, va_list *);

typedef struct		s_printfn
{
	char			*types;
	t_printfunc		print;
}					t_printfn;

t_printf_arg		ft_getarg(int *index_p, char *format);

t_printfn			*ft_getprint_fn(char c);

int					ft_printarg(t_printf_arg arg, char *format,
								va_list *args_p);

#endif
