#include <stdio.h>

int main(){
  int nombre, i=1;
  printf("Veuillez donner un nombre : ");
  scanf("%d", &nombre);
  while(nombre/10 != 0){
    nombre = nombre/10;
    i = i+1;
  }
  printf("Le nombre de chiffres est %d\n", i);
  return 0;
}
