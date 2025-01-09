#include <stdio.h>

int main(){
  int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *pointeur = tab;
  int nombre, i;
  int trouve = 0;

  printf("Veuillez entrer un nombre à rechercher :\n");
  scanf("%d", &nombre);

  for(i=0; i<10; i++){
    if(*(pointeur + i) == nombre){
      printf("Le nombre %d est présent à l'indice %d\n", nombre , i);
      trouve = 1;
      break;
    }
  }
  if(!trouve){
    printf("Le nombre %d n'est pas présent dans le tableau", nombre);
  }
  return 0;
}
