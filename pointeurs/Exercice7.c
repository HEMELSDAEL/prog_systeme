#include <stdio.h>

int main(){
  int tab[7] = {1, 2, 3, 4, 5, 6, 7};
  int *pointeur = tab;
  int somme=0;

  for(int i=0; i<7; i++){
    somme = somme + *(pointeur+i);
  }

  printf("La somme des éléments du tableau est : %d\n", somme);
  return 0;
  
}
