#include <stdio.h>

int main(){
  int n1, n2, n3;
  int moyenne;
  printf("Veuillez entrer la première note :\n");
  scanf("%d", &n1);
  printf("Veuillez entrer la seconde note :\n");
  scanf("%d", &n2);
  printf("Veuillez entrer la troisième note :\n");
  scanf("%d", &n3);
  moyenne = (n1 + n2 + n3)/3;
  printf("La moyenne de ces trois notes est :%d", moyenne);
  return 0;
  
  
}
