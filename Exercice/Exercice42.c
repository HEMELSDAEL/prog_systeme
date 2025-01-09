#include <stdio.h>

int main(){
  int n1, n2, produit;
  printf("Entrer nombre 1 :");
  scanf("%d", &n1);
  printf("Entrer nombre 2 :");
  scanf("%d", &n2);
  produit = n1 * n2;
  if(produit<0){
    printf("Le produit est négatif\n");
  }
  else if(produit>0){
    printf("Le produit est positif\n");
  }
  else{
    printf("Le produit est nul\n");
  }
}
