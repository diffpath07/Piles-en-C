#include <stdio.h>
#include <assert.h>
#include "PILE.h"

void test_pile_vide(void) {
    Pile p = pile_vide();
    assert(est_vide(p));
    assert(!est_pleine(p));
    printf("test_pile_vide OK\n");
}

void test_empiler_sommet(void) {
    Pile p = pile_vide();

    p = empiler(p, 1);
    assert(!est_vide(p));
    assert(sommet(p) == 1);

    p = empiler(p, 2);
    p = empiler(p, 3);
    assert(sommet(p) == 3);          

    p = depiler(p);
    assert(sommet(p) == 2);
    p = depiler(p);
    assert(sommet(p) == 1);
    p = depiler(p);
    assert(est_vide(p));
    printf("test_empiler_sommet OK\n");
}

void test_depiler_pile_vide(void) {
    Pile p = pile_vide();
    p = depiler(p);                
    assert(est_vide(p));
    assert(p.sommet == -1);
    printf("test_depiler_pile_vide OK\n");
}

void test_pile_pleine(void) {
    Pile p = pile_vide();
    for (int i = 0; i < MAX; i++)
        p = empiler(p, i);
    assert(est_pleine(p));
    assert(sommet(p) == MAX - 1);

    p = empiler(p, 999);             
    assert(p.sommet == MAX - 1);
    assert(sommet(p) == MAX - 1);

    p = depiler(p);
    assert(!est_pleine(p));
    printf("test_pile_pleine OK\n");
}

void test_passage_par_valeur(void) {
    Pile p = pile_vide();
    Pile q = empiler(p, 5);
    assert(est_vide(p));            
    assert(!est_vide(q));
    printf("test_passage_par_valeur OK\n");
}

int main(void) {
    test_pile_vide();
    test_empiler_sommet();
    test_depiler_pile_vide();
    test_pile_pleine();
    test_passage_par_valeur();
    printf("\nTous les tests de la pile sont passes.\n");
    return 0;
}