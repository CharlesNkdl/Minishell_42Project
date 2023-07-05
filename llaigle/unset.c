
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


typedef struct s_minishell {
	char *reader;
	char **envp;

} t_minishell;



int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}



void	ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

void    ft_unset(t_minishell *env, char *supr)
{
    int i;
    int j;
    size_t len;

    len = ft_strlen(supr);
    i = 0;
    j = 0;
    while(env->envp[i])
    {
        if(ft_strncmp(env->envp[i], supr, len) != 0) //0 = argument a supprimer trouvé
        {
            i++;
            j++;
        }
        else
        {
            free(env->envp[i]);
            i++;
            while(env->envp[i])
            {
                env->envp[i - 1] = env->envp[i];
                i++;
            }
            env->envp[i - 1] = NULL;
        }
    }
    if(j == i)
    {
        printf("%s : Cette variable n'existe pas\n", supr);
    }
}

void    ft_full_unset(t_minishell *env, char *supr[])
{
    int i;

    i = 0;
    while(supr[i])
    {
        ft_unset(env, supr[i]);
        i++;
    }
}

int main() 
{
    int i;
    t_minishell env;
    env.reader = NULL;
    env.envp = (char**)malloc(sizeof(char*) * 4);
    env.envp[0] = strdup("VAR1");
    env.envp[1] = strdup("VAR2");
    env.envp[2] = strdup("VAR3");
    env.envp[3] = NULL;

    char *variables[] = {"VAR1", "VAR4", NULL};

    ft_full_unset(&env, variables);
    //printf("cacaki");
    i = 0;
    while (env.envp[i]) {
        printf("%s\n", env.envp[i]);
        free(env.envp[i]);
        i++;
    }
    return (0);
}