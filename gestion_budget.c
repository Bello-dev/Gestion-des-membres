#include "membre.h"

//gererMontantAdhesion
void gererMontantAdhesion(membre listeMembres) {
    char matricule[MAX];
    float nouveauMontant;
    
    printf("Matricule du membre : ");
    scanf("%s", matricule);
    membre membreAModifier = rechercherMembre(listeMembres, matricule);
    if (membreAModifier != NULL) {
        float montantRestant = montant_adhesion - membreAModifier->montant_paye;
        int m=montant_adhesion;
        printf("Montant total d'adhésion : %d\n", m);
        printf("Montant déjà payé : %.2f\n", membreAModifier->montant_paye);
        printf("Montant restant à payer : %.2f\n", montantRestant);
        
        if (montantRestant > 0) {
            printf("Combien souhaitez-vous ajouter au montant déjà payé ? ");
            scanf("%f", &nouveauMontant);
            
            membreAModifier->montant_paye += nouveauMontant;
            
            if (membreAModifier->montant_paye >= montant_adhesion) 
            
                printf("Le membre a payé la totalité de l'adhésion.\n");
            else
                printf("Montant d'adhésion mis à jour avec succès.\n");
        } 
        else 
            printf("Le membre a déjà payé la totalité de l'adhésion.\n");
    }
}

float montantTotal(membre m){
    float total = 0;
    while(m != NULL){
        total += m->montant_paye;
        m = m->next;
    }
    return total;
}

float calculerMontantPaye(membre m) {
    return m->montant_paye;
}

float calculerMontantRestant(membre m) {
    return montant_adhesion - m->montant_paye;
}


void afficherMontantRestant(membre listeMembres) {
    membre membreCourant = listeMembres;
    afficherTitre("Montant Restant pour chaque membre");
    while (membreCourant != NULL) {
        float montantRestant = calculerMontantRestant(membreCourant);
        printf(RED"Membre %d (%s %s) doit encore : %.2f\n"RESET, 
               membreCourant->numero, 
               membreCourant->profil.nom, 
               membreCourant->profil.prenom, 
               montantRestant);
        
        membreCourant = membreCourant->next;
    }
}

void afficherMembresAyantPayeTotalite(membre listeMembres) {
    membre membreCourant = listeMembres;
    
    afficherTitre("Membres ayant payé la totalité du montant d'adhésion");
    while (membreCourant != NULL) {
        if (membreCourant->montant_paye >= montant_adhesion) {
            printf(GREEN"Membre %d : %s %s\n"RESET, 
                   membreCourant->numero, 
                   membreCourant->profil.nom, 
                   membreCourant->profil.prenom);
        }
        membreCourant = membreCourant->next;
    }
}