#include <stdio.h>

int main(){
  int nombre_copies;
  float prix;
  printf("Veuillez entrer un nombre de copies :");
  scanf("%d", &nombre_copies);
  if(nombres_copies<=10){
    prix = nombres_copies * 0.50;
  }
  else if(nombre_copies>10 && nombre_copies<=20){
    prix = nombres_copies * 0.45;
  }
  else{
    prix = nombres_copies * 0.20;
  }
  return prix;
 
  
}
