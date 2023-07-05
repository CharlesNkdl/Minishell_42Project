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

/* COMMAND = commande
	ARG = arg type -n
	CONTENT = ce qu'il y a ecrit
	quote = 0 pas de quote, 1 single, 2 double
	order = si c'est la commande 0 , 1, 2 ....
	pour le reste : 0 = pas present, 1 = present */
typedef struct s_token {
	char *command;
	char *arg;
	char *content;
	int quote;
	unsigned int order;
	int	pipeleft;
	int	piperight;
	int redirleft;
	int reredirleft;
	int redirright;
	int reredirright;
	struct s_token *next;
} t_token;

typedef struct s_minishell {
	char *reader;
	char **envp;
	t_list *head;


} t_minishell;

void	printstrtab(char **str);
void print_stat(struct stat st);
void print_dirent(struct dirent *entry);
t_list *token(t_minishell *str);
void	free_tok(t_list **bucket);
void    ft_builtins(t_minishell *mini);
void printLinkedList(t_list *head);
void	parser(t_minishell **mini);
void	**ft_free(char **tabl, int i);
char **strdbldup(char **str);

#endif
