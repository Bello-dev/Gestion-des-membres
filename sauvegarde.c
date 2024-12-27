#include "membre.h"

void sauvegarderMembres(membre listeMembres) {
    FILE *fichier = fopen("membres.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, RED"Erreur : impossible d'ouvrir le fichier pour sauvegarder les membres.\n"RESET);
        exit(EXIT_FAILURE);
    }
    
    membre courant = listeMembres;
    while (courant != NULL) {
        fprintf(fichier, "%d %s %s %c %d %s %s %.2f ",
                courant->numero,
                courant->profil.nom,
                courant->profil.prenom,
                courant->profil.sexe,
                courant->profil.age,
                courant->role,
                courant->matricule,
                courant->montant_paye);
        
        // Écriture des coordonnées
        fprintf(fichier, "%s %s %s ",
                courant->coordonnee->numero_telephone,
                courant->coordonnee->adresse_residence,
                courant->coordonnee->adresse_mail);
        
        // Écriture des horaires
        horaire horaireCourant = courant->horaire;
        while (horaireCourant != NULL) {
            fprintf(fichier, "%s %s %s ",
                    horaireCourant->jour,
                    horaireCourant->heure_debut,
                    horaireCourant->heure_fin);
            horaireCourant = horaireCourant->next;
        }
        
        fprintf(fichier, "-\n"); // Délimiteur entre les membres
        courant = courant->next;
    }
    
    fclose(fichier);
}