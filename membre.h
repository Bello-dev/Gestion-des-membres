#ifndef __MEMBRE_H__
#define __MEMBRE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>


#define MAX 50
//Le propriétaire doit définir le montant d'adhésion pour tous les membres 
#define montant_adhesion 15000

static int numeroMembre = 1;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct Horaire {
    char jour[MAX];
    char heure_debut[MAX];
    char heure_fin[MAX];
    struct Horaire* next;
} Horaire;

typedef struct Profil {
    char nom[MAX];
    char prenom[MAX];
    char sexe;
    int age;
} Profil;

typedef struct Coordonnee {
    char numero_telephone[MAX];
    char adresse_residence[MAX];
    char adresse_mail[MAX];
} Coordonnee;

typedef struct Membre {
    int numero;
    Profil profil;
    char role[MAX];
    char matricule[MAX];
    float montant_paye;
    struct Coordonnee *coordonnee;
    struct Horaire *horaire;
    struct Membre* next;
} Membre;

typedef struct Membre *membre;
typedef struct Horaire *horaire;

void ajouterMembre(membre *listeMembres);
void afficherMembres(membre listeMembres);
void afficherProfil(membre unMembre);
void afficherHoraires(membre unMembre);
void libererMembres(membre listeMembres);
void afficherCoordonnees(membre unMembre);
membre rechercherMembre(membre listeMembres, char matricule[MAX]);
void supprimerMembre(membre *listeMembres, char matricule[]) ;
void sauvegarderMembres(membre listeMembres);
void gererMontantAdhesion(membre listeMembres);
void restaurerMembres(membre *listeMembres);
void modifierMembre(membre membreAModifier);


float calculerMontantPaye(membre m);

float calculerMontantRestant(membre m);

float montantTotal(membre m);

void afficherMontantRestant(membre listeMembres);

void afficherMembresAyantPayeTotalite(membre listeMembres);

int obtenirLargeurConsole();
void afficherMenu();
void afficherTitre(const char *titre);




#endif