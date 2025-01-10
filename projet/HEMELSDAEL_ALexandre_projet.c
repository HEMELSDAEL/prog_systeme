#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100 //Maximum de livre dans la bibliothèque
#define MAX_EMPRUNTEURS 50 //Maximum d'emprunteur dans la bibliothèque

typedef struct{
  char titre[100];//titre du livre
  char auteur[50];//Auteur du livre
  int annee;//Année de parution du livre
  char isbn[20];//Numéro ISBN du livre
  int disponible;//disponibilité (1 = oui, 0 = non)
} Livre;//Représente la structure d'un livre

typedef struct{
  char nom[50];//Nom de l'emprunteur
  char prenom[50];//Prénom de l'emprunteur
  int id;//Id unique de l'emprunteur
  char emprunts[5][20];//ISBN des livres empruntés (maximum 5 livres)
  int nbEmprunts;//Nombre de livre actuellement empruntés
} Emprunteur;//Représente la structure d'un emprunteur à la bibliothèque

Livre bibliotheque[MAX_LIVRES];//Tableau contenant les livres
Emprunteur emprunteurs[MAX_EMPRUNTEURS];//Tableau contenant les emprunteurs
int nbLivres = 0;//Nombre de livres dans la bibliothèque
int nbEmprunteurs = 0;//Nombre d'emprunteurs inscrits


void ajouterLivre(Livre* tableau, int* nbLivre, char* titre, char* auteur, int annee, char* isbn){//Fonction qui va ajouter un livre à la biblitohèque avec ses caractéristiques
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

//Affiche la liste des livres disponibles avant l'emprunt
void afficherLivresDisponibles(Livre* tableau, int nbLivres){
  printf("\nLivres disponibles: \n");
  for(Livre* ptr=tableau; ptr<tableau+nbLivres; ptr++){
    if(ptr->disponible){
      printf("Titre : %s, Auteur : %s, Année : %d, ISBN : %s\n", ptr->titre, ptr->auteur, ptr->annee, ptr->isbn);
    }
  }
}

//Permet à l'emprunteur d'emprunter un livre qui est disponible dans la bibliothèque
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

//Permet à l'emprunteur de retourner un livre qu'il a emprunté
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

//Recherche un livre en fonction du titre ou de l'auteur
void rechercherLivre(Livre* tableau, int nbLivres, char* recherche){
  printf("\nVoici les résultats de la recherche pour le livre recherché \"%s\" :\n", recherche);
  for(Livre* ptr=tableau; ptr<tableau+nbLivres; ptr++){
    if(strstr(ptr->titre, recherche) || strstr(ptr->auteur, recherche)){
      printf("Titre : %s, Auteur : %s, Année : %d, ISBN : %s\n", ptr->titre, ptr->auteur, ptr->annee, ptr->isbn);
    }
  }
}

//Affiche la liste des livres empruntés en fonction du nom et prénom de l'emprunteur
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

//Affiche la la liste des empruntés ayant emprunté un livre spécifique en fonction du titre du livre
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

//Supprime un livre de la bibliothèque
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

//Ajoute un emprunteur à la bibliothèque
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

//Affiche la liste des emprunts de tous les emprunteurs de la bibliothèque
void afficherTousEmprunts(Emprunteur* tableau, int nbEmprunteurs){
  printf("\nLa liste des emprunts de tous les emprunteurs :\n");
  for(int i=0; i<nbEmprunteurs; i++){
    printf("L'emprunteur : %s %s\n", tableau[i].prenom, tableau[i].nom);
    for(int j=0; j<tableau[i].nbEmprunts; j++){
      printf("L'ISBN : %s\n", tableau[i].emprunts[j]);
    }
  }
}

//Affiche la liste des emprunteurs inscrits
void afficherEmprunteurs(Emprunteur* tableau, int nbEmprunteurs){
  printf("\nLa liste des emprunteurs :\n");
  for(int i=0; i<nbEmprunteurs; i++){
    printf("ID : %d, Nom : %s, Prénom : %s\n", tableau[i].id, tableau[i].nom, tableau[i].prenom);
  }
}

//Supprime un emprunteur de la bibliothèque
void supprimerEmprunteur(Emprunteur* tableau, int* nbEmprunteurs, int id){
  for(int i=0; i<*nbEmprunteurs; i++){
    if(tableau[i].id == id){
      for(int j=i; j<*nbEmprunteurs-1; j++){
	tableau[j] = tableau[j+1];
      }
      (*nbEmprunteurs)--;
      printf("L'emprunteur avec l'ID %d a été supprimé\n", id);
      return;
    }
  }
  printf("L'emprunteur avec l'ID %d n'a pas été trouvé\n", id);
}

//Affiche un menu interactif pour l'utilisateur
void afficherMenu(){
  printf("\n----------MENU----------\n");
  printf("1. Ajouter un livre\n");
  printf("2. Afficher les livres disponibles\n");
  printf("3. Emprunter un livre\n");
  printf("4. Retourner un livre\n");
  printf("5. Rechercher un livre\n");
  printf("6. Afficher les emprunts d'un emprunteur\n");
  printf("7. Afficher tous les emprunts\n");
  printf("8. Ajouter un emprunteur\n");
  printf("9. Afficher tous les emprunteurs\n");
  printf("10. Supprimer un emprunteur\n");
  printf("11. Quitter\n");
  printf("\nChoississez une option : ");
}

//Permet d'exécuter l'action correspondante au choix de l'utilisateur
void Choix(int choix){
  char isbn[20], titre[100], auteur[50], recherche[100];
  char nom[50], prenom[50];
  int annee, id;
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
  case 4:
    printf("Entrez l'ISBN du livre à retourner : ");
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';
          
    printf("Entrez le prénom de l'emprunteur : ");
    fgets(prenom, sizeof(prenom), stdin);
    prenom[strcspn(prenom, "\n")] = '\0'; 
            
    printf("Entrez le nom de l'emprunteur : ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0'; 
           
    emprunteurId = -1;
    for (int i = 0; i < nbEmprunteurs; i++) {
     if (strcmp(emprunteurs[i].prenom, prenom) == 0 && strcmp(emprunteurs[i].nom, nom) == 0) {
       emprunteurId = i;
       break;
     }
    }
            
    if (emprunteurId != -1) {
      retournerLivre(bibliotheque, nbLivres, &emprunteurs[emprunteurId], isbn);
    } else {
      printf("Emprunteur introuvable.\n");
    }
    break;
    
  case 5: 
    printf("Entrez le titre ou l'auteur à rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche, "\n")] = '\0';
    
    rechercherLivre(bibliotheque, nbLivres, recherche);
    break;
    
  case 6: 
    printf("Entrez le prénom de l'emprunteur : ");
    fgets(prenom, sizeof(prenom), stdin);
    prenom[strcspn(prenom, "\n")] = '\0';  
    
    printf("Entrez le nom de l'emprunteur : ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';  
    
    emprunteurId = -1;
    for (int i = 0; i < nbEmprunteurs; i++) {
      if (strcmp(emprunteurs[i].prenom, prenom) == 0 && strcmp(emprunteurs[i].nom, nom) == 0) {
	emprunteurId = i;
	break;
      }
    }
    
    if (emprunteurId != -1) {
      afficherEmprunts(&emprunteurs[emprunteurId]);
    } else {
      printf("Emprunteur introuvable.\n");
    }
	   break;
  case 7:
    afficherTousEmprunts(emprunteurs, nbEmprunteurs);
    break;
  case 8:
    printf("Entrez le prénom de l'emprunteur : ");
    fgets(prenom, sizeof(prenom), stdin);
    prenom[strcspn(prenom, "\n")] = '\0';
    printf("Entrez le nom de l'emprunteur : ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';
    inscrireEmprunteur(emprunteurs, &nbEmprunteurs, nom, prenom);
    break;
  case 9:
    afficherEmprunteurs(emprunteurs, nbEmprunteurs);
    break;
  case 10:
    printf("Entrez l'ID de l'emprunteur à supprimer : ");
    scanf("%d", &id);
    supprimerEmprunteur(emprunteurs, &nbEmprunteurs, id);
    break;
  case 11:
    printf("Au revoir !\n");
    break;
  default:
    printf("Votre choix est invalide. Essayez à nouveau\n");	  
  }
}      

int main(){
  int choix;
  
  ajouterLivre(bibliotheque, &nbLivres, "Les Misérables", "Victor HUGO", 1862, "123456789");
  ajouterLivre(bibliotheque, &nbLivres, "Voyage au centre de la terre", "Jules Verne", 1864, "987654321");

  do{
    afficherMenu();
    scanf("%d", &choix);
    getchar();
    Choix(choix);
  }while(choix!=11);

  return 0;
}
    
