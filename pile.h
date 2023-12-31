#ifndef PILE_H
#define PILE_H

#include <stdlib.h>

typedef struct noeud {
  char donnee;
  struct noeud* prochain;
} *pile;

pile pile_vide();
void detruire_pile(pile p);
pile empiler(int donnee, pile p);
int sommet(pile p);
pile depiler(pile p);
int est_pile_vide(pile p);

#endif /* PILE_H */