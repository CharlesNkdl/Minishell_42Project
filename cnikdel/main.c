#include "../inc/minishell.h"

int	lexer(char *str)
{
	(void)str;
	return (1);

}

int main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	(void)argv;

	mini = malloc(sizeof(t_minishell));
	mini->reader = NULL;
	mini->envp = envp;
	mini->head = NULL;
	if (argc != 1)
	{
		printf("no arg \n");
		return (0);
	}

	while (1)
	{
		//Demande de lire
		mini->reader = readline("Commande : ");
		//Permet de mettre la commande dans un historique, on peut du coup le recuperer avec les fleches dans le shell
		add_history(mini->reader);
		token(mini);
		free_tok(&mini->head);
		//if (lexer(buffer) == 1)
			//perror("Invalid Command");
		//ft_printf("%s\n", buffer);
		rl_on_new_line();
	}
}
