#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *afficher_identifiant(void *arg) {
    int id = *(int *)arg; 
    for (int i = 0; i < 5; i++) {
        printf("Thread %d - itération %d\n", id, i + 1);
    }
    free(arg); 
    pthread_exit(NULL); 
}

int main() {
    int n, ret;
    printf("Combien de threads souhaitez-vous créer ? ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Le nombre de threads doit être supérieur à 0.\n");
        return 1;
    }

    pthread_t *threads = malloc(n * sizeof(pthread_t));
    if (threads == NULL) {
        perror("Erreur d'allocation mémoire");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        int *id = malloc(sizeof(int));
        if (id == NULL) {
            perror("Erreur d'allocation mémoire");
            free(threads);
            return 1;
        }
        *id = i + 1; 
        ret = pthread_create(&threads[i], NULL, afficher_identifiant, id);
        if (ret != 0) {
            perror("Erreur de création du thread");
            free(threads);
            free(id);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);

    printf("Tous les threads ont terminé.\n");
    return 0;
}
