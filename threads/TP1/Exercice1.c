#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Affiche(void *arg);

pthread_t tid;

int main(){
  pthread_t tid;
  int ret;
  printf("Ceci est le main : pid = %d \n\n", getpid());
  ret = pthread_create(&tid, NULL, Affiche, NULL);
  if(ret<0){
    perror("Erreur de pthread_create \n");
    exit(1);
  }
  pthread_join(tid, NULL);
  return 0;
}

void *Affiche(void *arg){
  printf("Je suis le thread fils, mon pid = %d\n\n", getpid());
  pthread_exit(NULL);
}
