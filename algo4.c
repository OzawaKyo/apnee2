#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"

char* GenerationParImbricationMin(int niveauImbrication) {
    int longueurActuelle = 0;
    pile p = pile_vide();
    int niveauImbricationActuelle = 0;
    srand(time(NULL));

    char *resultat = NULL;
    char *temp = NULL;
    char c;

    while (niveauImbricationActuelle < niveauImbrication) {
        int choix = rand() % 3;

        switch (choix) {
            case 0:
                c = '(';
                p = empiler(c, p); 
                niveauImbricationActuelle++;
                break;
            case 1:
                if (longueurActuelle > 0 && !est_pile_vide(p) && sommet(p) == '(') {
                    c = ')';
                    p = depiler(p); 
                    niveauImbricationActuelle--;
                }
                break;
            case 2:
                c = 'A' + (rand() % 26);
                break;
            default:
                break;
        }

        temp = realloc(resultat, (longueurActuelle + 1) * sizeof(char));
        if (temp == NULL) {
            free(resultat);
            detruire_pile(p);
            return NULL;
        }
        resultat = temp;
        resultat[longueurActuelle++] = c;
    }

    while (est_pile_vide(p)) {
        temp = realloc(resultat, (longueurActuelle + 1) * sizeof(char));
        if (temp == NULL) {
            free(resultat);
            detruire_pile(p);
            return NULL;
        }
        resultat = temp;
        resultat[longueurActuelle++] = '(';
        p = empiler('(', p);
    }

    temp = realloc(resultat, (longueurActuelle + 1) * sizeof(char));
    if (temp == NULL) {
        free(resultat);
        detruire_pile(p);
        return NULL; 
    }
    resultat = temp;
    resultat[longueurActuelle] = '\0'; 

    detruire_pile(p);

    return resultat;
}

int main() {
    int l;
    do{
    printf("Niveau d'imbrication:");
    scanf("%d",&l);
    }while(l<0);
    char *c = GenerationParImbricationMin(l);
    if (c != NULL) {
        printf("%s\n", c);
        free(c);
    } else {
        printf("Memoire fail.\n");
    }

    return 0;
}
