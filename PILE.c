#include "PILE.h"

Pile pile_vide(void) {
    Pile p;
    p.sommet = -1;
    return p;
}

Booleen est_vide(Pile p) {
    return p.sommet == -1;
}

Booleen est_pleine(Pile p) {
    return p.sommet == MAX - 1;
}

Pile empiler(Pile p, Element e) {
    if (!est_pleine(p)) {
        p.sommet++;
        p.tab[p.sommet] = e;
    }
    return p;
}

Pile depiler(Pile p) {
    if (!est_vide(p)) {
        p.sommet--;
    }
    return p;
}

Element sommet(Pile p) {
    return p.tab[p.sommet];    
}