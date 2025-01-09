#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PERSONNES 50
#define MAX_CHAINE 30

typedef struct{
  char nom[MAX_CHAINE];
  char prenom[MAX_CHAINE];
  char telephone[10];
  char email[MAX_CHAINE];
} Personne;

Personne repertoire[MAX_PERSONNES];
int nbPersonnes = 0;

void Creer_Enregistrement(){
  if(nbPersonnes >=MAX_PERSONNES){
    printf("Le répertoire est plein !\n");
    return;
  }
  printf("Ajout d'une personne :\n");
  printf("Nom : ");
  scanf("%s", repertoire[nbPersonnes].nom);
  printf("Prénom : ");
  scanf("%s", repertoire[nbPersonnes].prenom);
  printf("Téléphone : ");
  scanf("%s", repertoire[nbPersonnes].telephone);
  printf("Email : ");
  scanf("%s", repertoire[nbPersonnes].email);
  nbPersonnes++;
  printf("Personne ajoutée avec succès !\n");
}

void Afficher_Repertoire(){
  if(nbPersonnes == 0){
    printf("Le répertoire est vide et ne contient personne\n");
  }
  for(int i=0; i<nbPersonnes; i++){
     printf("Personne %d;\n", i+1);
     printf("Nom : %s\n", repertoire[i].nom);
     printf("Prénom : %s\n", repertoire[i].prenom);
     printf("Téléphone : %s\n", repertoire[i].telephone);
     printf("Email : %s\n", repertoire[i].email);
     printf("\n");
   }
}

void Recherche_telephone(){
  char telephone[10];
  printf("Entrez le numéro de téléphone à rehcercher :");
  scanf("%s", telephone);
  for(int i=0; i<nbPersonnes; i++){
    if(strcmp(repertoire[i].telephone, telephone)==0){
      printf("Personne trouvée :\n");
      printf("Personne %d;\n", i+1);
      printf("Nom : %s\n", repertoire[i].nom);
      printf("Prénom : %s\n", repertoire[i].prenom);
      printf("Téléphone : %s\n", repertoire[i].telephone);
      printf("Email : %s\n", repertoire[i].email);
      return;
    }
  }

  printf("Personne non trouvée dans le répertoire\n");
}

void Retirer(){
  char nom[MAX_CHAINE];
  printf("Entrez le nom de la personne à retirer :");
  scanf("%s", nom);
  for(int i=0; i<nbPersonnes; i++){
    if(strcmp(repertoire[i].nom, nom) == 0){
      for(int j=i; j<nbPersonnes-1; j++){
	repertoire[j]=repertoire[j+1];
      }
      nbPersonnes--;
      printf("Personne supprimée avec succès !\n");
      return;
    }
  }
  printf("La personne n'a pas été trouvée dans le répertoire\n");
}

//Utilisation du tri par bulles
void Trier_Repertoire(){
  for(int i=0; i<nbPersonnes-1; i++){
    for(int j=i+1; j<nbPersonnes; j++){
      if(strcmp(repertoire[i].nom, repertoire[j].nom)>0){
	Personne temp = repertoire[i];
	repertoire[i] = repertoire[j];
	repertoire[j] = temp;
      }
    }
  }
  printf("Répertoire trié par nom\n");
}

void compter_nbPersonnes(){
  printf("Il y a actuellement %d personnes dans le répertoire\n", nbPersonnes);
}

int main(){
  int Action;
  while(1){
    printf("Quelle action voulez-vous faire ? :\n");
    printf("*Ajouter une personne    (1)\n");
    printf("*Afficher le répertoire  (2)\n");
    printf("*Rechercher une personne (3)\n");
    printf("*Retirer une personne    (4)\n");
    printf("*Triez le répertoire     (5)\n");
    printf("*Compter personne        (6)\n");
    printf("*Terminer                (7)\n");
    printf("Votre choix : ");
    scanf("%d", &Action);

    if(Action==1){
      Creer_Enregistrement();
    }
    else if (Action==2){
      Afficher_Repertoire();
    }
    else if (Action == 3){
      Recherche_telephone();
    }
    else if (Action == 4){
      Retirer();
    }
    else if (Action == 5){
      Trier_Repertoire();
    }
    else if (Action == 6){
      compter_nbPersonnes();
    }
    else if (Action == 7){
      break;
    }
    else{
      printf("CHoix invalide, réessayez\n");
    }
    printf("\n");
  }
  printf("Programme terminé\n");
  return 0;
}
    
      
