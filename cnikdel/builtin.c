#include "../inc/minishell.h"

void    ft_builtins(t_minishell *mini)
{
    char    *path = ft_strjoin("/bin/", (char *)mini->head->content);
    char    *str[4] = {mini->head->content,mini->head->next->content,mini->head->next->next->content, NULL};

	pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execve(path, str, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Le processus fils s'est terminé avec le code de sortie : %d\n", exit_status);
        }
    }

    free(path);
}
