#include <stdio.h>

int main(){
  int tableau1[5] = {1, 2, 3, 4, 5};
  int tableau2[5] = {1, 2, 3, 4, 5};
  int *pointeur1 = tableau1;
  int *pointeur2 = tableau2;
  int idem = 1;

  for(int i=0; i<5; i++){
    if(*(pointeur1+i) != *(pointeur2+i)){
      idem = 0;
      break;
    }
  }

  if(idem){
    printf("Les deux tableaux sont identiques\n");
  }else{
    printf("Les deux ne sont pas identiques\n");
  }
  return 0;
}
