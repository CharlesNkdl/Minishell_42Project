# Consignes Minishell et Recherche

## 1. Decomposition du sujet

Le projet nous amenes a travailler sur la mise au point d'un Shell fonctionnel en C.

### a) ***Histoire***

Le Shell, aussi appelle l'interface systeme est celui qui fourni l'interface utilisateur du systeme d'exploitation. C'est la couche la plus externe et nous permet de communiquer avec le systeme d'exploitation.

Il y a le kernel = Le Noyau = Le systeme d'exploitation
Le Shell = la coquille qui est autour du Noyau

Il peut prendre 2 formes = soit un terminal, qui prends comme argument des lignes de commandes(CLI) qui permet de tout gerer via le clavier
Ou de type graphique avec une GUI type windows

Il y a beaucoup de Shell/Interface systeme qui ont ete ecrit et utiliser
ex : Powershell pour windows qui utilise une autre syntaxe et une autre logique

Le sujet nous demande de prendre Bash pour reference pour le sujet, nous allons nous concentrer dessus + nous avons plus d'experience sur celui la dans tout les cas.

### b) ***Bash - Bourne Again Shell***

Le Bash ou Bourne Again Shell, est le Shell Unix du projet GNU, fait par Brian Fox et publie en 1989.

Il execute 4 fonctions fondamentales :

1. Une liste de commandes pour operer sur l'ordinateur
2. La possibilite de faire des fichiers executables de liste de commandes
3. Un parsing de la commande pour relancer sur les erreurs
4. Chaque ligne correcte est alors interpreter et lancer

Bash peut aussi faire de la gestion de flux => Il peut transmettre le resultat d'un script a un autre ce qui permet de chainer les commandes (ls | grep "*.c" | wc -l par exemple)

### c) ***Fonctionnement technique general***

