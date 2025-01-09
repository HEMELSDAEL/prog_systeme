#include <stdio.h>

int main(){
  int tab1[5] = {1, 2, 3, 4, 5};
  int tab2[5] = {5, 4, 3, 2, 1};
  int resultat[5];

  int *pointeur1 = tab1;
  int *pointeur2 = tab2;
  int *pointeurResultat = resultat;

  for(int i = 0; i<5; i++){
    *(pointeurResultat + i) = *(pointeur1 + i) + *(pointeur2 + i);
  }

  printf("Premier tableau :\n");
  for(int i=0; i<5; i++){
    printf("%d ", *(pointeur1 + i));
  }
  printf("\n");

  printf("Second tableau :\n");
  for(int i=0; i<5; i++){
    printf("%d ", *(pointeur2 + i));
  }
  printf("\n");

  printf("Tableau de résultat :\n");
  for(int i=0; i<5; i++){
    printf("%d ", *(pointeurResultat + i));
  }
  printf("\n");
  return 0;
}
