#include <stdio.h>

int main(){
  int i=0;
  int nombre;
  int somme;
  printf("Veuillez entrer un nombre :\n");
  scanf("%d", &nombre);
  while(i<nombre){
    somme = i+nombre;
    i++;
  }
  printf("La somme des nombres allant de 1 jusuq'à %d est:\n ", nombre, somme);
  return 0;
    
}
