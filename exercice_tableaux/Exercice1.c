#include <stdio.h>

int main(){
  int tab[5];
  printf("Entrez 5 entiers\n");
  for(int i=0; i<5; i++){
    printf("Entrez le nombre %d:", i);
    scanf("%d", &tab[i]);
  }
  for(int j=0; j<5; j++){
    printf("Indice %d : %d\n", j, tab[j]);
  }
  return 0;
}
