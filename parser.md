# Lexer et parser ce que je doit faire #

## Schema general ##

Input => Lexer et parser => Expansion => Command exec => exit status

## Lexer ##

Dans tout les compilateurs, meme pour le bash, le traitement des informations passe par plusieurs etapes
La premiere est un lexer / tokenizer
Pour bien tout separer puis tout parser
Les nuances du lexer :

- si on commence par commencer par un split " ", on n'isole pas les "" ni les ''
- pas necessairement d'espace apres ou avant les pipes
-
