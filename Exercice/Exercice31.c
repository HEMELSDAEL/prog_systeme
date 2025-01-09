#include <stdio.h>

int main(){
  int km;
  float essence;
  float consommation;
  printf("Veuillez entrer une distance en km : ");
  scanf("%d", &km);
  printf("Veuillez entrer une consommation de carburant : ");
  scanf("%f", &essence);
  consommation = km / essence;
  printf("La consommation de votre trajet est de : %.2f\n ", consommation);
  return 0;
  
}
