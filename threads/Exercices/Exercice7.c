#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int variable_partagee = 0;
pthread_mutex_t mutex;

void *incrementer(void *arg){
  while(1){
    pthread_mutex_lock(&mutex);
    variable_partagee++;
    pthread_mutex_unlock(&mutex);
    usleep(100000);
  }
  pthread_exit(NULL);
}

void *afficheur(void *arg){
  int derniere_valeur = -1;
  while(1){
    pthread_mutex_lock(&mutex);
    if(variable_partagee != derniere_valeur){
      derniere_valeur = variable_partagee;
      printf("Variable partagée : %d\n", derniere_valeur);
    }
    pthread_mutex_unlock(&mutex);
    usleep(50000);
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t thread1, thread2;
  pthread_mutex_init(&mutex, NULL);
  if(pthread_create(&thread1, NULL, incrementer, NULL) !=0){
    perror("Erreur lors de la création du thread incrementer");
    exit(1);
  }

  if(pthread_create(&thread2, NULL, afficheur, NULL) !=0){
    perror("Erreur lors de la création du thread afficheur");
    exit(1);
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  pthread_mutex_destroy(&mutex);
  return 0;
}
      
    
