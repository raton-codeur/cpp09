# comprendre le tri par fusion-insertion

on veut trier un tableau de n nombres

1. faire des paires d'éléments
2. ordonner les 2 éléments qui composent chaque paire

en parcourant les paires, on obtient la liste d'éléments :
- a1 a2 a3... : la liste des éléments haut
- b1 b2 b3... : la liste des éléments bas

3. trier les paires par ordre croissant selon les éléments haut. on obtient :

<img src="img/a.png" height="150px" />

4. commencer l'insertion

un élément a ou b devient de type c lorsqu'il est inséré. on insère toujours devant le premier a.

on commence par insérer b1 dans une liste vide de c, ce qui nécessite 0 comparaison. on obtient les 2 premiers c qui sont les anciens b1 et a1 :

<img src="img/b.png" height="150px" />

5. continuer l'insertion dans c

le nombre d'éléments de type c détermine la prochaine série d'insertions. en effet, il ne faut pas juste insérer les b dans l'ordre croissant. petit exemple pour voir cela :

## si on insère b2 puis b3

### pour b2

on veut insérer b2 dans un tableau trié [c1, c2]. ça va nous couter au plus 2 comparaisons (une avec c2, et, si on a pas de chance, une autre avec c1).

on se retrouve avec une configuration :

<img src="img/c.png" height="150px" />

### pour b3

on veut insérer b3 dans un tableau trié [c1, c2, c3, c4].

comme on trie par dichotomie, on sait que ça va nous coûter au plus 3 comparaisons (une avec c3, une autre avec c2 ou c4, et potentiellement, une 3e avec c1).

au final, ça nous aurait coûter, au pire, 5 comparaisons.

## mais si on insère b3 puis b2

on va insérer b3 dans un tableau trié [c1, c2], donc c'est comme avant, ça va nous coûter au plus 2 comparaisons.

et là, miracle, lorsqu'on va vouloir insérer b2 on sera dans cette configuration :

<img src="img/d.png" height="150px" />

donc on va vouloir insérer b2 dans un tableau trié [c1, c2, c3], ce qui ne coûte toujours que 2 comparaisons, et non 3.

## généralisation du raisonnement

combien de comparaisons sont nécessaires pour insérer une valeur b dans un tableau trié de n éléments ?

pour n = 2, c'est 2
pour n = 3, c'est 2
pour n = 4, 5, 6, 7, c'est 3
à partir de 8, c'est 4
à partir de 16, c'est 5
