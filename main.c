#include "membre.h"

int main() 
{
    membre listeMembres = NULL;
    int choix;
    char matricule[MAX];
    afficherTitre("YOU ARE WELCOME");
    sleep(2);
    system("clear");
    afficherTitre("BIENVENUE");
    sleep(2);
    float T;
    int c,d;
    system("clear");

    restaurerMembres(&listeMembres); // Restaurer les membres depuis le fichier
    // dernierNumeroMembre est maintenant initialisé avec le plus grand numéro de membre existant

    do {
        
        afficherMenu();
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                system("clear");
                ajouterMembre(&listeMembres);
                sauvegarderMembres(listeMembres);
                break;
            case 2:
                system("clear");
                printf(YELLOW "Matricule du membre dont vous voulez afficher le profil : " RESET);
                scanf("%s", matricule);
                afficherProfil(rechercherMembre(listeMembres, matricule));
                c = getchar();
                break;
            case 3:
                system("clear");
                printf(YELLOW "Matricule du membre dont vous voulez afficher les coordonnées : " RESET);
                scanf("%s", matricule);
                afficherCoordonnees(rechercherMembre(listeMembres, matricule));
                c = getchar();
                break;
            case 4:
                system("clear");
                printf(YELLOW "Matricule du membre dont vous voulez afficher les horaires : " RESET);
                scanf("%s", matricule);
                afficherHoraires(rechercherMembre(listeMembres, matricule));
                c = getchar();
                break;
            case 5:
                system("clear");
                printf(YELLOW "Matricule du membre à supprimer : " RESET);
                scanf("%s", matricule);
                supprimerMembre(&listeMembres, matricule);
                sauvegarderMembres(listeMembres);
                break;
            case 6:
                system("clear");
                afficherMembres(listeMembres);
                c = getchar();
                d = getchar();
                break;
            case 7:
                
                system("clear");
                 int f;
                afficherTitre("GESTION DES FRAIS D'ADHÉSION DES MEMBRES");
                sleep(2);
                do{
                    afficherTitre("MENU");
                    printf(CYAN"\t1. Ajouter une tranche de payement\n");
                    printf("\t2. Afficher les membres ayant payés la totalité\n");
                    printf("\t3. Afficher le montant restant pour chaque membre\n");
                    printf("\t4. Afficher le budget total payé par tous\n"RESET);
                    printf(RED"\t0. Quitter\n"RESET);
                    printf(WHITE"Votre choix : "RESET);
                    scanf("%d", &f);
        
                    switch(f){
                        case 1 : 
                            gererMontantAdhesion(listeMembres);
                            sauvegarderMembres(listeMembres);
                            c = getchar();
                            break;
                        case 2 :
                            afficherMembresAyantPayeTotalite(listeMembres);
                            int g = getchar();
                            sleep(2);
                            break;
                        case 3 : 
                            afficherMontantRestant(listeMembres);
                            c = getchar();
                            break;
                        case 4 :
                            T = montantTotal(listeMembres);  
                            afficherTitre("Le budget totale payé par tous les membres");
                            printf(YELLOW"%.2f FCFA\n"RESET, T);
                            sleep(3);
                            d = getchar();
                            break;
                        case 0 : 
                            printf(RED"Modifications terminées\n"RESET); 
                            c = getchar();
                            break;
                        default :
                            printf(RED"Choix non valide 🤯\n"RESET);   
                            sleep(1);
                            c = getchar();
                    }
                }while(f!=0);
                c = getchar();
                break;
            case 8:
                system("clear");
                printf(YELLOW "Matricule du membre à modifier : " RESET);
                scanf("%s", matricule);
                modifierMembre(rechercherMembre(listeMembres, matricule));
                sauvegarderMembres(listeMembres);
                c = getchar();
                break;
            case 0:
                system("clear");
                printf(YELLOW "Sauvegarde des données en cours...\n" RESET);
                sleep(3);
                sauvegarderMembres(listeMembres); // Sauvegarder les membres dans le fichier avant de quitter
                libererMembres(listeMembres); // Libérer la mémoire allouée pour les membres
                system("clear");
                printf(GREEN "Fermeture du programme...\n" RESET);
                sleep(2);
                break;
            default:
                system("clear");
                printf(RED "Choix invalide. 😔Veuillez choisir à nouveau.\n" RESET);
                sleep(2);
                d = getchar();
        }
    } while (choix != 0);
    
    afficherTitre("GOODBYE 👋🏾");
    sleep(2);
    system("clear");
    afficherTitre("À BIENTÔT🤗");
    sleep(2);
    c = getchar();
    system("clear");
    return 0;
}