#include <stdio.h>

int main(){
  int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int nombre, i;
  int trouve = 0;
  printf("Tapez un nombre pour savoir s'il est dans le tableau : ");
  scanf("%d", &nombre);
  for(i=0; i<10; i++){
    if(tab[i]==nombre){
      printf("Le nombre %d est présent dans le tableau et voici son indice %d\n",nombre,  i);
      trouve = 1;
      break;
    }
  }
  if(!trouve){
    printf("Le nombre %d n'est pas présent dans le tableau\n", nombre);
  }
  return 0;
}
