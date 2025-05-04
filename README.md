# comprendre le tri par fusion-insertion

on veut trier un tableau de n nombres.

algorithme en 5 étapes.

**étape 1** : faire des paires d'éléments

**étape 2** : ordonner les 2 éléments qui composent chaque paire

en parcourant les paires, on obtient la liste d'éléments :
- a1 a2 a3... : la liste des éléments haut
- b1 b2 b3... : la liste des éléments bas

**étape 3** : trier les paires par ordre croissant selon les éléments haut. on obtient :

<img src="img/a.png" height="150px" />

**étape 4** : commencer l'insertion

un élément a ou b devient de type c lorsqu'il est inséré. on insère toujours devant le premier a.

on commence par insérer b1 dans une liste vide de c, ce qui nécessite 0 comparaison. c'est la fin de cette série d'insertion. à la fin de chaque série d'insertion, le premier a devient automatiquement le dernier c (il se trie tout seul, si on veut). on obtient les 2 premiers c, qui sont les anciens b1 et a1 :

<img src="img/b.png" height="150px" />

**étape 5** : continuer l'insertion dans c

le nombre d'éléments de type c détermine la prochaine série d'insertions. en effet, il ne faut pas juste insérer les b dans l'ordre des paires. petit exemple pour comprendre cela :

## si on insère b2 puis b3

### pour b2

on veut insérer b2 dans un tableau trié [c1, c2]. ça va nous couter au plus 2 comparaisons (une avec c2, et, si on a pas de chance, une autre avec c1).

on se retrouve avec une configuration :

<img src="img/c.png" height="150px" />

### pour b3

on veut insérer b3 dans un tableau trié [c1, c2, c3, c4].

comme on trie par dichotomie, on sait que ça va nous coûter au plus 3 comparaisons (une avec c3, une autre avec c2 ou c4, et potentiellement, une 3e avec c1).

au final, si on insère b2 avant b3, ça nous coûte, au pire, 5 comparaisons.

## si on insère b3 puis b2

<img src="img/b.png" height="150px" />

on veut insérer b3 dans un tableau trié [c1, c2]. donc, comme on l'a vu juste avant, ça va nous coûter, au plus, 2 comparaisons.

et là, miracle, lorsqu'on va vouloir insérer b2, on sera dans cette configuration :

<img src="img/d.png" height="150px" />

donc on va vouloir insérer b2 dans un tableau trié [c1, c2, c3], ce qui ne coûte toujours que 2 comparaisons, et non 3 (une avec c2, et une autre avec c1 ou c3).

donc, si on insère b3 avant b2, ça nous coûte, au pire, 4 comparaisons.

après ça, on se retrouvera dans cette configuration :

<img src="img/e.png" height="150px" />

et là, quel élément faut-il insérer ? encore une fois, cela dépend de la taille de c

pour une taille de 6, il faut d'abord insérer b5, puis b4. ainsi, on aura, au pire, pour l'un et pour l'autre, seulement 3 comparaisons à faire.

une fois b4 et b5 inséré, on est dans la configuration :

<img src="img/f.png" height="150px" />

et là, pour une taille de 10, il va d'abord falloir insérer b11, puis b10, b9, b8, b7, et b6. ainsi, on aura, pour toutes ces insertions, au plus 4 comparaisons à faire.

## comprendre et trouver l'ordre des insertions

### généraliser la recherche dichotomique

on cherche le nombre de comparaisons nécessaires pour insérer une valeur b dans un tableau trié de n éléments.

on l'a vu, pour n = 2, c'est 2. pour n = 3, c'est 2 aussi. pour n = 4, 5, 6, 7, c'est 3. à partir de 8, c'est 4. à partir de 16, c'est 5.

on en déduit que, pour une taille n, c'est floor ( log2 (n) ) + 1.

### lien avec la suite de jacobsthal

pas vraiment besoin d'utiliser la taille de la liste c. on a juste besoin de retrouver la suite :

0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, ...

elle nous donne l'indice des éléments b qui initient une série d'insertion. d'où le fait qu'il faille d'abord insérer :
- b3 + tout ce qui lui est inférieur, donc b2
- b5, b4
- b11, b10, b9, b8, b7, b6
- b21, b20, ..., b12

