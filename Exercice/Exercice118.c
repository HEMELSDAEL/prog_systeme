#include <stdio.h>

int binomial(int n, int k){
  if(k==0 || k==n){
    return 1;
  }
  return binomial(n-1, k-1) + binomial(n-1, k);
}

int main(){
  int  nb_lignes;
  printf("Entrer le nombre de lignes :");
  scanf("%d", &nb_lignes);
  for(int i=0; i < nb_lignes; i++){
    for(int j=0; j<nb_lignes-i-1; j++){
      printf(" ");
    }
    for(j=0; j <=i; j++){
      printf("%d", binomial(i, j));
    }
    printf("\n");
  }
  return 0;
  
}
