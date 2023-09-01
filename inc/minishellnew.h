/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellnew.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:25:11 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 03:31:30 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLNEW_H
# define MINISHELLNEW_H

# include "../Libft/Headers/ft_printf.h"
# include "../Libft/Headers/get_next_line_bonus.h"
# include "../Libft/Headers/libft.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

extern int			g_sigvar;

typedef enum e_specialchar
{
	WORD = 'W',
	REDIRR = '>',
	REDIRL = '<',
	REREDIRL = 'H',
	REREDIRR = 'A',
	PIP = '|',
	MONEY = '$'
}					t_specialchar;

typedef struct s_exc
{
	char			*path;
	char			**argv;
	char			**envp;
}					t_exc;

typedef struct s_ntr
{
	int				opt;
	char			**s;
	int				i;
	int				len;
	int				n;
}					t_ntr;

typedef struct s_bez
{
	char			*new;
	char			*tmp2;
	char			**tmp1;
	char			**tmp3;
	char			*tmp4;
	int				i;
}					t_bez;

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
	int				fd[2];
	int				exit_status;
	int				in;
	int				out;
	int				heredoc;
	pid_t			pid;
	int				std[2];
	char			*line;
	char			**env1;
	t_env			*env;
	t_token			*token;
}					t_data;

void				*ft_begin(t_data *m);
void				ft_check_parameters(t_data *m, int i);
t_env				*ft_envnode(char **envp);
t_env				*ft_new_env(char *s);
void				ft_splitok(t_data *m);
void				ft_addt(t_data *m, char c, char *s, int i);
void				ft_addtsub(t_data *m, char c, char *s, int i);
int					ft_symbol(char c);
int					nextok(t_data *m, char b);
char				**strdbldup(char **str);
void				ft_init_tokens(t_data *m, int in, int out);
void				**ft_free(char **tabl, int i);
char				*ft_moneysub(t_data *m, int i, int j);
int					ft_money(t_data *m, int i, int j);
int					ft_dquote(t_data *m, int i);
int					ft_quote(t_data *m, int i);
int					ft_redir(t_data *m, int i);
int					ft_pipe(t_data *m, int i);
int					ft_word(t_data *m, int i);
void				ft_translator(t_data *m, int i);
void				commande(t_token *tmp, t_token *tmp2);
int					pipo(t_token *tmp, t_data *m);
int					redir(t_token *tmp, t_token *tmp2, t_data *m);
int					translate_error(t_token *tmp2, t_data *m);
int					ft_strlenmini(char *s);
char				*ft_jointok(char *s1, char *s2);
void				ft_freem(t_data *m, int i);
void				freeenv(t_env *m);
void				freetok(t_token *m);
void				**ft_free(char **tabl, int i);
void				execution(t_data *m, int i, t_token *tmp);
t_token				*exectwo(t_data *m, t_token *tmp, int i);
void				execthree(t_data *m, t_token *tmp, int i);
void				execfour(t_data *m, t_token *tmp, int i);
char				*cmdjoin(char *tmp, int i);
char				*cmdadd(t_token *tmp, t_env *env);
int					accessor(char *s);
void				dirstat(t_data *m, char *s, int i);
void				verifdir(t_data *m, char *s, int i);
void				enfantexec(t_data *m, t_token *tmp, int i);
void				enfantexectwo(t_data *m, t_token *tmp);
void				enfantexecthree(t_data *m, t_token *tmp, t_exc args);
void				enfants(t_data *m, int i);
void				cmdfree(char *tmp, char **tmp1);
t_token				*deltok(t_data *m, t_token *tmp, t_token *tmp2);
t_token				*exredir(t_data *m, t_token *tmp, int i, int j);
int					accessperm(char *s, char c);
int					heredocread(int i, t_data *m);
int					exredirtwo(t_token *tmp, t_data *m, int i);
void				enfantdoc(t_data *m, int in, char *s2);
int					heredoc(char *s2, t_data *m, int in);
void				init_signals(int boule);
void				signal_handler(int sig);
void				free_arr(char **array);
void				ft_inifir(t_data *m, int in, int out);
void				ft_builtins(t_data *m, t_token *tmp);
int					ft_cd(t_data *m, t_token *tmp);
int					ft_pimp_strncmp(char *s);
void				ft_echo(t_data *m, t_token *tok);
void				ft_env(t_data *m);
int					ft_str_isdigit(char *s);
void				ft_exit(t_data *m, t_token *tok);
void				ft_export(t_data *m, t_token *tok);
void				ft_export_solo(t_data *m);
int					ft_verif_key(char *s, t_data *m);
void				ft_change_content(char **s, t_data *m);
void				ft_do_export(t_data *m, t_token *tok);
t_data				*ft_gugugaga(char *s, t_data *m);
char				**ft_stock(char *s);
void				ft_pwd(t_data *m);
int					ft_strcmp(char const *s1, char const *s2);
void				ft_unset(t_data *m, char *supr);
int					ft_verif_unset(char *s, t_data *m);
void				ft_full_unset(t_data *m, t_token *supr);
int					ft_cdpip(t_data *m, t_token *tmp);
void				ft_exportpip(t_data *m, t_token *tok);
void				ft_full_unsetpip(t_data *m, t_token *supr);
void				*ft_envdd(t_data *m, int i);
int					ft_llstsize(t_env *lst);
int					ft_verif_export(char *s);
int					checkbuiltstwo(t_data *m, t_token *tmp);
void				dirstattwo(t_data *m, char *s, int i,
						struct stat path_stat);
int					heredoctwo(t_data *m, char *s2, int in, int pid);
void				reset_init(t_exc *args);
void				exc_init(t_data *m, t_token *tmp, t_exc *args, int mode);
void				ft_exittwo(t_data *m, char **s, int i);
t_env				*initee(char **str);
void				*ft_ntr(char **str, t_env *tmp2, t_env *tmp,
						t_env *newnode);
int					checkbuilts(t_data *m);

#endif
