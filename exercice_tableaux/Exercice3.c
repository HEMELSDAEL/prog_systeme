#include <stdio.h>

int main(){
  int tab[10] = {12, 1, 54, 89, 2, 234, 789, 567, 23, 86};
  int i, recherche;
  int count=0;
  printf("Veuillez entrer un nombre à chercher :\n");
  scanf("%d", &recherche);
  for(i=0; i<10; i++){
    if(tab[i] == recherche){
      count++;
    }
  }
  if(count>0){
    printf("Le nombre %d apparaît %d fois dans le tableau\n", recherche, count);
  }else{
    printf("Le nombre %d n'apparaît pas le tableau\n", recherche);
  }
  return 0;
}
