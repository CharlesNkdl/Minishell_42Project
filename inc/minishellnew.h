#ifndef MINISHELLNEW_H
# define MINISHELLNEW_H

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

typedef enum {
    WORD = 'W',
    REDIRR = '>',
    REDIRL = '<',
    REREDIRL = 'H', // <<
    REREDIRR = 'A', // >>
	PIP = '|',
    MONEY = '$'
} SpecialChar;

typedef struct s_env
{
	char			*key;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct s_token
{
	int				i;
	char			c;
	char			*content;
	struct s_token	*next;
}					t_token;

typedef struct s_data
{
	int		fd[2];
	int		exit_status;
	int		in;
	int		out;
	int		heredoc;
	pid_t	pid;
	int		std[2];
	char	*line;
	char	**env1;
	t_env	*env;
	t_token	*token;
}				t_data;

void	ft_begin(t_data *m);
void	ft_check_parameters(t_data *m, int i);
t_env	*ft_envnode(char **envp);
t_env	*ft_new_env(char *s);
void	ft_splitok(t_data *m);
void	ft_addt(t_data *m, char c, char *s, int i);
void	ft_addtsub(t_data *m, char c, char *s, int i);
int	ft_symbol(char c);
int	nextok(t_data *m, char b);
char **strdbldup(char **str);
void	ft_init_tokens(t_data *m, int in, int out);
void	**ft_free(char **tabl, int i);
char	*ft_moneysub(t_data *m, int i, int j);
int ft_money(t_data *m, int i, int j);
int ft_dquote(t_data *m, int i);
int ft_quote(t_data *m, int i);
int ft_redir(t_data *m, int i);
int ft_pipe(t_data *m, int i);
int ft_word(t_data *m, int i);
void	ft_translator(t_data *m, int i);
void	commande(t_token *tmp, t_token *tmp2);
int		pipo(t_token *tmp, t_data *m);
int		redir(t_token *tmp, t_token *tmp2, t_data *m);
int	translate_error(t_token *tmp2, t_data *m);
int	ft_strlenmini(char *s);
char	*ft_jointok(char *s1, char *s2);
void	ft_freem(t_data *m, int i);
void	freeenv(t_env *m);
void	freetok(t_token *m);
void	**ft_free(char **tabl, int i);
void	execution(t_data *m, int i, t_token *tmp);
t_token	*exectwo(t_data *m, t_token *tmp, int i);
void	execthree(t_data *m, t_token *tmp, int i);
void	execfour(t_data *m, t_token *tmp, int i);
char	*cmdjoin(char *tmp, int	i);
char	*cmdadd(t_token *tmp, t_env *env);
int	accessor(char *s);
void	dirstat(char *s, int i);
void	verifdir(char *s, int i);
void	enfantexec(t_data *m, t_token *tmp, int i);
void	enfantexectwo(t_data *m, t_token *tmp);
void	enfantexecthree(t_data *m, t_token *tmp);
void	enfants(t_data *m, int i);
void	cmdfree(char *tmp, char **tmp1);
t_token *deltok(t_data *m, t_token *tmp, t_token *tmp2);
t_token	*exredir(t_data *m, t_token *tmp, int i, int j);
int	accessperm(char *s, char c);
int	heredocread(int i, t_data *m);
int	exredirtwo(t_token *tmp, t_data *m, int i);
void	enfantdoc(int in, char *s2);
int	heredoc(char *s2, t_data *m, int in);


#endif
