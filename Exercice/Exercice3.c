#include <stdio.h>

int main(){
  int num1, num2;
  int moyenne;
  printf("Veuillez rentrer votre premier nombre : \n");
  scanf("%d", &num1);
  printf("Veuillez rentrer votre second nombre : \n");
  scanf("%d", &num2);
  moyenne = num1 + num2;
  printf("La somme des deux nombres est : %d\n", moyenne);
  return moyenne;
}
