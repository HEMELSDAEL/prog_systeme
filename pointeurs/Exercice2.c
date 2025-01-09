#include <stdio.h>

int main(){
  int tab[5] = {10, 20, 30, 40, 50};
  int *pointeur = tab;

  printf("Les éléments du tableau sont :\n");
  for(int i=0; i<5; i++){
    printf("Element %d : %d\n", i+1, *(pointeur+i));
  }
  return 0;
}
