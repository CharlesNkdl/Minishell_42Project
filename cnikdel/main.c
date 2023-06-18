#include "../inc/minishell.h"

int	lexer(char *str)
{
	(void)str;
	return (1);

}

// int argc, char **argv, char **envp
int main(void)
{
	char *buffer;
	char path[512];
	//Struct issu de la librairie pour stocker les infos quand on appelle stat
	struct stat oui;
	//Pointeur sur les directories
	DIR *tester;
	//Permet d'acceder aux infos sur les directories
	struct dirent *dirbuff;

	//printstrtab(argv);
	//printstrtab(envp);

	//Permet d'obtenir le path actuel
	getcwd(path, sizeof(path));
	ft_printf("%s\n",path);

	// Permet de remplir la struct stat
	stat(path, &oui);
	print_stat(oui);

	//Initialise la structure DIR
	tester = opendir(path);
	//Lit la structure DIR via une structure DIRENT
	dirbuff = readdir(tester);
	print_dirent(dirbuff);

	printf("CHDIR TRY \n \n");
	chdir(ft_strjoin(path,"/cnikdel"));
	tester = opendir(path);
	dirbuff = readdir(tester);
	print_dirent(dirbuff);
	getcwd(path, sizeof(path));
	ft_printf("%s\n",path);

	// Permet de remplir la struct stat
	stat(path, &oui);
	print_stat(oui);


	while (1)
	{
		//Demande de lire
		buffer = readline("Commande : ");
		//Permet de mettre la commande dans un historique, on peut du coup le recuperer avec les fleches dans le shell
		add_history(buffer);
		if (lexer(buffer) == 1)
			perror("Invalid Command");
		ft_printf("%s\n", buffer);
		rl_on_new_line();
	}
}
