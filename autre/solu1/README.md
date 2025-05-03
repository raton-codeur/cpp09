# cpp09 - École 42 | Paris

## Description

Ce projet fait partie des exercices du module CPP09. Il a pour but de renforcer les compétences en programmation C++98, en mettant l'accent sur l'utilisation de la Standard Template Library (STL) en C++.

## Exercise 00: Bitcoin Exchange

L'objectif de l'exercice 00 consiste à créer un programme qui affiche la valeur d’une certaine quantité de bitcoins à une certaine date. Vous allez développer un programme qui utilise une base de données au format CSV pour représenter le prix du bitcoin au fil du temps.

### Structure du Projet

Le projet est organisé de la manière suivante :

- **Directory:** `ex00/`
- **Files submitted:**
  - `BitcoinExchange.hpp`
  - `BitcoinExchange.cpp`
  - `Makefile`
  - `main.cpp`

### Description des Fichiers

- `BitcoinExchange.hpp`: Contient la déclaration des classes et fonctions utilisées dans le projet.
- `BitcoinExchange.cpp`: Contient l'implémentation des classes et fonctions.
- `main.cpp`: Contient le point d'entrée du programme et la logique principale.
- `Makefile`: Fichier pour automatiser la compilation du projet.

### Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé btc dans le répertoire courant.

## Exécution
Après la compilation, exécutez le programme avec la commande :

```bash
./btc input.txt
```
Remplacez input.txt par le fichier contenant les données à évaluer.

## Exercise 01: Reverse Polish Notation
L'objectif de l'exercice 01 consiste à créer un programme capable de traiter des expressions mathématiques en notation polonaise inversée.

## Structure du Projet
Le projet est organisé de la manière suivante :

- **Directory:** `ex01/`
- **Files submitted:**
  - `RPN.hpp`
  - `RPN.cpp`
  - `Makefile`
  - `main.cpp`
### Description des Fichiers
- `RPN.hpp`: Contient la déclaration des classes et fonctions utilisées dans le projet.
- `RPN.cpp`: Contient l'implémentation des classes et fonctions.
- `main.cpp`: Contient le point d'entrée du programme et la logique principale.
- `Makefile`: Fichier pour automatiser la compilation du projet.
## Compilation
Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé RPN dans le répertoire courant.

## Exécution
Après la compilation, exécutez le programme avec la commande :

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```
Vous pouvez remplacer l'expression par n'importe quelle autre expression en notation polonaise inversée.

## Exercise 02: PmergeMe
L'objectif de l'exercice 02 consiste à créer un programme qui trie une séquence d'entiers positifs en utilisant l'algorithme "merge-insert".

## Structure du Projet
Le projet est organisé de la manière suivante :

- **Directory:** `ex02/`
- **Files submitted:**
  - `PmergeMe.hpp`
  - `PmergeMe.cpp`
  - `Makefile`
  - `main.cpp`
### Description des Fichiers
`PmergeMe.hpp`: Contient la déclaration des classes et fonctions utilisées dans le projet.
`PmergeMe.cpp`: Contient l'implémentation des classes et fonctions.
`main.cpp`: Contient le point d'entrée du programme et la logique principale.
`Makefile`: Fichier pour automatiser la compilation du projet.
## Compilation
Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé PmergeMe dans le répertoire courant.

## Exécution
Après la compilation, exécutez le programme avec la commande :

```bash
./PmergeMe 3 5 9 7 4
```
Vous pouvez remplacer les arguments par n'importe quelle séquence d'entiers positifs.

## Fonctionnalités
Gestion des exceptions : Le programme démontre l'utilisation des exceptions pour gérer les erreurs de manière propre et sécurisée.
Suivi des bonnes pratiques de codage C++98 : Respect strict des conventions de codage et des standards de C++98.
Structure de code modulaire et maintenable : Le code est organisé de manière à être facilement compréhensible et extensible.
## Contributeurs
raveriss

## Remarques
Ce projet suit les conventions de codage strictes pour C++98.

## Ressources Utilisées
- [Apprenez à programmer en C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c)
- [Programmez en orienté objet avec C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c)
- [Apprenez à programmer en C++ sur codecademy](https://www.codecademy.com/catalog/language/c-plus-plus)
- [Introduction à C++ sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-introduction)
- [C++ Intermédiaire sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-intermediate)
