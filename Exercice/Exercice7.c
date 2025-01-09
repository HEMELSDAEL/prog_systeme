#include <stdio.h>

int main(){
  int nombre1;
  int fact=1;
  printf("Veuillez entrer un nombre pour calculer le factoriel : \n");
  scanf("%d", &nombre1);
  if(nombre1==1){
    printf("La valeur du factoriel est de :%d ", fact);
  }
  for(int i=1; i<=nombre1; i++){
      fact = fact * i;
  }
  printf("Le résultat est :%d\n", fact);
   
	
}
