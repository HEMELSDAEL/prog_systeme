#include <stdio.h>

int main(){
  int tab[6] = {5, 3, 7, 9, 1, 8};
  int *pointeur1, *pointeur2, temp;
  int i, j;

  printf("Voici le tableau avant le tri :\n");
  for(i=0; i<6; i++){
    printf("%d ", *(tab + i));
  }
  printf("\n");

  //tri à bulles
  for(i=0; i<5; i++){
    for(j=0; j< 6-i-1; j++){
      pointeur1 = tab + j;
      pointeur2 = tab + j + 1;
      if(*pointeur1 > *pointeur2){
	temp = *pointeur1;
	*pointeur1 = *pointeur2;
	*pointeur2 = temp;
      }
    }
  }

  //Affichage du tableau après le tri
  printf("Voici le tableau après le tri :\n");
  for(i=0; i<6; i++){
    printf("%d ", *(tab+i));
  }
  printf("\n");
  return 0;
}
