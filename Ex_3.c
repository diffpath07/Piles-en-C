#include <stdio.h>
#include "PILE.h"
#include <string.h>


// Fonction pour vérifier si les parenthèses dans une expression sont correctement appariées en utilisant une pile
int parenthesage(char *expression) {
    Pile p = pile_vide();
    int longueur = strlen(expression);
    char c;
    for(int i=0 ; i<longueur; i++) {
        c = expression[i];
        if (c == '(' ) {
            p = empiler(p, c);
        } else if (c == ')' ) {
            if (est_vide(p)) {
                return 0; 
            }
            char sommet_pile = sommet(p);
            if ((c == ')' && sommet_pile != '(') )
                return 0; 
            p = depiler(p);
            
        }
    }
    return (est_vide(p)==VRAI) ? 1 : 0;
}

//Version plus simple de la fonction parenthesage
int parenthesage_simple(char *expression) {
    Pile p = pile_vide();

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(')
            p = empiler(p, '(');
        else if (expression[i] == ')') {
            if (est_vide(p))
                return 0;
            p = depiler(p);
        }
    }
    return est_vide(p);
}