#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PERSONNES 50
#define MAX_CHAINE 30
#define MAX_COMPTES 50

typedef struct{
  char titulaire[MAX_CHAINE];
  char numeroCompte[20];
  float solde;
} CompteBancaire;


typedef struct{
  char nom[MAX_CHAINE];
  char prenom[MAX_CHAINE];
  char telephone[10];
  char email[MAX_CHAINE];
  CompteBancaire comptes[MAX_PERSONNES];
  int nbComptes;
} Personne;

Personne repertoire[MAX_PERSONNES];
CompteBancaire comptes[MAX_COMPTES];
int nbPersonnes = 0;
int nbComptes = 0;

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

void Creer_Compte(){
  if(nbComptes >= MAX_COMPTES){
    printf("Le nombre maximum de comptes a été atteint\n");
    return;
  }
  printf("Création d'un nouveau compte bancaire :\n");
  printf("Titulaire : \n");
  scanf("%s", comptes[nbComptes].titulaire);
  printf("Numéro de compte : ");
  scanf("%s", comptes[nbComptes].numeroCompte);
  comptes[nbComptes].solde = 0.0;
  nbComptes++;
  printf("Compte créé avec succès !\n");
}

void Afficher_Compte() {
    char numeroCompte[20];
    printf("Entrez le numéro de compte à afficher : ");
    scanf("%s", numeroCompte);
    for (int i = 0; i < nbComptes; i++) {
        if (strcmp(comptes[i].numeroCompte, numeroCompte) == 0) {
            printf("Informations du compte :\n");
            printf("Titulaire : %s\n", comptes[i].titulaire);
            printf("Numéro de compte : %s\n", comptes[i].numeroCompte);
            printf("Solde : %.2f\n", comptes[i].solde);
            return;
        }
    }
    printf("Compte non trouvé.\n");
}

void Depot() {
    char numeroCompte[20];
    float montant;
    printf("Entrez le numéro de compte pour le dépôt : ");
    scanf("%s", numeroCompte);
    printf("Entrez le montant à déposer : ");
    scanf("%f", &montant);
    for (int i = 0; i < nbComptes; i++) {
        if (strcmp(comptes[i].numeroCompte, numeroCompte) == 0) {
            comptes[i].solde += montant;
            printf("Dépôt effectué. Nouveau solde : %.2f\n", comptes[i].solde);
            return;
        }
    }
    printf("Compte non trouvé.\n");
}

void Retrait() {
    char numeroCompte[20];
    float montant;
    printf("Entrez le numéro de compte pour le retrait : ");
    scanf("%s", numeroCompte);
    printf("Entrez le montant à retirer : ");
    scanf("%f", &montant);
    for (int i = 0; i < nbComptes; i++) {
        if (strcmp(comptes[i].numeroCompte, numeroCompte) == 0) {
            if (comptes[i].solde >= montant) {
                comptes[i].solde -= montant;
                printf("Retrait effectué. Nouveau solde : %.2f\n", comptes[i].solde);
            } else {
                printf("Fonds insuffisants.\n");
            }
            return;
        }
    }
    printf("Compte non trouvé.\n");
}

void Virement(){
  char compteSource[20], compteDest[20];
  float montant;
  int trouveSource=0, trouveDest=0;

  printf("Entrez le numéro du compte source : ");
  scanf("%s", compteSource);
  printf("Entrez le numéro du compte destinataire : ");
  scanf("%s", compteDest);
  printf("Entrez le montant à transférer : ");
  scanf("%f", &montant);

  if(montant <= 0){
    printf("Le montant du virement doit être positif.\n");
    return;
  }

  for (int i = 0; i < nbComptes; i++) {
    if (strcmp(comptes[i].numeroCompte, compteSource) == 0) {
      trouveSource = 1;
      if (comptes[i].solde < montant) {
        printf("Solde insuffisant sur le compte source.\n");
        return;
      }
      comptes[i].solde -= montant;
    }

    if (strcmp(comptes[i].numeroCompte, compteDest) == 0) {
      trouveDest = 1;
      comptes[i].solde += montant;
    }
  }

  if (trouveSource && trouveDest) {
    printf("Virement effectué avec succès !\n");
    printf("Le nouveau solde du compte source est : %.2f\n", comptes[trouveSource].solde);
    printf("Le nouveau solde du compte destinataire est : %.2f\n", comptes[trouveDest].solde);
  } else {
    if (!trouveSource) {
      printf("Compte source non trouvé.\n");
    }
    if (!trouveDest) {
      printf("Compte destinataire non trouvé.\n");
    }
  }
}


int main(){
  int Action;
  while(1){
    printf("Quelle action voulez-vous faire ? :\n");
    printf("*Ajouter une personne        (1)\n");
    printf("*Afficher le répertoire      (2)\n");
    printf("*Rechercher une personne     (3)\n");
    printf("*Retirer une personne        (4)\n");
    printf("*Triez le répertoire         (5)\n");
    printf("*Compter personne            (6)\n");
    printf("*Gérer les comptes bancaires (7)\n");
    printf("*Terminer                    (8)\n");
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
      int gestionComptes;
      while(1){
	printf("Que voulez-vous faire avec les comptes bancaires ? :\n");
	printf("1. Créer un compte\n");
	printf("2. Afficher un compte\n");
	printf("3. Déposer de l'argent\n");
	printf("4. Retirer de l'argent\n");
	printf("5. Faire un virement\n");
	printf("6. Retour\n");
	printf("Votre choix : ");
	scanf("%d", &gestionComptes);
	if (gestionComptes == 1) {
	  Creer_Compte();
	}
	else if (gestionComptes == 2) {
	  Afficher_Compte();
	}
	else if (gestionComptes == 3) {
	  Depot();
	}
	else if (gestionComptes == 4) {
	  Retrait();
	}
	else if (gestionComptes == 5){
	  Virement();
	}
	else if (gestionComptes == 6){
	  break;
	}
	else{
	  printf("Choix invalide, réessayez\n");
	}
      }
    }
    else if (Action == 8){
      break;
    }
    else{
      printf("Choix invalide, réessayez\n");
    }
    printf("\n");
  }
  printf("Programme terminé\n");
  return 0;
}
    
      
