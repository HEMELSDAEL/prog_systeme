#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *bonjour(void *arg){
  for(int i=0; i<100; i++){
    printf("Bonjour\n");
  }
  pthread_exit(NULL);
}

void *aurevoir(void *arg){
  for(int i=0; i<100; i++){
    printf("Au revoir\n");
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t thread1, thread2;
  int ret;
  ret = pthread_create(&thread1, NULL, bonjour, NULL);
  if(ret !=0){
    perror("Erreur lors de la création du thread Bonjour");
    exit(1);
  }

  ret = pthread_create(&thread2, NULL, aurevoir, NULL);
  if(ret!=0){
    perror("Erreur lors de la création du thread Au revoir");
    exit(1);
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  return 0;
}
