#include <stdio.h>

int main(){
  int tab[10] = {1, 2, 2, 3, 3, 3, 4, 5, 6, 7};
  int i, j;
  int compteur[10]={0};
  int deja_compte[10]={0};

  for(i=0; i<10; i++){
    if(deja_compte[i]==1){
      continue;//si le nombre a déjà été compté je ne fais l'opération
    }
    
    for(j=i+1; j<10; j++){
      if(tab[i] == tab[j]){
	compteur[i]++;
	deja_compte[i]=1;
      }
    }
  }

  printf("Voici les nombres répétés avec leur fréquence :\n");
  int aucune_repet = 1;
  for(i=0; i<10; i++){
    if(compteur[i] > 0){
      printf("%d : %d fois\n", tab[i], compteur[i]+1);
      aucune_repet = 0;
    }
  }
  
  if(aucune_repet){
    printf("Aucun nombre est répété dans ce tableau\n");
  }
  return 0;
}
