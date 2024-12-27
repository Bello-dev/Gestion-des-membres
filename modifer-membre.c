#include "membre.h"

void modifierMembre(membre membreAModifier) {
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int largeurConsole = w.ws_col;
    
    if (membreAModifier != NULL) {
        afficherTitre("MODIFIER LES INFORMATIONS D'UN MEMBRE");
        int choix;
        do {
            
            printf(RED "\n");
            printf("%*sQuelle information souhaitez-vous modifier pour le membre %s %s ?\n"RESET, (largeurConsole -41)/ 2, "", membreAModifier->profil.nom, membreAModifier->profil.prenom);
            printf(CYAN"%*s1. Nom\n", (largeurConsole -41) / 2, "");
            printf("%*s2. Prénom\n", (largeurConsole - 41) / 2, "");
            printf("%*s3. Sexe\n", (largeurConsole - 41) / 2, "");
            printf("%*s4. Âge\n", (largeurConsole -41)/2, "");
            printf("%*s5. Rôle\n", (largeurConsole - 41) / 2, "");
            printf("%*s6. Matricule\n", (largeurConsole -41) / 2, "");
            printf("%*s7. Montant d'adhésion\n", (largeurConsole  - 41) / 2, "");
            printf("%*s8. Numéro de téléphone\n", (largeurConsole -41) / 2, "");
            printf("%*s9. Adresse de résidence\n", (largeurConsole -41) / 2, "");
            printf("%*s10. Adresse mail\n", (largeurConsole  - 41) / 2, "");
            printf("%*s0. Quitter\n", (largeurConsole - 41) / 2, "");
            printf("%*sVotre choix : "RESET, (largeurConsole - 41) / 2, "");
            scanf("%d", &choix);
            switch (choix) {
                case 1:
                    
                    printf(YELLOW"Nouveau nom : "RESET);
                    scanf("%s", membreAModifier->profil.nom);
                    break;
                case 2:
                    printf(CYAN"Nouveau prénom : "RESET);
                    scanf("%s", membreAModifier->profil.prenom);
                    break;
                case 3:
                    printf(CYAN"Nouveau sexe (M/F) : "RESET);
                    scanf(" %c", &membreAModifier->profil.sexe);
                    break;
                case 4:
                    printf(CYAN"Nouvel âge : "RESET);
                    scanf("%d", &membreAModifier->profil.age);
                    break;
                case 5:
                    printf(CYAN"Nouveau rôle : "RESET);
                    scanf("%s", membreAModifier->role);
                    break;
                case 6:
                    printf(CYAN"Nouveau matricule : "RESET);
                    scanf("%s", membreAModifier->matricule);
                    break;
                case 7:
                    printf(CYAN"Nouveau montant d'adhésion : "RESET);
                    scanf("%f", &membreAModifier->montant_paye);
                    break;
                case 8:
                    printf(CYAN"Nouveau numéro de téléphone : "RESET);
                    scanf("%s", membreAModifier->coordonnee->numero_telephone);
                    break;
                case 9:
                    printf(CYAN"Nouvelle adresse de résidence : "RESET);
                    scanf("%s", membreAModifier->coordonnee->adresse_residence);
                    break;
                case 10:
                    printf(CYAN"Nouvelle adresse mail : "RESET);
                    scanf("%s", membreAModifier->coordonnee->adresse_mail);
                    break;
                
                case 0:
                    printf(GREEN"Modification terminée...\n"RESET);
                    sleep(1);
                    break;
                default:
                    printf(RED"Choix invalide. Veuillez choisir à nouveau.\n"RESET);
            }
        } while (choix != 0);
    }
}