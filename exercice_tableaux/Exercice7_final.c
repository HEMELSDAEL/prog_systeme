#include <stdio.h>

int main(){
  int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i, dernier;
  printf("Voici le tableau avant sa rotation :\n");
  for(i=0; i<10; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");

  //rotation_tableau
  dernier = tab[9];
  for(i=9; i>0; i--){
    tab[i] = tab[i-1];
  }
  tab[0] = dernier;

  printf("\nTableau après rotation :\n");
  for(i=0; i<10; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
  return 0;
}
