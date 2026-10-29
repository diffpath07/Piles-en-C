#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "PILE.h"

long factorielle(int n);
Pile creer_copie(Pile p);
void chercher_element(Pile p, Element e);
int  est_palindrome(char *chaine);
char *inverser_chaine(char *chaine);
int  parenthesage(char *expression);
int  evaluer_postfixe(char *expression);

int main(void) {
    assert(factorielle(0) == 1);
    assert(factorielle(5) == 120);

    Pile p = pile_vide();
    p = empiler(p, 1);
    p = empiler(p, 2);
    p = empiler(p, 3);
    Pile c = creer_copie(p);
    assert(sommet(c) == 3);
    c = depiler(c);
    assert(sommet(c) == 2);
    chercher_element(p, 2);
    chercher_element(p, 9);

    assert(est_palindrome("radar") == 1);
    assert(est_palindrome("informatique") == 0);
    char s[] = "bonjour";
    inverser_chaine(s);
    assert(strcmp(s, "ruojnob") == 0);

    assert(parenthesage("(2+6) / (9-3)") == 1);
    assert(parenthesage("((3+6) / (5+9)") == 0);
    assert(parenthesage(")(") == 0);

    assert(evaluer_postfixe("23+") == 5);
    assert(evaluer_postfixe("92-3*") == 21);
    assert(evaluer_postfixe("82/3+") == 7);

    printf("Tous les tests des exercices sont passes.\n");
    return 0;
}
