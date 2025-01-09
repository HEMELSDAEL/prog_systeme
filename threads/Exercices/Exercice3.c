#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int Global_bonjour = 0;
int Global_aurevoir = 0;

pthread_mutex_t mutex_bonjour;//Garantit qu'une seule opération d'incrémentation est effectuée à la fois
pthread_mutex_t mutex_aurevoir;//Garantit qu'une seule opération d'incrémentation est effectuée à la fois

void *bonjour(void *arg){
  for(int i=0; i<100; i++){
    printf("Bonjour\n");
    pthread_mutex_lock(&mutex_bonjour);
    Global_bonjour++;
    pthread_mutex_unlock(&mutex_bonjour);
  }
  printf("Le thread Bonjour a terminé\n");
  pthread_exit(NULL);
}

void *aurevoir(void *arg){
  for(int i=0; i<100; i++){
    printf("Au revoir\n");
    pthread_mutex_lock(&mutex_aurevoir);
    Global_aurevoir++;
    pthread_mutex_unlock(&mutex_aurevoir);
  }
  printf("Le thread Au revoir a terminé\n");
  pthread_exit(NULL);
}

int main(){
  pthread_t thread1, thread2;
  int ret;
  pthread_mutex_init(&mutex_bonjour, NULL);
  pthread_mutex_init(&mutex_aurevoir, NULL);
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

  printf("Nombre total de 'Bonjour' comptés : %d\n", Global_bonjour);
  printf("Nombre total de 'Au revoir' comptés : %d\n", Global_aurevoir);

  pthread_mutex_destroy(&mutex_bonjour);
  pthread_mutex_destroy(&mutex_aurevoir);
  return 0;
}
