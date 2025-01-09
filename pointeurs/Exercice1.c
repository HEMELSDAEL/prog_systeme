#include <stdio.h>

int main(){
  int entier = 42;
  int *pointeur = &entier;
  printf("La valeur de l'entier est : %d\n", entier);
  *pointeur = 10;
  printf("La valeur de l'entier après changement du pointeur est : %d\n", entier);
  return 0;
}
