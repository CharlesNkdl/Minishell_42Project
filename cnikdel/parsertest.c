#include "../inc/minishell.h"

/* Je dois essayer de faire un parsing de qualite sachant que c'est sensible a la casse
pour l'instant au plus simple et stocker les tokens de commandes
Comment stocker tout  ? Dans une linked list ?
Dans une grande struct avec des tokens ?

qq fonctions d'aide me viennent a l'esprit pour la suite:
	-Un strtrim mais que de la fin, pour gerer le path plus facilement
	-Un strjoin qui rajoute direct le / pour faire le path sans besoin de modif les strings
	-Un parsing de base automatisee pour la casse
	-Un count words, a la ft split => peut etre juste un ft_split mais du coup faire attention a tab/espace => un ftsplit a double param mais aussi qui s'annule avec quote
*/

/* On va commencer simplement, reussir a avoir le premier mot, en sortir un token*/



/* Pour servir de token simplement, on va faire
	E = echo
	N = echo -n
	C = cd
	P = pwd
	X = export
	U = unset
	V = env
	Z = exit */

/*on va y aller comme un debile pour le moment*/

char *passwhite(char *str)
{
	while (*str && (*str == ' ' || *str== 9))
		str++;
	return (str);
}

char *password(char *str)
{
	while (*str && (*str != ' '))
		str++;
	return (str);
}

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

int ft_strlenms(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] != ' '))
		i++;
	return (i);
}
void printLinkedList(t_list *head)
{
	t_list *current = head;

	while (current != NULL)
	{
		printf("%s ", (char *)(current->content));
		current = current->next;
	}

	printf("\n");
}
t_token *token(char *str)
{
	//t_token *oui;
	int len;
	int order;
	int i = -1;
	t_list *head;
	char *content;

	head = NULL;
	order = 0;
	len = 0;
	/*oui = NULL;
	oui = init(oui);
	printList(oui);*/
	while (*str != '\0')
	{
		str = passwhite(str);
		if (*str == '\0')
			break;
		len = ft_strlenms(str);
		printf("%d \n", len);
		content = malloc(len + 1);
		while (++i < len)
			content[i] = str[i];
		content[i] = '\0';
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(content)));
		free(content);
		str = str + len;
		i = -1;
		order++;
	}
	printLinkedList(head);
	printf("%d" , ft_lstsize(head));
	if (str)
		return (NULL);
	return (NULL);
}
