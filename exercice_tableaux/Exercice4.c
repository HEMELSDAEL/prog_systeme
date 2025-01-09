#include <stdio.h>

int main(){
  int tab[10] = {12, 1, 5, 8, 2, 4, 9, 7, 17, 10};
  int i;
  int moyenne, somme=0, notes_sup=0;
  for(i=0; i<10; i++){
    somme = somme+i;
  }
  moyenne = somme/10;
  printf("La moyenne de ces notes est : %d\n", moyenne);
  printf("Les notes supérieurs à cette moyenne sont : \n");
  for(i=0; i<10; i++){
    if(tab[i] > moyenne){
      printf("%d ", tab[i]);
      notes_sup = notes_sup + tab[i];
    }
  }
  printf("\nLa somme des notes supérieures à la moyenne est : %d\n", notes_sup);
  return 0;
}
