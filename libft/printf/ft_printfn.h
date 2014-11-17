#ifndef FT_PRINTFN_H
# define FT_PRINTFN_H
# include "ft_printfarg.h"
# define NB_PRINT_FN 5

int					ft_printf_float(t_printf_arg *arg,
								char *format, va_list *args_p);

int					ft_printf_char(t_printf_arg *arg,
								char *format, va_list *args_p);

int					ft_printf_str(t_printf_arg *arg,
									char *format, va_list *args_p);

int					ft_printf_point(t_printf_arg *arg,
								char *format, va_list *args_p);

int					ft_printf_integer(t_printf_arg *arg,
									char *format, va_list *args_p);

#endif
