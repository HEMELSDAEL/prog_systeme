#include <stdio.h>

int main(){
  int score;
  printf("Veuillez entrer une note :");
  scanf("%d", &score);
  if(score>0 && score<=10){
    printf("NOT GOOD !!!\n");
  }
  else if(score > 10){
    printf("GOOD !!!\n");
  }
  else{
    printf("Votre note rentrée est invalide\n");
  }
  return 0;
}
