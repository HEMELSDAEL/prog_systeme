#include <stdio.h>

int main(){
  int n;
  printf("Veuillez entrer un nombre pour la table de multiplication :\n");
  scanf("%d", &n);
  for(int i=0; i<=10; i++){
    printf("%d x %d = %d\n", n, i, n*i);
  }
  return 0;
    
}
