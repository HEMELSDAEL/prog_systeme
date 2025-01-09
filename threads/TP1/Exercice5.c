#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Affiche(void *arg);
void *Triple(void *arg);
void *Factorielle(void *arg);

int main(){
  int N, ret, i, nb;

  printf("Entrez le nombre de threads à créer : \n");
  scanf("%d", &N);

  printf("Entrez un nombre pour calculer le triple et la factorielle : \n");
  scanf("%d", &nb);
  pthread_t *tid = (pthread_t *)malloc((N+2) * sizeof(pthread_t));

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

  ret = pthread_create(&tid[N], NULL, Triple, (void *)(long int)nb);
  if(ret<0){
    perror("Erreur de pthread_create pour le triple\n");
    exit(1);
  }

  ret = pthread_create(&tid[N+1], NULL, Factorielle, (void *)(long int)nb);
  if(ret<0){
    perror("Erreur de pthread_create pour la factorielle\n");
    exit(1);
  }

  for(i=0; i<N+2; i++){
    pthread_join(tid[i], NULL);
  }

  free(tid);
  return 0;
}

void *Affiche(void *arg){
  long int i = (long int)arg;
  printf("Je suis le thread %ld\n\n", i);
  pthread_exit(NULL);
}

void *Triple(void *arg){
  int nb = (int)(long int)arg;
  printf("Le triple de %d est %d\n\n", nb, nb*3);
  pthread_exit(NULL);
}

void *Factorielle(void * arg){
  int nb = (int)(long int)arg;
  int fact = 1;
  for(int i=1; i<=nb; i++){
    fact = fact*i;
  }
  printf("La factorielle de %d est %d\n\n", nb, fact);
  pthread_exit(NULL);
}
