#include <stdio.h>

int main() {
    int i, j, nombre;
    int nombres[10]; 
    int max, min;
    printf("Veuillez entrer 10 nombres entiers :\n");

    for (i = 0; i < 10; i++) {
        printf("Entrez le %dème nombre : ", i + 1);
        scanf("%d", &nombres[i]);
    }


    max = nombres[0];
    min = nombres[0];
    
    for (i = 1; i < 10; i++) {
        if (nombres[i] > max) {
            max = nombres[i];
        }
        if (nombres[i] < min) {
            min = nombres[i];
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
	  if (nombres[i] > nombres[j]){
                int temp = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = temp;
            }
        }
    }

    printf("\nLe plus grand nombre est : %d\n", max);
    printf("Le plus petit nombre est : %d\n", min);

    printf("\nLes nombres triés dans l'ordre croissant sont :\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", nombres[i]);
    }

    printf("\n");

    return 0;
}
