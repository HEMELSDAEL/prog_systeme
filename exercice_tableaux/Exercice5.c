#include <stdio.h>

int main(){
  int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i;

  printf("Les nombres pairs sont : \n");
  for(i=0; i<10; i++){
    if(tab[i]%2==0){
      printf("%d ", tab[i]);
    }
  }

  printf("\nLes nombres impairs sont : \n");
  for(i=0; i<10; i++){
    if(tab[i]%2!=0){
      printf("%d ", tab[i]);
    }
  }

  printf("\n");
  return 0;
}
