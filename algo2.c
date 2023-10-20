#include <stdio.h>
#include "pile.h"
#include <stdlib.h>
#include <time.h>

char* GenerationAvecNiveauImbrication(int niveauImbrication) {
    char *resultat = (char *)malloc(2 * niveauImbrication + 1 + niveauImbrication);
    int longueurActuelle = 0;
    pile p = pile_vide();
    int niveauImbricationActuelle = 0;

    srand(time(NULL)); 

    while (niveauImbricationActuelle < niveauImbrication) {
        int choix = rand() % 3;
        char c;
        switch (choix) {
            case 0:
                c = '(';
                resultat[longueurActuelle++] = c;
                p = empiler(c, p); 
                niveauImbricationActuelle++;

                break;
            case 1:
                if (longueurActuelle > 0 && !est_pile_vide(p) && sommet(p) == '(') {
                    c = ')';
                    resultat[longueurActuelle++] = c;
                        p = depiler(p); 
                    niveauImbricationActuelle--;

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
    do{
    printf("imbrication min :");
    scanf("%d",&l);
    }while(l<0);
    
    char *c = GenerationAvecNiveauImbrication(l);
    printf("%s\n", c);

    free(c);

    return 0;
}
