#include <stdio.h>
#include "pile.h"
#include <stdlib.h>
#include <time.h>

char* GenerationParLongueurMin(int longueurMin) {
    char *resultat = (char *)malloc(2 * longueurMin + 1); 
    int longueurActuelle = 0;
    pile p = pile_vide();

    srand(time(NULL)); 

    while (longueurActuelle < longueurMin) {
        int choix = rand() % 3;
        char c;
        switch (choix) {
            case 0:
                c = '(';
                resultat[longueurActuelle++] = c;
                p = empiler(c, p); 
                break;
            case 1:
                if (longueurActuelle > 0 && !est_pile_vide(p) && sommet(p) == '(') {
                    c = ')';
                    resultat[longueurActuelle++] = c;
                        p = depiler(p); 
                }
                break;
            case 2:
                c = 'A' + (rand() % 26);
                resultat[longueurActuelle++] = c;
                break;
            default:
                break;
        }
    }

    while (!est_pile_vide(p)) {
        resultat[longueurActuelle++] = ')';
        p = depiler(p);
    }

    resultat[longueurActuelle] = '\0';

    detruire_pile(p);

    return resultat;
}

int main() {
    int l;
    printf("valeur min :");
    scanf("%d",&l);
    char *c = GenerationParLongueurMin(l);
    printf("%s\n", c);

    free(c);

    return 0;
}