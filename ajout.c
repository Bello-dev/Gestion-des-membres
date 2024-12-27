#include "membre.h"

void ajouterMembre(membre *listeMembres) {
    membre nouveauMembre = (membre)malloc(sizeof(struct Membre));
    if (nouveauMembre == NULL) {
        fprintf(stderr, RED"Erreur : impossible d'allouer la mémoire.\n"RESET);
        exit(EXIT_FAILURE);
    }

    nouveauMembre->coordonnee = (Coordonnee*)malloc(sizeof(Coordonnee));
    if (nouveauMembre->coordonnee == NULL) {
        fprintf(stderr, RED"Erreur : impossible d'allouer la mémoire pour les coordonnées.\n"RESET);
        exit(EXIT_FAILURE);
    }
    afficherTitre("AJOUT D'UN MEMBRE");
    printf(MAGENTA"Nom : "CYAN);
    scanf("%s", nouveauMembre->profil.nom);
    printf(MAGENTA"Prénom : "CYAN);
    scanf("%s", nouveauMembre->profil.prenom);
    printf(MAGENTA"Sexe (M/F) : "CYAN);
    scanf(" %c", &nouveauMembre->profil.sexe);
    printf(MAGENTA"Âge : "CYAN);
    scanf("%d", &nouveauMembre->profil.age);
    printf(MAGENTA"Rôle : "CYAN);
    scanf("%s", nouveauMembre->role);
    printf(MAGENTA"Matricule : "RESET);
    scanf("%s", nouveauMembre->matricule);
    printf(MAGENTA"Montant d'adhésion : "CYAN);
    scanf("%f", &nouveauMembre->montant_paye);

    // Ajout des coordonnées
    printf(MAGENTA"Numéro de téléphone : "CYAN);
    scanf("%s", nouveauMembre->coordonnee->numero_telephone);
    printf("Adresse de résidence : ");
    scanf("%s", nouveauMembre->coordonnee->adresse_residence);
    printf(MAGENTA"dresse mail : "CYAN);
    scanf("%s", nouveauMembre->coordonnee->adresse_mail);

    nouveauMembre->horaire = NULL;
    int nbJours;
    printf(YELLOW"Combien de jours souhaitez-vous ajouter pour les horaires ? "BLUE);
    scanf("%d", &nbJours);

    for (int i = 0; i < nbJours; i++) {
        Horaire *nouvelHoraire = (Horaire*)malloc(sizeof(Horaire));
        if (nouvelHoraire == NULL) {
            fprintf(stderr, "Erreur : impossible d'allouer la mémoire pour l'horaire.\n");
            exit(EXIT_FAILURE);
        }

        printf(CYAN"Jour : "MAGENTA);
        scanf("%s", nouvelHoraire->jour);
        printf(CYAN"Heure de début : "MAGENTA);
        scanf("%s", nouvelHoraire->heure_debut);
        printf(CYAN"Heure de fin : "MAGENTA);
        scanf("%s", nouvelHoraire->heure_fin);

        nouvelHoraire->next = NULL;

        // Si la liste des horaires est vide, le nouvel horaire devient le premier
        if (nouveauMembre->horaire == NULL) {
            nouveauMembre->horaire = nouvelHoraire;
        } else {
            // Sinon, ajouter à la fin de la liste des horaires
            Horaire *dernierHoraire = nouveauMembre->horaire;
            while (dernierHoraire->next != NULL) {
                dernierHoraire = dernierHoraire->next;
            }
            dernierHoraire->next = nouvelHoraire;
        }
    }
    int nbr=1;
    // Ajouter le nouveau membre à la fin de la liste principale
    nouveauMembre->next = NULL;
    if (*listeMembres == NULL) 
    {
        nouveauMembre->numero = nbr +1;
        *listeMembres = nouveauMembre;
    } else 
    {
        membre dernierMembre = *listeMembres;
        while (dernierMembre->next != NULL) 
        {    nbr++;
            dernierMembre = dernierMembre->next;
        }
        nouveauMembre->numero = nbr +1;
        dernierMembre->next = nouveauMembre;
    }
}