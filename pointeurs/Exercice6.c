#include <stdio.h>

int main(){
  int tableau1[5] = {10, 20, 30, 40, 50};
  int tableau2[5];
  int *pointeur1, *pointeur2;
  int i;

  pointeur1 = tableau1;
  pointeur2 = tableau2;

  for(i=0; i<5; i++){
    *(pointeur2+i) = *(pointeur1+i);
  }
  
  printf("Tableau 1 :\n");
  for(i=0; i<5; i++){
    printf("%d ", *(pointeur1+i));
  }
  printf("\n");

  printf("Tableau 2 :\n");
  for(i=0; i<5; i++){
    printf("%d ", *(pointeur2+i));
  }
  printf("\n");
  return 0;
}
