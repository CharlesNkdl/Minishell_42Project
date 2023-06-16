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

### 2. ***Fonctions autorises***

1. **Unistd.h** :
   - *write()* : **ssize_t write(int fd, const void *buf, size_t count)**: Cette fonction permet d'écrire les données du tampon buf vers le descripteur de fichier spécifié par fd. Elle renvoie le nombre d'octets écrits avec succès, ou -1 en cas d'erreur.
   - *access()* : **int access(const char *path, int mode)**: Cette fonction vérifie l'accès au fichier ou au répertoire spécifié par path en fonction du mode spécifié. Elle renvoie 0 si l'accès est autorisé, ou -1 en cas d'erreur.
   - *read()* : **ssize_t read(int fd, void *buf, size_t count)**: Cette fonction lit les données depuis le descripteur de fichier spécifié par fd et les stocke dans le tampon buf. Elle renvoie le nombre d'octets lus, ou 0 si la fin du fichier est atteinte, ou -1 en cas d'erreur.
   - *close()* : **int close(int fd)**: Cette fonction ferme le descripteur de fichier spécifié par fd. Elle renvoie 0 en cas de succès, ou -1 en cas d'erreur.
   - *fork()* : **pid_t fork(void)**: Cette fonction crée un nouveau processus en dupliquant le processus appelant. Elle renvoie la valeur 0 dans le processus enfant, et le PID (identifiant de processus) du processus enfant dans le processus parent, ou -1 en cas d'erreur.
   - *getcwd()* : **char *getcwd(char *buf, size_t size)**: Cette fonction renvoie le chemin absolu du répertoire de travail courant. Le chemin est stocké dans le tampon buf d'une taille maximale spécifiée par size. Elle renvoie buf en cas de succès, ou NULL en cas d'erreur.
   - *chdir()* : **int chdir(const char *path)**: Cette fonction change le répertoire de travail courant vers celui spécifié par path. Elle renvoie 0 en cas de succès, ou -1 en cas d'erreur.
   - *execve()* : **int execve(const char *filename, char *const argv[], char *const envp[])**: Cette fonction remplace le processus courant par un nouveau processus exécutant le programme spécifié par filename. Les arguments de la ligne de commande sont passés via le tableau argv, et les variables d'environnement sont passées via le tableau envp. Elle ne renvoie qu'en cas d'erreur.
   - *isatty()* : **int isatty(int fd)**: Cette fonction vérifie si le descripteur de fichier spécifié par fd est associé à un terminal. Elle renvoie 1 si c'est le cas, ou 0 sinon.
   - *ttyname()* : **char *ttyname(int fd)**: Cette fonction renvoie le nom du terminal associé au descripteur de fichier spécifié par fd. Elle renvoie NULL en cas d'erreur.
   - *ttyslot()* : **int ttyslot(void)**: Cette fonction renvoie le numéro de l'entrée de la table des terminaux associée au descripteur de fichier. Elle renvoie -1 en cas d'erreur.
2. **Stdio.h** :
   - *printf()* : **int printf(const char *format, ...)**: Cette fonction permet d'imprimer des données formatées sur la sortie standard (généralement la console). Elle accepte un format de chaîne spécifié par format qui contrôle la manière dont les données sont affichées. Les arguments supplémentaires fournis seront insérés dans les emplacements spécifiés dans la chaîne de format. Elle renvoie le nombre de caractères imprimés avec succès.
3. **Stdlib.h** :
   - *malloc()* : **void *malloc(size_t size)**: Cette fonction alloue dynamiquement un bloc de mémoire de la taille spécifiée par size en octets. Elle renvoie un pointeur vers le début du bloc de mémoire alloué, ou NULL en cas d'échec.
   - *exit()* : **void exit(int status)**: Cette fonction termine immédiatement l'exécution du programme en retournant le statut spécifié par status à son processus parent ou au système d'exploitation. Elle peut être utilisée pour quitter le programme de manière contrôlée à n'importe quel point.
   - *unlink()* : **int unlink(const char *path)**: Cette fonction supprime le fichier spécifié par path du système de fichiers. Elle renvoie 0 en cas de succès, ou -1 en cas d'échec.
   - *getenv()* : **char *getenv(const char *name)**: Cette fonction renvoie la valeur de la variable d'environnement spécifiée par name. Elle est utilisée pour accéder aux informations stockées dans les variables d'environnement du système. Si la variable n'est pas trouvée, elle renvoie NULL.
4. **Readline.h** :
   - *readline()* : **char *readline(const char *prompt)**: Cette fonction affiche le message d'invite spécifié par prompt et lit une ligne de texte depuis l'entrée standard. Elle renvoie un pointeur vers la chaîne de caractères contenant la ligne lue.
   - *rl_clear_history()* : **void rl_clear_history()**: Cette fonction efface l'historique des lignes de commande précédemment saisies à l'aide de la fonction readline()
   - *rl_on_new_line()* : **void rl_on_new_line()**: Cette fonction signale à la bibliothèque readline qu'une nouvelle ligne de commande a été saisie et que les opérations suivantes devraient être effectuées à partir de la première colonne de la ligne.
   - *rl_replace_line()* : **void rl_replace_line(const char *text, int clear_undo)**: Cette fonction remplace la ligne de commande actuelle par la chaîne de caractères spécifiée par text. Si clear_undo est différent de 0, l'historique des modifications de ligne est également effacé.
   - *rl_redisplay()* : **void rl_redisplay()**: Cette fonction réaffiche la ligne de commande actuelle.
   - *add_history()* : **void add_history(const char *line)**: Cette fonction ajoute la ligne spécifiée par line à l'historique des lignes de commande.
5. **Termios.h** :
   - *tcsetattr()* : **int tcsetattr(int fd, int optional_actions, const struct termios *termios_p)**: Cette fonction modifie les attributs du terminal associé au descripteur de fichier fd en utilisant les paramètres spécifiés dans la structure termios_p. L'argument optional_actions spécifie quand les changements doivent prendre effet. Elle renvoie 0 en cas de succès, ou -1 en cas d'échec.
   - *tcgetattr()* : **int tcgetattr(int fd, struct termios *termios_p)**: Cette fonction obtient les attributs actuels du terminal associé au descripteur de fichier fd et les stocke dans la structure termios_p. Elle renvoie 0 en cas de succès, ou -1 en cas d'échec.
6. **String.h** :
   - *strerror()* : **char *strerror(int errnum)**: Cette fonction renvoie une chaîne de caractères décrivant le message d'erreur correspondant au code d'erreur spécifié par errnum. Elle est souvent utilisée pour obtenir une description textuelle d'une erreur.
7. **errno.h** :
   - *perror()* : **void perror(const char *str)**: Cette fonction affiche le message d'erreur correspondant à la valeur de la variable errno actuelle, préfixé par la chaîne str.
8. **dirent.h** :
   - *opendir()* : **DIR *opendir(const char *name)**: Cette fonction ouvre le répertoire spécifié par name et renvoie un pointeur vers une structure de type DIR, qui peut être utilisée pour lire le contenu du répertoire.
   - *readdir()* : **struct dirent *readdir(DIR *dirp)**: Cette fonction lit une entrée du répertoire spécifié par le pointeur dirp et renvoie un pointeur vers une structure de type dirent contenant les informations de l'entrée du répertoire suivante.
   - *closedir()* : **int closedir(DIR *dirp)**: Cette fonction ferme le répertoire spécifié par le pointeur dirp. Elle renvoie 0 en cas de succès, ou -1 en cas d'erreur.
9. **fcntl.h** :
   - *open()* : **int open(const char *pathname, int flags, mode_t mode)**: Cette fonction ouvre le fichier spécifié par pathname avec les indicateurs de flags spécifiés, et renvoie le descripteur de fichier correspondant. Si nécessaire, le mode du fichier peut être spécifié avec mode.
   - *dup()* : **int dup(int oldfd)**: Cette fonction duplique le descripteur de fichier oldfd, en renvoyant un nouveau descripteur de fichier qui fait référence au même fichier ouvert.
   - *dup2()* : **int dup2(int oldfd, int newfd)**: Cette fonction duplique le descripteur de fichier oldfd vers newfd, en fermant newfd au préalable s'il est ouvert. Elle assure que newfd fait référence au même fichier que oldfd.
   - *pipe()* : **int pipe(int pipefd[2])**: Cette fonction crée un tube (pipe) unidirectionnel, et renvoie les descripteurs de fichier pipefd pour la lecture (pipefd[0]) et l'écriture (pipefd[1]).
10. **sys/wait.h** :
    - *wait()* : **pid_t wait(int *status)**: Cette fonction suspend l'exécution du processus appelant jusqu'à ce qu'un de ses processus enfants se termine. Elle renvoie le PID du processus enfant terminé et met à jour la valeur de status pour refléter le statut de sortie du processus enfant.
    - *waitpid()* : **pid_t waitpid(pid_t pid, int *status, int options)**: Cette fonction attend la terminaison d'un processus enfant spécifié par pid. Elle renvoie le PID du processus enfant terminé et met à jour la valeur de status pour refléter son statut de sortie. Les options supplémentaires peuvent être spécifiées avec options.
11. **sys/types.h** :
    - Necessaire pour certaines fonctions
12. **sys/stat.h** :
    - *stat()* : **int stat(const char *path, struct stat *buf)**: Cette fonction récupère les informations sur le fichier spécifié par path et les stocke dans la structure buf. Elle renvoie 0 en cas de succès, ou -1 en cas d'erreur.
    - *lstat()* : **int lstat(const char *path, struct stat *buf)**: Cette fonction est similaire à stat(), mais lorsqu'elle est utilisée avec un lien symbolique, elle renvoie les informations sur le lien symbolique lui-même, plutôt que sur le fichier auquel il pointe.
    - *fstat()* : **int fstat(int fd, struct stat *buf)**: Cette fonction récupère les informations sur le descripteur de fichier fd et les stocke dans la structure buf. Elle est utilisée pour obtenir des informations sur un fichier ouvert.
13. **sys/ioctl.h** :
    - *ioctl()* : **int ioctl(int fd, unsigned long request, ... )**: Cette fonction effectue diverses opérations de contrôle sur le périphérique associé au descripteur de fichier fd. Les opérations spécifiques sont définies par request et peuvent avoir des arguments supplémentaires facultatifs.
14. **signal.h** :
    - *signal()* : **void (*signal(int signum, void (*handler)(int)))(int)**: Cette fonction permet de capturer et de gérer les signaux logiciels spécifiés par signum. Elle associe le gestionnaire de signal spécifié par handler au signal donné. Elle renvoie le gestionnaire de signal précédent.
    - *sigaction()* : **int sigaction(int signum, const struct sigaction \*act, struct sigaction \*oldact)** : Cette fonction permet de modifier le comportement du signal spécifié par signum en utilisant les paramètres spécifiés dans la structure act. Elle renvoie 0 en cas de succès, ou -1 en cas d'erreur.
    - *sigemptyset()* : **int sigemptyset(sigset_t *set)**: Cette fonction initialise l'ensemble de signaux spécifié par set en le vidant de tous les signaux.
    - *sigaddset()* : **int sigaddset(sigset_t *set, int signum)**: Cette fonction ajoute le signal spécifié par signum à l'ensemble de signaux spécifié par set.
    - *kill()* : **int kill(pid_t pid, int signum)**: Cette fonction envoie le signal spécifié par signum au processus avec le PID spécifié par pid.
15. **term.h et curses.h** :
    - *tgetent()* : **int tgetent(char *bp, const char *name)**: Cette fonction initialise la bibliothèque terminfo en lisant les informations de capacité du terminal spécifié par name et les stocke dans le buffer bp. Elle renvoie 1 en cas de succès, 0 si le terminal n'est pas trouvé ou -1 en cas d'erreur.
    - *tgetflag()* : **int tgetflag(const char *id)**: Cette fonction renvoie la valeur de la capacité de drapeau associée à l'identifiant id` spécifié. Elle est utilisée pour récupérer les informations sur les drapeaux du terminal.
    - *tgetnum()* : **int tgetnum(const char *id)**: Cette fonction renvoie la valeur de la capacité numérique associée à l'identifiant id spécifié. Elle est utilisée pour récupérer les informations sur les valeurs numériques du terminal.
    - *tgetstr()* : **char *tgetstr(const char *id, char *\*area)**: Cette fonction renvoie la valeur de la capacité de chaîne associée à l'identifiant id spécifié. Elle est utilisée pour récupérer les informations sur les séquences de contrôle du terminal.
    - *tgoto()* : **char *tgoto(const char *cap, int col, int row)**: Cette fonction génère une séquence de contrôle pour se déplacer à la position spécifiée par les coordonnées col et row. Elle utilise la capacité spécifiée par cap pour construire la séquence de contrôle.
    - *tputs()* : **int tputs(const char *str, int affcnt, int (*putc)(int))**: Cette fonction envoie la séquence de contrôle spécifiée par str au terminal. Le paramètre affcnt indique combien de lignes sont affectées par la séquence de contrôle. La fonction putc est utilisée pour envoyer chaque caractère individuellement.
16. **Obsolete** :
     - *wait3()* : obsolete selon le manuel, plutot utilise waitpid ou waitid, l'equivalent de wait3 est **waitpid(-1, status, options)**. Wait 3 attends n'importe quel child.
     - *wait4()* : idem, l'equivalent de wait4 est **waitpid(pid, status, options)**. Wait 4 lui attends un child specifique.

### 3. ***Types et Structures issues des libraires et des fonctions***

1. **struct stat** : issues de stat.h, elle est necessaire pour appeller les fonctions, et permet d'envoyer une structure stat et de la remplir pour avoir les informations :

```C
   struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for file system I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
    };
```

2. **struct sigaction** : issues de signal.h,cette structure est utilisée pour spécifier le comportement d'un signal. Elle contient des membres tels que sa_handler qui pointe vers la fonction de gestion du signal, sa_flags qui spécifie les indicateurs de comportement du signal, et sa_mask qui indique les signaux bloqués lors de l'exécution de la fonction de gestion du signal.

```C
    struct sigaction {
        void     (*sa_handler)(int);
        void     (*sa_sigaction)(int, siginfo_t *, void *);
        sigset_t   sa_mask;
        int        sa_flags;
        void     (*sa_restorer)(void);
    };
```

3. **struct dirent** : issues de dirent.h, cette structure est utilisée pour représenter une entrée de répertoire. Elle contient des informations sur un fichier ou un sous-répertoire dans un répertoire donné, telles que son nom et son type.

```C
    struct dirent {
    ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* offset to the next dirent */
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
                                   by all file system types */
    char           d_name[256]; /* filename */
    };
```

4. **struct termios** : issues de termios.h, Cette structure est utilisée pour représenter les attributs d'un terminal. Elle contient des membres tels que c_iflag, c_oflag, c_cflag, c_lflag qui représentent les indicateurs de mode d'entrée, de sortie, de contrôle et de local, respectivement. Ces membres sont utilisés pour configurer et obtenir les attributs du terminal à l'aide des fonctions tcsetattr() et tcgetattr().

```C
    struct termios {            /*Contient au moins les elements suivant*/
    tcflag_t c_iflag;           tcflag_t c_iflag;      /* input modes */
    tcflag_t c_oflag;           tcflag_t c_oflag;      /* output modes */
    tcflag_t c_cflag;           tcflag_t c_cflag;      /* control modes */
    tcflag_t c_lflag;           tcflag_t c_lflag;      /* local modes */
    cc_t c_cc[NCCS];            cc_t     c_cc[NCCS];   /* special characters */
    speed_t c_ispeed;
    speed_t c_ospeed;
};
```

5. **DIR struct** : issues de dirent.h, elle represente un flux de repertoire, sa structure est opaque, on ne vas directement la manipuler, on va l'ouvrir avec Opendir puis appeler readdir() pour avoir une structure dirent plus facile a manipuler.

➡️ Un excellent tutoriel pour voir plus clair https://pub.phyks.me/sdz/sdz/arcourir-les-dossiers-avec-dirent-h.html

## Ressources qui ont l'air utile

- https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html
- https://minishell.simple.ink/
- https://betterprogramming.pub/how-bash-works-8424becc12f3 ➡️ Shell
- https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html ➡️ Shell
- https://stackoverflow.com/questions/6697753/difference-between-single-and-double-quotes-in-bash ➡️ Shell
- https://cs61.seas.harvard.edu/site/2019/Section7/ ➡️ Shell
- https://ast-viewer.datacamp.com/editor?code=echo%20%22oui%22&start=NA&grammar=shell ➡️ Permet de simuler la reflexion du parser bash en graphique pour mieux visualiser
- http://www-igm.univ-mlv.fr/~dr/NCSPDF/chapitre11.pdf ➡️ Signaux
- https://unix.stackexchange.com/questions/159513/what-are-the-shells-control-and-redirection-operators
- https://codes-sources.commentcamarche.net/forum/affich-10047436-developper-un-shell-de-base
- https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/#1-le-terminal-1
- http://i.paysdu42.fr/?page=minishell.c Schema tres general, du minishell d'Epitech, surement difference de sujet
- https://www.lamsade.dauphine.fr/~bnegrevergne/ens/Unix/static/projet.pdf sujet minishell de l'universite Paris Dauphine, avec quelques precisions sur les etapes possibles
- https://stackoverflow.com/questions/13636252/c-minishell-adding-pipelines
- https://nickolasteixeira.medium.com/want-to-build-a-simple-shell-heres-how-you-do-it-75890647bae8
- https://www.youtube.com/watch?v=cIBmeEpsMj0&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj ➡️ series de video Ytb, explique bien

### Geeks for Geeks le S

- https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/
- https://www.geeksforgeeks.org/pipe-system-call/?ref=rp
- https://www.geeksforgeeks.org/wait-system-call-c/?ref=rp
- https://www.geeksforgeeks.org/fork-system-call/?ref=rp
- https://www.geeksforgeeks.org/making-linux-shell-c/
- https://www.geeksforgeeks.org/dup-dup2-linux-system-call/?ref=ml_lbp
- https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/

### Developpez.com pas mal aussi

- https://chrtophe.developpez.com/tutoriels/minisysteme/
- https://rperrot.developpez.com/articles/algo/structures/arbres/ arbre de logique abstraite pour lexer/parser semble revenir souvent

## Sources utilise pour le Readme

- Wikipedia
- man
- linux.die.net
- man7.org
- mkssoftware.com
- chatgpt
- pub.phyks.me/sdz/sdz
- gnu.org
