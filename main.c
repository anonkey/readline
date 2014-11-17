#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"
#ifdef _POSIX_MAX_CANON
# define SHELL_CANON_MAX (_POSIX_MAX_CANON * 8)
#else
# define SHELL_CANON_MAX 4096
#endif
#define SHELL_RLINE_MAX SHELL_CANON_MAX
#define DELETE_CHAR '\127'
#define NEWLINE_CHAR '\n'

char	*ft_getenv(const char *name, char **env)
{
	int		i;
	char	*ret;
	size_t	namelen;

	i = 0;
	if (!env || !name)
		return (NULL);
	namelen = ft_strlen(name);
	while (env[i] && (ft_strncmp(env[i], name, namelen)
						|| env[i][namelen] != '='))
		++i;
	ret = env[i] ? ft_strdup(env[i] + namelen + 1) : NULL;
	return (ret);
}

char	*ft_basic_readline(char *prompt)
{
	ssize_t		readl;
	char		buff[SHELL_CANON_MAX + 1];

	ft_bzero(buff, SHELL_CANON_MAX + 1);
ft_putstr("CANON");
	ft_putstr(prompt);
	readl = read(0, buff, SHELL_CANON_MAX);
	return (ft_strdup(buff));
}

char	*ft_nonblock_readline(char *prompt)
{
	ssize_t		readl;
	ssize_t		total;
	char		tmp;
	char		buff[SHELL_RLINE_MAX + 1];

	ft_bzero(buff, SHELL_RLINE_MAX + 1);
ft_putstr("RLINE");
	ft_putstr(prompt);
	total = 0;
	errno = 0;
	while ((-1 < (readl = read(0, &tmp, 1)) || errno == EAGAIN)
			&& tmp != NEWLINE_CHAR)
	{
		if (readl > 0)
		{
			if (tmp == DELETE_CHAR)
				buff[--total] = '\0';
			else if (total < SHELL_RLINE_MAX)
				buff[total++] = tmp;
			else
				ft_putchar(DELETE_CHAR);
		}
	};
	return (ft_strdup(buff));
}

char	*ft_readline(char *prompt, char *term)
{
	int				flags;

	if (!term || term)
	{
		if (!isatty(0) || -1 == (flags = fcntl(0, F_GETFL, 0))
			|| -1 == fcntl(0, F_SETFL, flags | O_NONBLOCK))
			return (ft_basic_readline(prompt));
		else
			return (ft_nonblock_readline(prompt));
	}
}

int		main(int argc, char **argv, char **envp)
{
	char	*dflprompt = "42sh>";
	char	*termcap;

	termcap = ft_getenv("TERM", envp);
	ft_putendl(ft_readline(argc > 1 ? argv[1] : dflprompt, termcap));
	return (0);
}
