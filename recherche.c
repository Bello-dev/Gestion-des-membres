#include "membre.h"

//Fonction de Recherche d'un Membre par Matricule
membre rechercherMembre(membre listeMembres, char matricule[MAX]) {
        afficherTitre("RECHERCHE D'UN MEMBRE");
    membre courant = listeMembres;
    while (courant != NULL && strcmp(courant->matricule, matricule) != 0) {
        courant = courant->next;
    }
    
    if (courant == NULL) {
        printf(RED"Aucun membre avec le matricule %s n'a été trouvé.\n"RESET, matricule);
        sleep(3);
        return NULL;
    } else {
        return courant;
    }
}