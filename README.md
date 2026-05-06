# 🤖 A-MAZE-D (DELGRANGE JÉRÉMY - JOSHUA KNOCKAERT @Whisp59 - NOA WASIELEWSKI @Then0ix)

## 🧭 DESCRIPTION DU PROJET

- L'objectif de ce projet est de faire naviguer des robots dans un labyrinthe virtuel, de la salle d'entrée jusqu'à la sortie.
- Il s'agit de faire traverser le maximum de robots en un minimum de temps (tours).
- Le programme est basé sur la théorie des graphes et les algorithmes de pathfinding (recherche de chemin).
- L'outil doit dans un premier temps analyser la configuration du terrain pour vérifier sa validité, puis calculer le ou les chemins les plus courts pour atteindre la sortie.

## 🗓️ DATES

📅 **16/02/2026 à 16/02/2026 - 06/03/2026 à 19h42**

## 🛠️ Fonctionnalités attendues

- Lecture de données : Le programme lit la description du labyrinthe depuis l'entrée standard (standard input). Le programme doit afficher chaque ligne lue avant qu'une potentielle erreur ne survienne.

- Parsing : Récupération du nombre de robots au départ, des différentes salles (avec leurs coordonnées) et des tunnels reliant les salles.

- Gestion des commandes et commentaires : Les lignes contenant un `#` servent de commentaires, tandis que `##start` et `##end` indiquent respectivement la salle d'entrée et la salle de sortie.

- Déplacements (Laps) : À chaque tour, un robot ne peut se déplacer qu'une seule fois via un tunnel. Chaque salle (à l'exception de l'entrée et de la sortie) ne peut accueillir qu'un seul robot à la fois.

> [!NOTE]
> ⚠️ Les noms des salles ne sont pas obligatoirement des suites de nombres logiques. Il est tout à fait possible d'avoir des salles nommées `zdfg`, `256`, ou `qwerty`.

## 🚀 UTILISATION

### - Lancement :

Un script Perl est fourni pour générer des labyrinthes à tester.
```bash
make
./amazed < labyrinth
```

### ⚙️ - Interactions :

- Le programme doit obligatoirement afficher la configuration initiale parsée (robots, salles, tunnels), suivie de chaque mouvement de robot au format Pn-r (n étant le numéro du robot et r la salle de destination).

```bash
$> ./amazed < labyrinth
#number_of_robots
3
#rooms
##start
0 1 0
##end
1 13 0
2 5 0
#tunnels
0-2
2-1
#moves
P1-2
P1-1 P2-2
P2-1 P3-2
P3-1
```

> [!IMPORTANT]
> Les messages d'erreur doivent impérativement être écrits sur la sortie d'erreur (stderr). En cas d'erreur ou de ligne non conforme, le programme doit s'arrêter et retourner le code d'erreur 84 (ou 0 s'il n'y a pas d'erreur).

## 📜 RÈGLES ET CONTRAINTES :

* Le projet suit des règles strictes de développement :

    - Langage : C.

    - Rendu : La totalité des fichiers sources doit être présente, sans fichiers inutiles (binaires, temporaires, etc.).

    - Compilation : Le projet doit inclure un Makefile contenant les règles re, clean et fclean.

    - Bonus : Possibilité de créer un viewer (visualiseur 2D ou 3D). Tous les fichiers liés aux bonus (ainsi que leur Makefile spécifique) doivent être placés dans un dossier nommé bonus.

* Fonctions autorisées : read, write, malloc, free, getline.

## 📁 FICHIERS && STRUCTURE DU PROJET :

```bash
├── include
│   ├── my.h
│   ├── print.h
│   └── str.h
├── lib_print
│   └── my
│       ├── Makefile
│       ├── my_putchar.c
│       ├── my_puterror.c
│       ├── my_put_nbr.c
│       ├── my_putstr.c
│       ├── my_revstr.c
│       ├── my_strlen.c
│       └── print.h
├── lib_str
│   └── my
│       ├── Makefile
│       ├── my_atoi.c
│       ├── my_strcapitalize.c
│       ├── my_strcat.c
│       ├── my_strcmp.c
│       ├── my_strcpy.c
│       ├── my_strdup.c
│       ├── my_str_isalpha.c
│       ├── my_str_islower.c
│       ├── my_str_isnum.c
│       ├── my_str_isprintable.c
│       ├── my_str_isupper.c
│       ├── my_strlen.c
│       ├── my_strlowcase.c
│       ├── my_strncat.c
│       ├── my_strncmp.c
│       ├── my_strncpy.c
│       ├── my_strstr.c
│       ├── my_strtok.c
│       ├── my_strupcase.c
│       └── str.h
├── Makefile
├── README.md
└── src
    ├── algo
    │   ├── check_neighbors.c
    │   └── implement_dijk.c
    ├── main.c
    ├── maze
    │   ├── init_maze.c
    │   ├── new_matrix.c
    │   └── solve_maze.c
    ├── parsing
    │   ├── moves.c
    │   ├── parsing.c
    │   ├── rooms.c
    │   └── tunnels.c
    └── paths
        ├── commands.c
        └── get_paths.c

```
