
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

int		stupid(char *str)
{
	if (ft_strnstr(str, "echo", 4))
	{
		if (ft_strnstr(passwhite(str + 5),"-n", 2))
			return 'N';
		else
			return 'E';
	}
	if (ft_strnstr(str, "cd", 4))
		return 'C';
	if (ft_strnstr(str, "pwd", 3))
		return 'P';
	if (ft_strnstr(str, "export", 6))
		return 'X';
	if (ft_strnstr(str, "unset", 5))
		return 'U';
	if (ft_strnstr(str, "env", 3))
		return 'V';
	if (ft_strnstr(str, "exit", 4))
		return 'Z';
	else
		return (0);
}

void printList(t_token *head)
{
    t_token *current = head;

    while (current != NULL)
    {
        printf("Command: %s\n", current->command);
        printf("Argument: %s\n", current->arg);
        printf("Content: %s\n", current->content);
        printf("Quote: %d\n", current->quote);
        printf("Order: %d\n", current->order);
        printf("Pipe Left: %d\n", current->pipeleft);
        printf("Pipe Right: %d\n", current->piperight);
        printf("Redirect Left: %d\n", current->redirleft);
        printf("Double Redirect Left: %d\n", current->reredirleft);
        printf("Redirect Right: %d\n", current->redirright);
        printf("Double Redirect Right: %d\n", current->reredirright);

        current = current->next;
    }
}

t_token *init(t_token *yes)
{
	yes = malloc(sizeof(t_token));
	if (!yes)
		return (NULL);
	yes->command = NULL;
	yes->arg = NULL;
	yes->content = NULL;
	yes->quote = 0;
	yes->order = 0;
	yes->pipeleft = 0;
	yes->piperight = 0;
	yes->redirleft = 0;
	yes->reredirleft = 0;
	yes->redirright = 0;
	yes->reredirright = 0;
	yes->next = NULL;
	return (yes);
}
