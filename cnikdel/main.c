#include "../inc/minishell.h"

int	lexer(char *str)
{
	(void)str;
	return (1);

}

// int argc, char **argv, char **envp
int main(int argc, char **argv, char **envp)
{
	char *buffer;
	(void) argc;
	(void) argv;

	printstrtab(envp);


	/*

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


	//On test un cd
	printf("\n \n CHDIR TRY \n \n");
	//ca prends comme arguments un path, du coup vu que je veux changer de directory, je fais un join avec un nom de fichier
	chdir(ft_strjoin(path,"/cnikdel")); //c'est un changement RELATIF pck on ajoute juste un truc(genre cd cnikdel)
	//je recommence tout et je compare
	getcwd(path, sizeof(path));
	ft_printf("AFTER CWD %s\n",path);
	tester = opendir(path);
	dirbuff = readdir(tester);
	print_dirent(dirbuff);
	stat(path, &oui);
	print_stat(oui);


	printf("\n \n CHDIR ABSOLU TRY \n \n");
	printf("trimmed : %s \n", ft_strtrim(path, "/cnikdel"));
	chdir(ft_strjoin("/",ft_strtrim(path, "/cnikdel"))); //c'est un changement ABSOLU pck on ajoute tout le chemin
	//Bon le strjoin avec un strtrim c'est moche de ouf, mais c'est juste que du coup ca retirer aussi le premier / mdr, c'est juste des tests
	//je recommence tout et je compare
	getcwd(path, sizeof(path));
	ft_printf("AFTER CWD %s\n",path);
	tester = opendir(path);
	dirbuff = readdir(tester);
	print_dirent(dirbuff);
	stat(path, &oui);
	print_stat(oui);

	*/
	while (1)
	{
		//Demande de lire
		buffer = readline("Commande : ");
		//Permet de mettre la commande dans un historique, on peut du coup le recuperer avec les fleches dans le shell
		add_history(buffer);
		token(buffer);
		//if (lexer(buffer) == 1)
			//perror("Invalid Command");
		//ft_printf("%s\n", buffer);
		rl_on_new_line();
	}
}
