#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t condition;
int tour = 0;

void *bonjour(void *arg){
  for(int i=0; i<50; i++){
    pthread_mutex_lock(&mutex);
    while(tour!=0){
      pthread_cond_wait(&condition, &mutex);
    }
    printf("Bonjour\n");
    tour = 1;
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

void *aurevoir(void *arg){
  for(int i=0; i<50; i++){
    pthread_mutex_lock(&mutex);
    while(tour!=1){
      pthread_cond_wait(&condition, &mutex);
    }
    printf("Au revoir\n");
    tour = 0;
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t thread1, thread2;
  int ret;

  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&condition, NULL);

  ret = pthread_create(&thread1, NULL, bonjour, NULL);
  if(ret != 0){
    perror("Erreur de création du thread Bonjour");
    exit(1);
  }

  ret = pthread_create(&thread2, NULL, aurevoir, NULL);
  if(ret!=0){
    perror("Erreur de création du thread Au revoir");
    exit(1);
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&condition);

  return 0;
}
    
  
