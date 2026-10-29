#include <stdio.h>
#include "PILE.h"
#include <string.h>


// Fonction pour vérifier si une chaîne de caractères est un palindrome en utilisant une pile
int est_palindrome(char *chaine) {
    Pile p = pile_vide();
    int longueur = strlen(chaine);

    for (int i = 0; i < longueur; i++) {
        p = empiler(p, chaine[i]);
    }
    for (int i = 0; i < longueur; i++) {
        if (sommet(p) != chaine[i])
            return 0;
        p = depiler(p);
    }
    return 1; 
}

// Fonction pour inverser une chaîne de caractères en utilisant une pile
char* inverser_chaine(char *chaine) {
    Pile p = pile_vide();
    int longueur = strlen(chaine);
    int i;

    for ( i = 0; i < longueur; i++) {
        p = empiler(p, chaine[i]);
    }
    i=0;
    while (!est_vide(p)) {
        chaine[i] = sommet(p);
        p = depiler(p);
        i++;
    }
    return chaine ;
}

