#include <stdio.h>

int main(){
  int tab[10] = {1, 2, 2, 3, 3, 7, 4, 5, 6, 6};
  int i, j;
  int repete=0;

  printf("Voici les nombres répétés dans le tableau : \n");
  for(i=0; i<10; i++){
    for(j = i+1; j<10; j++){
      if(tab[i]==tab[j]){
	printf("%d\n", tab[i]);
	repete = 1;
	break;
      }
    }
  }
  if(!repete){
    printf("Aucun nombre est répété dans le tableau\n");
  }
  return 0;
  
}
