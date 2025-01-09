#include <stdio.h>

int main(){
  int i;
  printf("Entrer un nombre : ");
  scanf("%d", &i);
  for(int j=1; j<=i; j++){
      for(int x=1; x<=j; x++){
	printf("%d", j);
      }
      printf("\n");
  }
  return 0;
      
}
