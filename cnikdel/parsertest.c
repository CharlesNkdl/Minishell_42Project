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

int ft_strlenms(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[i] == '|')
		return (1);
	if (str[i] == '>' || str[i] == '<')
	{
		while (str[i] && (str[i] == '>' || str[i] == '<' ))
			i++;
		return (i);
	}
	if (str[i] == 39 || str[i] == 34)
	{
		check = (int)str[i];
		i++;
		while (str[i] && str[i] != check)
            i++;
        if (str[i] == check)
			i++;
        return (i);
	}
	while (str[i] && (str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<'))
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

t_list *token(t_minishell *mini)
{
	int len;
	int i;
	char *content;

	len = 0;
	i = -1;
	while (*mini->reader != '\0')
	{
		mini->reader = passwhite(mini->reader);
		if (*mini->reader == '\0')
			break;
		len = ft_strlenms(mini->reader);
		content = malloc(len + 1);
		if (!content)
			return (NULL);
		while (++i < len)
			content[i] = mini->reader[i];
		content[i] = '\0';
		ft_lstadd_back(&mini->head, ft_lstnew(ft_strdup(content)));
		free(content);
		mini->reader = mini->reader + len;
		i = -1;
	}
	//printLinkedList(mini->head);

	return (mini->head);
}
char  *substractquote(char *str, int check)
{
	char *buffer;
	(void)check;

	buffer = 0;
	buffer = ft_substr(str, 1, ft_strlen(str) - 1);
	free(str);
	return (buffer);
}

void	parser(t_minishell **mini)
{
	t_list *ptr;
	int	check;
	char *content;

	check = 0;
	ptr = (*mini)->head;
	while (ptr)
	{
		content = ptr->content;
		while (*content)
		{
			if (*(content) == 34 && check != 3)
				check += 1;
			if (*(content) == 39 && check != 1)
				check += 3;
			/*if (check == 1 && ptr->content == '$')
				replacethis((char *)ptr->content);*/
			content = content + 1;
		}
		if (check != 0 && (check % 2))
			perror("parsing");
		else if (check != 0)
			*(char *)(ptr->content) = *substractquote((char *)ptr->content, check);
		check = 0;
		ptr = ptr->next;
	}
	printLinkedList((*mini)->head);
}
