#include <stdio.h>
#include <string.h>
#include "PILE.h"

// Primitive donnée : teste si un caractère est un opérande (un chiffre)
int est_operande(char c) {
    return (c >= '0' && c <= '9');
}

// Primitive donnée : effectue l'opération "op" entre deux opérandes a et b
int effectuer_operation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Fonction pour évaluer une expression postfixée en utilisant une pile
int evaluer_postfixe(char *expression) {
    Pile p = pile_vide();
    int longueur = strlen(expression);
    int a, b;
    char c;

    for (int i = 0; i < longueur; i++) {
        c = expression[i];
        if (est_operande(c)) {
            p = empiler(p, c - '0');       
        } else {
            b = sommet(p);                 
            p = depiler(p);
            a = sommet(p);                 
            p = depiler(p);
            p = empiler(p, effectuer_operation(c, a, b));
        }
    }
    return sommet(p);                      
}