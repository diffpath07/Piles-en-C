#ifndef _PILE_TABLEAU
#define _PILE_TABLEAU

#include "Booleen.h"

#define MAX 100

typedef int Element;

typedef struct Pile {
    Element tab[MAX];
    int sommet;          
} Pile;

Pile    pile_vide(void);

Pile    empiler(Pile p, Element e);

Pile    depiler(Pile p);

Element sommet(Pile p);

Booleen est_vide(Pile p);

Booleen est_pleine(Pile p);

#endif