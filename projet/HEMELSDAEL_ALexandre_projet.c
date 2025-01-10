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
Utilisateur utilisateurs[MAX_EMPRUNTEURS];
int nbLivres = 0;
int nbEmprunteurs = 0;


void ajouterLivre(Livre* tableau, int* nbLivre, char* titre, char* auteur, int annee, char* isbn){
  if(*nbLivres >= MAX_LIVRES){
    printf("La bibliothèque est pleine. On ne peut plus stocker de livres\n");
    return;
  }
  Livre nouveauLivre;
  strcpy(nouveauLivre.titre, titre);
  strcpy(nouveauLivre.auteur, auteur);
  nouveauLivre.annee = annee;
  strcpy(nouveauLivre.isbn, isbn);
  nouveauLivre.disponible = 1;
  tableau[*nbLivres]=nouveauLivre;
  (*nbLivres)++;
  printf("Livre ajouté avec succès : %s\n", titre);
}

void afficherLivresDisponibles(Livre* tableau, int nbLivres){
  printf("\nLivres disponibles :\n");
  for(Livre* ptr=tableau; ptr<tableau+nblivres; ptr++){
    if(ptr->disponbile){
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
	  printf("Le livre %s a été emprunté avec succès \n", ptr->titre);
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

int main(){
  ajouterLivre(bibliotheque, &nbLivres, "Les Misérables", "Victor HUGO", 1862, "123456789");
  ajouterLivre(bibliotheque, &nbLivres, "Voyage au centre de la terre", "Jules Verne", 1864, "987654321");

  afficherLivresDisponibles(bibliotheque, nbLivres);
  Emprunteur emprunteur = {"HEMELSDAEL", "Alexandre", 1, {}, 0};
  Emprunteur emprunteuse = {"COLLIN", "Garance", 2, {}, 0};

  emprunterLivre(bibliotheque, nbLivres, &emprunteur, "123456789");

  afficherLivresDisponibles(bibliotheque, nbLivres);

  return 0;
}
    
