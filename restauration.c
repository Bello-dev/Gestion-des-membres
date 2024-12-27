#include "membre.h"

void restaurerMembres(membre *listeMembres) {
    FILE *fichier = fopen("membres.txt", "r");
    if (fichier == NULL) {
        fprintf(stderr, RED"Fichier introuvable: impossible d'ouvrir le fichier pour restaurer les membres.\n"RESET);
        return;
    }

    // Trouver le dernier membre existant pour continuer l'incrémentation
    membre dernierMembre = *listeMembres;
    if (dernierMembre != NULL) {
        while (dernierMembre->next != NULL) {
            dernierMembre = dernierMembre->next;
        }
    }

    while (!feof(fichier)) {
        membre nouveauMembre = (membre)malloc(sizeof(struct Membre));
        if (nouveauMembre == NULL) {
            fprintf(stderr, RED"Erreur : impossible d'allouer la mémoire pour le membre.\n"RESET);
            exit(EXIT_FAILURE);
        }

        if (fscanf(fichier, "%d", &nouveauMembre->numero) != 1) {
            free(nouveauMembre);
            break;
        }

        fscanf(fichier, "%s %s %c %d %s %s %f ",
               nouveauMembre->profil.nom,
               nouveauMembre->profil.prenom,
               &nouveauMembre->profil.sexe,
               &nouveauMembre->profil.age,
               nouveauMembre->role,
               nouveauMembre->matricule,
               &nouveauMembre->montant_paye);

        // Allocation de la structure Coordonnee et lecture des données
        nouveauMembre->coordonnee = (Coordonnee *)malloc(sizeof(Coordonnee));
        if (nouveauMembre->coordonnee == NULL) {
            fprintf(stderr, RED"Erreur : impossible d'allouer la mémoire pour Coordonnee.\n"RESET);
            exit(EXIT_FAILURE);
        }
        fscanf(fichier, "%s %s %s ",
               nouveauMembre->coordonnee->numero_telephone,
               nouveauMembre->coordonnee->adresse_residence,
               nouveauMembre->coordonnee->adresse_mail);

        // Restauration des horaires
        Horaire *dernierHoraire = NULL;
        char buffer[MAX];
        fscanf(fichier, "%s", buffer);
        while (strcmp(buffer, "-") != 0) {
            Horaire *nouvelHoraire = (Horaire *)malloc(sizeof(Horaire));
            if (nouvelHoraire == NULL) {
                fprintf(stderr, RED"Erreur : impossible d'allouer la mémoire pour Horaire.\n"RESET);
                exit(EXIT_FAILURE);
            }
            strcpy(nouvelHoraire->jour, buffer);
            fscanf(fichier, "%s %s", nouvelHoraire->heure_debut, nouvelHoraire->heure_fin);
            nouvelHoraire->next = NULL;

            // Ajout de l'horaire à la liste des horaires du membre
            if (nouveauMembre->horaire == NULL) {
                nouveauMembre->horaire = nouvelHoraire;
            } else {
                dernierHoraire->next = nouvelHoraire;
            }
            dernierHoraire = nouvelHoraire;

            fscanf(fichier, "%s", buffer);
        }

        // Incrémentation du numéro de membre
        if (dernierMembre == NULL) {
            nouveauMembre->numero = 1;
        } else {
            nouveauMembre->numero = dernierMembre->numero + 1;
        }

        // Ajouter le nouveau membre à la fin de la liste
        nouveauMembre->next = NULL;
        if (*listeMembres == NULL) {
            *listeMembres = nouveauMembre;
        } else {
            dernierMembre->next = nouveauMembre;
        }

        dernierMembre = nouveauMembre; // Mettre à jour le dernier membre ajouté
    }

    fclose(fichier);
}