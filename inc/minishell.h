#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/Headers/ft_printf.h"
# include "../Libft/Headers/get_next_line_bonus.h"
# include "../Libft/Headers/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <termios.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <term.h>
# include <curses.h>
# include <limits.h>

typedef struct s_token {
	char token;
	char *content;
	unsigned int order;
	struct s_token *next;
} t_token;

void	printstrtab(char **str);
void print_stat(struct stat st);
void print_dirent(struct dirent *entry);
t_token *token(char *str);

#endif
