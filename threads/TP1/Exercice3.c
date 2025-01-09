#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *Affiche(void *arg);

int main(){
  int N, ret, i;
  printf("Entrez le nombre de threads à créer : ");
  scanf("%d", &N);
  pthread_t *tid = (pthread_t *)malloc(N * sizeof(pthread_t));
  if(tid==NULL){
    perror("Erreur d'allocation de mémoire");
    exit(1);
  }
  
  for(i=0; i<N; i++){
    ret = pthread_create(&tid[i], NULL, Affiche, (void*)(long int)(i+1));
    if(ret<0){
      perror("Erreur de pthread_create \n");
      exit(1);
    }
  }
  for(i=0; i<N; i++){
    pthread_join(tid[i], NULL);
  }
  free(tid);
  return 0;
}

void *Affiche(void *arg){
  long int i=(long int) arg;
  printf("Je suis le thread %ld \n\n\n", i);
  pthread_exit(NULL);
}
