#include <stdio.h>
#include "PILE.h"

// Fonction pour calculer la factorielle d'un nombre n en utilisant une pile
long factorielle(int n) {
    Pile p = pile_vide();
    long res = 1;

    for (int i = 2; i <= n; i++) {
        p = empiler(p, i);
    }

    while (!est_vide(p)) {
        res = res * sommet(p);
        p = depiler(p);
    }

    return res;
}

// Fonction pour  cree une copie d'une pile
Pile creer_copie(Pile p) {
    Pile p_copie = pile_vide();
    Pile p_aux = pile_vide();

    while (!est_vide(p)) {
        p_aux = empiler(p_aux, sommet(p));
        p = depiler(p);
    }

    while (!est_vide(p_aux)) {
        p_copie = empiler(p_copie, sommet(p_aux));
        p_aux = depiler(p_aux);
    }

    return p_copie;
}

// Fonction pour chercher un élément dans une pile
void chercher_element(Pile p , Element e){
    Pile p_aux = pile_vide();
    int trouve = 0;
    while (!est_vide(p)) {
        if (sommet(p) == e) {
            trouve = 1;
            break;
        }
        p_aux = empiler(p_aux, sommet(p));
        p = depiler(p);
    }
    while (!est_vide(p_aux)) {
        p = empiler(p, sommet(p_aux));
        p_aux = depiler(p_aux);
    }
    if (trouve ) {
        printf("Element %d trouvé dans la pile.\n", e);
    } else {
        printf("Element %d non trouvé dans la pile.\n", e);
    }
}