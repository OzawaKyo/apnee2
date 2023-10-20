#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int isBalanced(char* expression) {
    pile p = pile_vide();
    char currentChar;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            p = empiler(expression[i], p);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (est_pile_vide(p))
                return 0;
            currentChar = sommet(p);
            p = depiler(p);
            if (!isMatchingPair(currentChar, expression[i]))
                return 0;
        }
    }

    if (est_pile_vide(p))
        return 1;
    else
        return 0;
}

int main() {
    char expression[100];

    printf("Entrez une expression parenthésée : ");
    fgets(expression, sizeof(expression), stdin);

    if (isBalanced(expression))
        printf("L'expression est bien parenthésée.\n");
    else
        printf("L'expression n'est pas bien parenthésée.\n");

    return 0;
}