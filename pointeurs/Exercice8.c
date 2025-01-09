#include <stdio.h>

int main(){
  int tableau[8] = {12, 78, 19, 97, 34, 67, 134, 0};
  int *pointeur = tableau;
  int plus_grand = *pointeur;
  int plus_petit = *pointeur;

  for(int i=0; i<8; i++){
    if(*(pointeur+i) > plus_grand){
      plus_grand = *(pointeur+i);
    }
    if(*(pointeur+i) < plus_petit){
      plus_petit = *(pointeur+i);
    }
  }

  printf("Le plus grand nombre du tableau est : %d\n", plus_grand);
  printf("Le plus petit nombre du tableau est : %d\n", plus_petit);
  return 0;
}
