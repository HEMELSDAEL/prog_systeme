#include <stdio.h>

int main(){
  int i=0;
  do{
    printf("2 x %d = %d\n", i, 2*i);
    i++;
  }
  while(i<=10);
  return 0;
}
