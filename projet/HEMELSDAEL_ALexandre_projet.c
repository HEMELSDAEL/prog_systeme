#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100
#define MAX_EMPRUNTEURS 50

typedef struct{
  char titre[100];
  char auteur[50];
  int annee;
  char isbn[20];
  int disponible;
} Livre;

typedef struct{
  char nom[50];
  char prenom[50];
  int id;
  char emprunts[5][20];
  int nbEmprunts;
} Emprunteur;

Livre bibliotheque[MAX_LIVRES];
Emprunteur emprunteurs[MAX_EMPRUNTEURS];
int nbLivres = 0;
int nbEmprunteurs = 0;


void ajouterLivre(Livre* tableau, int* nbLivre, char* titre, char* auteur, int annee, char* isbn){
  if(nbLivres >= MAX_LIVRES){
    printf("\nLa bibliothèque est pleine. On ne peut plus stocker de livres\n");
    return;
  }
  Livre nouveauLivre;
  strcpy(nouveauLivre.titre, titre);
  strcpy(nouveauLivre.auteur, auteur);
  nouveauLivre.annee = annee;
  strcpy(nouveauLivre.isbn, isbn);
  nouveauLivre.disponible = 1;
  tableau[nbLivres]=nouveauLivre;
  (nbLivres)++;
  printf("Livre ajouté avec succès : %s\n", titre);
}

void afficherLivresDisponibles(Livre* tableau, int nbLivres){
  printf("\nLivres disponibles: \n");
  for(Livre* ptr=tableau; ptr<tableau+nbLivres; ptr++){
    if(ptr->disponible){
      printf("Titre : %s, Auteur : %s, Année : %d, ISBN : %s\n", ptr->titre, ptr->auteur, ptr->annee, ptr->isbn);
    }
  }
}

void emprunterLivre(Livre* tableau, int nblivres, Emprunteur* emprunteur, char* isbn){
  for(Livre* ptr=tableau; ptr<tableau+nblivres; ptr++){
    if(strcmp(ptr->isbn, isbn) == 0){
      if(ptr->disponible){
	if(emprunteur->nbEmprunts<5){
	  ptr->disponible=0;
	  strcpy(emprunteur->emprunts[emprunteur->nbEmprunts], isbn);
	  emprunteur->nbEmprunts++;
	  printf("\nLe livre %s a été emprunté avec succès \n", ptr->titre);
	}else{
	  printf("L'emprunteur a déjà emprunté 5 livres. Ce qui est la limite d'emprunt\n");
	}
      }
      else{
	printf("Le livre %s n'est pas disponible. Il a déjà été emprunté\n", ptr->titre);
      }
      return;
     }
   }
   printf("Le livre avec l'ISBN %s est introuvable\n", isbn);
}

void retournerLivre(Livre* tableau, int nbLivres, Emprunteur* emprunteur, char* isbn){
  for(Livre* ptr=tableau; ptr<tableau+nbLivres; ptr++){
    if(strcmp(ptr->isbn, isbn)==0){
      if(!ptr->disponible){
	ptr->disponible=1;
	for(int i=0; i<emprunteur->nbEmprunts;i++){
	  if(strcmp(emprunteur->emprunts[i], isbn)==0){
	    for(int j=i; j<emprunteur->nbEmprunts-1; j++){
	      strcpy(emprunteur->emprunts[j], emprunteur->emprunts[j+1]);
	    }
	    emprunteur->nbEmprunts--;
	    printf("Le livre %s a été retourné avec succès\n", ptr->titre);
	    return;
	  }
	}
      }
    }    
  }
  printf("Le livre avec l'ISBN %s n'est pas emprunté ou il est introuvable\n", isbn);
}

void rechercherLivre(Livre* tableau, int nbLivres, char* recherche){
  printf("\nVoici les résultats de la recherche pour le livre recherché \"%s\" :\n", recherche);
  for(Livre* ptr=tableau; ptr<tableau+nbLivres; ptr++){
    if(strstr(ptr->titre, recherche) || strstr(ptr->auteur, recherche)){
      printf("Titre : %s, Auteur : %s, Année : %d, ISBN : %s\n", ptr->titre, ptr->auteur, ptr->annee, ptr->isbn);
    }
  }
}

void afficherEmprunts(Emprunteur* emprunteur){
  printf("\nLivres empruntés par %s %s :\n", emprunteur->prenom, emprunteur->nom);
  if(emprunteur->nbEmprunts==0){
    printf("Aucun livre n'a été emprunté par cet emprunteur\n");
  }else{
    for(int i=0; i<emprunteur->nbEmprunts; i++){
      printf("ISBN : %s\n", emprunteur->emprunts[i]);
    }
  }
}

void afficherEmprunteursParLivre(Livre* tableau, int nbLivres, char* isbn){
  printf("\nLes emprunteurs ayant emprunté le livre avec l'ISBN %s :\n", isbn);
  for(Livre* ptr=tableau; ptr<tableau+nbLivres; ptr++){
    if(strcmp(ptr->isbn, isbn)==0 && !ptr->disponible){
      for(int i=0; i<nbEmprunteurs; i++){
	for(int j=0; j<emprunteurs[i].nbEmprunts; j++){
	  if(strcmp(emprunteurs[i].emprunts[j], isbn)==0){
	    printf("L'emprunteur s'appelle : %s %s\n", emprunteurs[i].prenom, emprunteurs[i].nom);
	  }
	}
      }
    }
  }
}


void supprimerLivre(Livre* tableau, int* nbLivres, char* isbn){
  for(int i=0; i<*nbLivres; i++){
    if(strcmp(tableau[i].isbn, isbn)==0){
      for(int j=i; j<*nbLivres-1; j++){
	tableau[j] = tableau[j+1];
      }
      (*nbLivres)--;
      printf("Le livre avec l'ISBN %s a été supprimé\n", isbn);
      return;
    }
  }
  printf("Le livre avec l'ISBN %s n'a pas été trouvé\n", isbn);
}

void inscrireEmprunteur(Emprunteur* tableau, int* nbEmprunteurs, char* nom, char* prenom){
  if(*nbEmprunteurs >= MAX_EMPRUNTEURS){
    printf("Impossible d'ajouter un nouvel emprunteur, la limite a été atteinte\n");
    return;
  }
  Emprunteur nouvelEmprunteur;
  strcpy(nouvelEmprunteur.nom, nom);
  strcpy(nouvelEmprunteur.prenom, prenom);
  nouvelEmprunteur.id = *nbEmprunteurs+1;
  nouvelEmprunteur.nbEmprunts=0;

  tableau[*nbEmprunteurs] = nouvelEmprunteur;
  (*nbEmprunteurs)++;
  printf("Le nouvel emprunteur a été ajouté avec succès : %s %s\n",nom, prenom);
}

void afficherTousEmprunts(Emprunteur* tableau, int nbEmprunteurs){
  printf("\nLa liste des emprunts de tous les emprunteurs :\n");
  for(int i=0; i<nbEmprunteurs; i++){
    printf("L'emprunteur : %s %s\n", tableau[i].prenom, tableau[i].nom);
    for(int j=0; j<tableau[i].nbEmprunts; j++){
      printf("L'ISBN : %s\n", tableau[i].emprunts[j]);
    }
  }
}
  
void afficherMenu(){
  printf("\n----------MENU----------\n");
  printf("1. Ajouter un livre\n");
  printf("2. Afficher les livres disponibles\n");
  printf("3. Emprunter un livre\n");
  printf("4. Retourner un livre\n");
  printf("5. Rechercher un livre\n");
  printf("6. Afficher les emprunts d'un emprunteur\n");
  printf("7. Afficher tous les emprunts\n");
  printf("8. Quitter\n");
  printf("\nChoississez une option : ");
}

void Choix(int choix){
  char isbn[20], titre[100], auteur[50], recherche[100];
  char nom[50], prenom[50];
  int annee;
  switch(choix){
   case 1:
     printf("Entrez le titre du livre : ");
     fgets(titre, sizeof(titre), stdin);
     titre[strcspn(titre, "\n")] = '\0';

     printf("Entrez l'auteur : ");
     fgets(auteur, sizeof(auteur), stdin);
     titre[strcspn(titre, "\n")] = '\0';

     printf("Entrez l'année de parution : ");
     scanf("%d", &annee);
     getchar();

     printf("Entrez l'ISB du livre : ");
     fgets(isbn, sizeof(isbn), stdin);
     isbn[strcspn(isbn, "\n")] = '\0';

     ajouterLivre(bibliotheque, &nbLivres, titre, auteur, annee, isbn);
     break;
   case 2 :
     afficherLivresDisponibles(bibliotheque, nbLivres);
     break;
   case 3 :
     printf("Entrez l'ISBN du livre à emprunter : ");
     fgets(isbn, sizeof(isbn), stdin);
     isbn[strcspn(isbn, "\n")] = '\0';
     printf("Entrez le nom de l'emprunteur : ");
     fgets(nom, sizeof(nom), stdin);
     nom[strcspn(nom, "\n")] = '\0';
     printf("Entrez le prénom de l'emprunteur : ");
     fgets(prenom, sizeof(prenom), stdin);
     prenom[strcspn(prenom, "\n")] = '\0';
     int emprunteurId = -1;
     for(int i=0; i<nbEmprunteurs; i++){
       if(strcmp(emprunteurs[i].prenom, prenom) == 0 && strcmp(emprunteurs[i].nom, nom)==0){
	 emprunteurId = i;
	 break;
       }
     }
     if(emprunteurId != -1){
       afficherEmprunts(&emprunteurs[emprunteurId]);
     }else{
       printf("Emprunteur introuvable\n");
     }
     break;
   case 7:
     afficherTousEmprunts(emprunteurs, nbEmprunteurs);
     break;
  case 8:
    printf("Au revoir !\n");
    break;
  default :
    printf("Choix invalide \n");
    break;
  }
}      

int main(){
  int choix;

  Emprunteur emprunteur1 = {"HEMELSDAEL", "Alexandre", 1, {}, 0};
  Emprunteur emprunteuse = {"COLLIN", "Garance", 2, {}, 0};
  emprunteurs[0] = emprunteur1;
  emprunteurs[1] = emprunteuse;
  nbEmprunteurs = 2;
  
  ajouterLivre(bibliotheque, &nbLivres, "Les Misérables", "Victor HUGO", 1862, "123456789");
  ajouterLivre(bibliotheque, &nbLivres, "Voyage au centre de la terre", "Jules Verne", 1864, "987654321");

  do{
    afficherMenu();
    scanf("%d", &choix);
    getchar();
    Choix(choix);
  }while(choix!=8);

  return 0;
}
    
