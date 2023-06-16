#include "../inc/minishell.h"

int	lexer(char *str)
{
	(void)str;
	return (1);

}
int main(void)
{
	char *buffer;
	char path[512];
	struct stat oui;
	DIR *tester;
	struct dirent *dirbuff;

	//printstrtab(argv);
	getcwd(path, sizeof(path));
	ft_printf("%s\n",path);
	stat(path, &oui);
	print_stat(oui);


	tester = opendir(path);
	dirbuff = readdir(tester);
	print_dirent(dirbuff);




	while (1)
	{
		buffer = readline("Commande : ");
		add_history(buffer);
		if (lexer(buffer) == 1)
			perror("Invalid Command");
		ft_printf("%s\n", buffer);
		rl_on_new_line();
	}
}
