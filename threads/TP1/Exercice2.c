#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 3

void *Affiche(void *arg);

int main(){
  pthread_t tid[N];
  int ret, i;
  for(i=0; i<N; i++){
    ret = pthread_create(&tid[i], NULL, Affiche, (void*)(long int)i);
    if(ret<0){
      perror("Erreur de pthread_create \n");
      exit(1);
    }
  }
  for(i=0; i<N; i++){
    pthread_join(tid[i], NULL);
  }
  return 0;
}

void *Affiche(void *arg){
  long int i=(long int) arg;
  printf("Je suis le thread %ld \n\n\n", i);
  pthread_exit(NULL);
}
