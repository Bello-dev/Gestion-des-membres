#include "membre.h"

void afficherMembres(membre listeMembres) {
    afficherTitre("LISTE COMPLÈTE DES MEMBRES");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int largeurConsole = w.ws_col;
     

    membre courant = listeMembres;
    if (courant == NULL) {
        printf(RED"Liste vide\n"RESET);
        return;
    }

    while (courant != NULL) {
        // Affichage du numéro centré
        printf(MAGENTA"Numéro : %d\n"RESET, courant->numero);
        
        // Affichage du profil centré
        printf(YELLOW"\tProfil\n"RESET);
        printf(MAGENTA"Nom : \t%s\n", courant->profil.nom);
        printf("Prénom : \t%s\n", courant->profil.prenom);
        printf("Sexe : \t%c\n", courant->profil.sexe);
        printf("Âge : \t%d\n", courant->profil.age);
        printf("Rôle : \t%s\n", courant->role);
        printf("Matricule : \t%s\n", courant->matricule);
        printf("Montant payé : \t%.2f\n"RESET, courant->montant_paye);
        
        // Affichage des coordonnées 
        printf(YELLOW"\tCoordonnées :\n"RESET);
        printf(MAGENTA"- Numéro de téléphone : %s\n", courant->coordonnee->numero_telephone);
        printf("- Adresse de résidence : \t%s\n", courant->coordonnee->adresse_residence);
        printf("- Adresse mail : \t%s\n"RESET, courant->coordonnee->adresse_mail);
        
        // Affichage des horaires centré
        printf(YELLOW"\tHoraires :\n"RESET);
        horaire horaireCourant = courant->horaire;
        while (horaireCourant != NULL) {
            printf(MAGENTA"- Jour : %s, Début : %s, Fin : %s\n", horaireCourant->jour, horaireCourant->heure_debut, horaireCourant->heure_fin);
            horaireCourant = horaireCourant->next;
        }
        printf("\n"RESET);

        // Ligne de séparation centrée
        for (int j = 0; j < largeurConsole; j++) {
                printf(GREEN"~"RESET);
            }
            

        // Passer au prochain membre
        courant = courant->next;
    }
}

//Affichage du Profil d'un Membre
void afficherProfil(membre unMembre) {
    if (unMembre == NULL) {
        printf("Membre non trouvé.\n");
        return;
    }
    
    printf("\tProfil :\n");
    printf("Nom : %s\n", unMembre->profil.nom);
    printf("Prénom : %s\n", unMembre->profil.prenom);
    printf("Sexe : %c\n", unMembre->profil.sexe);
    printf("Âge : %d\n", unMembre->profil.age);
}

//Affichage des Coordonnées d'un Membre
void afficherCoordonnees(membre unMembre) {
    afficherTitre("LES COORDONNÉS DU MEMBRE");
    if (unMembre == NULL || unMembre->coordonnee == NULL) {
        printf(RED"Coordonnées non disponibles pour ce membre.\n"RESET);
        return;
    }
    
    printf(GREEN"\tCoordonnées :\n"RESET);
    printf(CYAN"Numéro de téléphone : %s\n", unMembre->coordonnee->numero_telephone);
    printf("Adresse de résidence : %s\n", unMembre->coordonnee->adresse_residence);
    printf("Adresse mail : %s\n"RESET, unMembre->coordonnee->adresse_mail);
}

//Affichage des Horaires d'un Membre
void afficherHoraires(membre unMembre) {
    afficherTitre("LES HORAIRES DU MEMBRE");
    if (unMembre == NULL || unMembre->horaire == NULL) {
        printf(RED"Horaires non disponibles pour ce membre.\n"RESET);
        return;
    }
    
    printf(GREEN"\tHoraires :\n"RESET);
    horaire horaireCourant = unMembre->horaire;
    while (horaireCourant != NULL) {
        printf(CYAN"- Jour : %s, Début : %s, Fin : %s\n"RESET, horaireCourant->jour, horaireCourant->heure_debut, horaireCourant->heure_fin);
        horaireCourant = horaireCourant->next;
    }
}