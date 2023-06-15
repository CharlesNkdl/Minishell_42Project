# Consignes Minishell et Recherche

## 1. ***Kezako le Shell***

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

Bash utilise la bibliotheque Readline (cf plus tard)
Pour interpreter une lignem bash commence par la segmenter en mots.
Le premier mot doit forcement etre une commande, on place les arguments/parametres a la suite puis les options(introduit par -, ex -rf), sans espace.

Voici les contraintes d'interpretation des commandes :

1. Le premier mot doit etre une commande
2. Chaque mot est separer par un OU plusieurs caractère de separation, bash considere les tabulations et les espaces comme caractère de separation.
3. la fin de commande est marque par ; (pour faire plusieurs commandes)(non demandes dans le sujet) ou un retour a la ligne

Il y a aussi des metacaracteres au niveau du shell, ce sont des caracteres qui represente autre chose que leurs valeurs litterales, il y a deux types ceux de substitution :

1. le * pour servir de wildcard = Bonus pour le sujet
2. le ? qui est un caractère quelconque

Et ensuite ceux de protection :

1. le \ qui empeche l'interpretation d'un metacaracteres
2. les ` , guillements inverses, qui interprete la chaine de caractère comme une commande
3. les ', qui permet d'interpreter comme texte tout ceux qui est ecrit entre les deux guillemets

Plus de precisions sont necessaires sur le \ :

Un antislash a la fin d'un ligne indique que la commande continue sur la ligne suivante
Elle permet aussi de former les caracteres speciaux de l'ASCII
On peut aussi le mettre avant un metacaracteres comme dit precedemment

### d) ***La gestion de flux***

Comme dit avant, une des choses qui rend le shell aussi bon, est la gestion de flux.
Chaque commande est associes a trois flux :

1. stdin : l'entree (0)
2. stdout : l'entree (1)
3. stderr : l'entree (2)

Il y a aussi la possibilite d'ajouter des descripteurs de fichiers supplementaires

Voici divers examples :

1. A > fichier :
   - sortie (>)
     - Exécute la commande A et redirige sa sortie standard (stdout) dans fichier en écrasant son contenu ou en créant fichier si celui-ci n'existe pas
2. A >> fichier :
   - sortie (>>)
     - Exécute la commande A et redirige sa sortie standard à la fin de fichier
3. A 2> fichier :
   - sortie (2>)
     - Exécute la commande A et redirige sa sortie standard des erreurs (stderr) dans fichier en écrasant son contenu ou en créant fichier si celui-ci n'existe pas
4. A 2>> fichier :
   - sortie (2>>)
     - Exécute la commande A et redirige sa sortie standard des erreurs à la fin de fichier
5. A 2>&1 :
   - sortie (2>&1)
     - Exécute la commande A et redirige sa sortie standard des erreurs dans sa sortie standard
6. A < fichier :
   - entrée (<)
     - Exécute la commande A en lui passant le contenu de fichier dans son entrée standard (stdin)

Plus d'informations sont disponibles sur les pages de manuel GNU du bash : https://www.gnu.org/software/bash/manual/html_node/index.html

## 2. ***Analyse du sujet***

### 1. ***Consignes***

Etant un minishell et non un vrai Shell, voici les specifications demandes pour reussir le sujet :

1. Ouvrir le prompt en l'attente d'une nouvelle commande
2. Avoir un historique fonctionnel
3. Chercher et lancer le bon executable
4. 1 Variable globale max
5. Il ne faut pas interprer de quotes non fermees, ni de caracteres speciaux non demandes : le backslash et le point virgule
6. Gerer les singles quotes, qui du coup empeche les metacaracteres
7. Gerer les double quotes qui empeche les metacaracteres sauf le $
8. Gerer les redirections suivantes :
   - < : doit rediriger l'entree
   - \> : doit redirager la sortie
   - << : doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour
   - \>> : doit rediriger la sortie en mode append
9. Implementer les pipes |
10. Gerer les variables d'environnement ($ suivi d'un sequence de caracters) qui doivent etre substituer par leur contenu
11. Gerer les $? qui doit etre substituer par le statue de la derniere pipeline executee au premier plan
12. Gerer ctrl-C , ctrl-D , ctrl-\ comme dans bash
13. On doit avoir les builtins suivant :
    - **Echo avec l'option -n** : Affiche les arguments, séparés par des espaces, et se termine par une nouvelle ligne. Le code de retour est 0 à moins qu'une erreur d'écriture ne se produise. Si l'option -n est spécifiée, la nouvelle ligne finale est supprimée.
    - **cd uniquement avec un chemin relatif ou absolu** : Change le répertoire de travail courant vers le répertoire spécifié. Si aucun répertoire n'est fourni, la valeur de la variable d'environnement HOME est utilisée. Si la variable d'environnement CDPATH existe, elle est utilisée comme chemin de recherche : chaque nom de répertoire dans CDPATH est recherché pour trouver le répertoire, avec des noms de répertoire alternatifs séparés par des deux-points (':') dans CDPATH. Si le répertoire commence par un slash, CDPATH n'est pas utilisé.
    - **pwd** : Affiche le chemin absolu du répertoire de travail courant.
    - **export** : Marque chaque nom pour être transmis aux processus enfants dans l'environnement.
    - **unset** : Supprime chaque variable ou nom de fonction.
    - **env** :Définit chaque NOM à VALEUR dans l'environnement et exécute COMMANDE.
    - **exit** : Quitte le shell en retournant un statut n au processus parent du shell. Si n est omis, le statut de sortie est celui de la dernière commande exécutée.
14. ***Precision*** : readline() peut provoquer des fuites de memoires, qui ne sont pas a gerer.
