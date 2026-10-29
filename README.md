#Les piles en C

Implémentation d'une pile (tableau statique) en C, avec les exercices du TD3.

## Fichiers

| Fichier         | Rôle                                          |
|-----------------|-----------------------------------------------|
| `Booleen.h`     | Type `Booleen` (`FAUX`, `VRAI`)               |
| `PILE.h`/`PILE.c` | Bibliothèque de pile (par valeur)           |
| `Ex_1.c`        | Factorielle, copie de pile, recherche         |
| `Ex_2.c`        | Palindrome, inversion de chaîne               |
| `Ex_3.c`        | Parenthésage                                  |
| `Ex_4.c`        | Évaluation d'une expression postfixée         |
| `test_pile.c`   | Tests de la bibliothèque                      |
| `test_exos.c`   | Tests des exercices                           |
| `Exos.pdf`      | Énoncés du TD                                 |

## Primitives

| Fonction                   | Description                    |
|----------------------------|--------------------------------|
| `Pile pile_vide(void)`     | Crée une pile vide             |
| `Pile empiler(Pile, Element)` | Retourne la pile avec `e` au sommet |
| `Pile depiler(Pile)`       | Retourne la pile sans le sommet |
| `Element sommet(Pile)`     | Valeur au sommet               |
| `Booleen est_vide(Pile)`   | `VRAI` si la pile est vide     |
| `Booleen est_pleine(Pile)` | `VRAI` si la pile est pleine   |

La pile est passée **par valeur** : on écrit `p = empiler(p, e);`.
Capacité maximale : `MAX` (100).

## Utilisation

```
make          # compile tout
make test     # lance tous les tests
make clean    # supprime les fichiers générés
```

## Énoncés

Voir [Exos.pdf](Exos.pdf).
