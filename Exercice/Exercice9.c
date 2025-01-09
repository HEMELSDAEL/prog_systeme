#include <stdio.h>

int main(){
  int nombre1, nombre2, nombre3;
  printf("premier nombre : \n");
  scanf("%d", &nombre1);
  printf("second nombre : \n");
  scanf("%d", &nombre2);
  printf("troisième nombre : \n");
  scanf("%d", &nombre3);
  if(nombre1 > nombre2 && nombre1 > nombre3){
    printf("Le plus grand nombre est :%d\n", nombre1);
  }
  else if(nombre2 > nombre1 && nombre2 > nombre3){
    printf("Le plus grand nombre est :%d\n", nombre2);
  }
  else{
    printf("Le plus grand nombre est :%d\n", nombre3);
  }
  return 0;
  
}
