#include <stdio.h>

int main(){
  int nombre, inverser=0, reste;

  printf("Entrer un nombre : ");
  scanf("%d", &nombre);
  while(nombre != 0){
    reste = nombre % 10;
    inverser = inverser * 10 + reste;
    nombre = nombre / 10;
  }
  printf("L'entier inversé est : %d\n", inverser);
  return 0;
}
