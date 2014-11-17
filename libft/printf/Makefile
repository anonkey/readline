
ifeq ($(GCC), 1)
    CC = gcc
else
    CC = clang
endif
ifeq ($(DEBUG), 1)
    CFLAGS = -Wall -Wextra -Werror -ggdb3
else
    CFLAGS = -Wall -Wextra -Werror
endif
NAME = printfgit
INCDIR = ./libft/headers
LIBDIR = ./libft
LIBNAME = libft
LIB = -lft
SRC = ft_printf.c \
ft_printfn.c \
ft_readarg.c \
ft_readautom.c \
ft_readchar.c \
ft_readfloat.c \
ft_readfloat_len.c \
ft_readint.c \
ft_readint_len.c \
ft_readpoint.c \
ft_readstr.c \
main.c
OBJ = $(SRC:.c=.o)

all: $(LIBNAME) $(NAME)

$(LIBNAME):
	make -C $(LIBDIR)

$(LIBNAME)_fclean:
	make -C $(LIBDIR) fclean

gcc: $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INCDIR) -L $(LIBDIR) -lft $(OBJ) -o $(NAME)
%.o: %.c
	$(CC) -I $(INCDIR) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: $(LIBNAME)_fclean clean
	rm -rf $(NAME)

re: $(LIBNAME)_fclean fclean all

.PHONY: $(LIBNAME) $(LIBNAME)_fclean clean fclean all re