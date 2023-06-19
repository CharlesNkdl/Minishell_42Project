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

t_token *token(char *str)
{
	str = passwhite(str);
	int result = stupid(str);
	printf ("result %c \n", result);
	if (str)
		return (NULL);
	return (NULL);
}
