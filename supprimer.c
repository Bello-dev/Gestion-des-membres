#include "membre.h"

//Fonction supprimerMembre
void supprimerMembre(membre *listeMembres, char matricule[]) {
    membre prec = NULL;
    membre courant = *listeMembres;

    if (courant == NULL) {
        printf(RED"Liste vide\n"RESET);
        return;
    }

    // Parcourir la liste jusqu'à trouver le membre avec le matricule donné
    while (courant != NULL && strcmp(courant->matricule, matricule) != 0) {
        prec = courant;
        courant = courant->next;
    }

    // Si le membre avec le matricule donné est trouvé, le supprimer
    if (courant != NULL) {
        if (prec == NULL) {
            *listeMembres = courant->next;
        } else {
            prec->next = courant->next;
        }

        // Libérer les horaires associés au membre
        horaire horaireCourant = courant->horaire;
        while (horaireCourant != NULL) {
            horaire tempHoraire = horaireCourant;
            horaireCourant = horaireCourant->next;
            free(tempHoraire);
        }

        // Libérer les coordonnées associées au membre
        free(courant->coordonnee);

        free(courant);
        printf(RED"suppressiondu membre...\n"RESET);
        sleep(2);
        printf(GREEN"Le membre avec le matricule %s a été supprimé.\n"RESET, matricule);
        sleep(1);
    } else {
        printf(RED"Aucun membre avec le matricule %s n'a été trouvé.\n"RED, matricule);
        sleep(1);
    }
}

//libererMembres
void libererMembres(membre listeMembres) {
    membre temp;
    while (listeMembres != NULL) {
        temp = listeMembres;
        listeMembres = (listeMembres)->next;
        
        // Libérer les horaires associés au membre
        horaire horaireCourant = temp->horaire;
        while (horaireCourant != NULL) {
            horaire tempHoraire = horaireCourant;
            horaireCourant = horaireCourant->next;
            free(tempHoraire);
        }
        
        // Libérer les coordonnées associées au membre
        free(temp->coordonnee);
        
        free(temp);
    }
}