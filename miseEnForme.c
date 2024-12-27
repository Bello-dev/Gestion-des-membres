#include "membre.h"

// Fonction pour obtenir la largeur de la console
int obtenirLargeurConsole() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void afficherTitre(const char *titre) {
    system("clear");
    int largeurConsole = obtenirLargeurConsole();
    int longueurTitre = strlen(titre);
    int padding = (largeurConsole - longueurTitre) / 2;
    
    // Dessiner le cadre supérieur
    for (int i = 0; i < largeurConsole; i++) {
        printf(BLUE "=" RESET);
    }
    printf("\n");
    
    // Dessiner la ligne du titre avec padding pour centrer
    printf(BLUE);
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", titre);
    printf(RESET "\n");
    
    // Dessiner le cadre inférieur
    for (int i = 0; i < largeurConsole; i++) {
        printf(BLUE "=" RESET);
    }
    printf("\n");
}



void afficherMenu() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int largeurConsole = w.ws_col;

    system("clear");
    afficherTitre("MENU PRINCIPAL");
    printf("\n");

    char *options[] = {
        "Que souhaitez-vous faire 👇?\n",
        "1.  Ajouter un membre",
        "2.  Afficher le profil d'un membre",
        "3.  Afficher les coordonnées d'un membre",
        "4.  Afficher les horaires d'un membre",
        "5.  Supprimer un membre du Club",
        "6.  Afficher la liste de tous les membres",
        "7.  Gérer les frais d'adhésion d'un membre",
        "8.  Modifier les informations d'un membre",
        "0.  Quitter"
    };
    char *couleurs[] = {
        YELLOW,
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        GREEN,
        RED
    };
    
    int nbOptions = sizeof(options) / sizeof(options[0]);    
    
    int longueurOption = strlen(options[0]);
        int padding = (largeurConsole - longueurOption) / 2;
        printf("%s", couleurs[0]);
        
            // Centrer la première ligne sans numéro
            for (int j = 0; j < padding; j++) {
                printf(" ");
            }
            printf("%s\n", options[0]);
            
    // Cadre supérieur
    for (int i = 0; i < largeurConsole; i++) {
        printf(CYAN "=" RESET);
    }
    printf("\n");

    for (int i = 1; i < nbOptions; i++) {
        int longueurOption = strlen(options[i]);
        int padding = (largeurConsole - 40) / 2;
        printf("%s", couleurs[i]);
        
        if (i == 0) {
            // Centrer la première ligne sans numéro
            for (int j = 0; j < padding; j++) {
                printf(" ");
            }
            printf("%s\n", options[i]);
        } else {
            // Conserver les numéros alignés et centrer le texte restant
            printf(" ");
           // printf("%d. ", i - 1 == 8 ? 0 : i);
            int longueurPrefixe = 0 + (i - 1 == 8 ? 0 : 1);  // 3 pour "x. " ou "0. "
            for (int j = 0; j < padding; j++) {
                printf(" ");
            }
            printf("%s\n", options[i]);  // Passer le numéro et le point
        }
        printf(RESET);
    }

    // Cadre inférieur
    for (int i = 0; i < largeurConsole; i++) {
        printf(CYAN "=" RESET);
    }
    printf("\n");

    printf("\nVotre choix : ");
}