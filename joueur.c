#include <stdio.h>
#include <stdlib.h>

#include "data.h"

#define NOM_FICHIER "joueurs.bin"


static paramJoueurs joueurs[30];
static int nombreJoueurs;
static paramJoueurs enCoursDeJeu[2];

/**
 * définis le nom, le mdp, l'age et le score du joueur qui va joueur 
 * @param nombreJ : position du joueur a récupérer 
 */
void setJ1(int nombreJ) {
    strcpy(enCoursDeJeu[0].nomJ, joueurs[nombreJ].nomJ);
    strcpy(enCoursDeJeu[0].mdp, joueurs[nombreJ].mdp);
    enCoursDeJeu[0].age = joueurs[nombreJ].age;
    enCoursDeJeu[0].score = joueurs[nombreJ].score;
}

/**
 * récupère le nom du joueur principal
 * @param nom : pointeur de tableau
 */
void getJ1(char nom[]) {
    strcpy(nom, enCoursDeJeu[0].nomJ);
}

/**
 * si le l'utilisateur ne se connecte pas, définis le joueur 1 sur J1
 */
void joueurInconnuJ1() {
    strcpy(enCoursDeJeu[0].nomJ, "Le joueur J1");
    strcpy(enCoursDeJeu[0].mdp, "");
    enCoursDeJeu[0].age = 0;
    enCoursDeJeu[0].score = 0;
}

/**
 * si le l'utilisateur ne se connecte pas, définis le joueur 2 sur J2
 */
void joueurInconnuJ2() {
    strcpy(enCoursDeJeu[0].nomJ, "J2");
    strcpy(enCoursDeJeu[0].mdp, "");
    enCoursDeJeu[0].age = 0;
    enCoursDeJeu[0].score = 0;
}

/**
 * renvoie le nombre de joueurs
 * @return : nbr de joueurs
 */
int getNombreJoueurs() {
    return nombreJoueurs;
}

/**
 * renvoie le nom du joueurs
 * @param nombreJ
 * @param nomJ
 * @return 
 */
int getNomJoueur(int nombreJ, char nomJ[]) {
    strcpy(nomJ, joueurs[nombreJ].nomJ);
}

int getMotPass(int nombreJ, char mdp[]) {
    strcpy(mdp, joueurs[nombreJ].mdp);
}

/**
 * ajoute un joueur au compteur
 */
void setNombreJoueurs() {
    nombreJoueurs += 1;
}

void setNomJoueurs(int nombre, paramJoueurs player) {
    strcpy(joueurs[nombre].nomJ, player.nomJ);
    strcpy(joueurs[nombre].mdp, player.mdp);
    joueurs[nombre].age = player.age;
    joueurs[nombre].date.annee = player.date.annee;
    joueurs[nombre].date.jour = player.date.jour;
    joueurs[nombre].date.mois = player.date.mois;
    joueurs[nombre].date.heure = player.date.heure;
    joueurs[nombre].date.minute = player.date.minute;
    joueurs[nombre].date.seconde = player.date.seconde;
    joueurs[nombre].score = 0;
    joueurs[nombre].age = player.age;
    joueurs[nombre].dateScore.annee = 0;
    joueurs[nombre].dateScore.jour = 0;
    joueurs[nombre].dateScore.mois = 0;
    joueurs[nombre].dateScore.heure = 0;
    joueurs[nombre].dateScore.minute = 0;
    joueurs[nombre].dateScore.seconde = 0;
    //printf("\n joueur : %s",joueurs[nombre].nomJ);
}

void base_enregistrement() {
    FILE *BDD;
    int i = 0;

    BDD = fopen(NOM_FICHIER, "wb+");

    fwrite(joueurs, sizeof (paramJoueurs), nombreJoueurs, BDD);

    fclose(BDD);
}

void base_recup() {
    FILE *BDD;
    int i;

    BDD = fopen(NOM_FICHIER, "rb");
    nombreJoueurs = base_nombreJoueurs();
    fread(joueurs, sizeof (paramJoueurs), nombreJoueurs, BDD);
    /*for (i = 0; i < nombreJoueurs; i++) {
        printf("\n(%s)", joueurs[i].nomJ);
    }*/
}

void scoreAugm(int nombre, int nombreManche) {
    time_t heure;
    struct tm * ptm;

    time(&heure);
    ptm = gmtime(&heure);

    joueurs[nombre].dateScore.annee = ptm->tm_year + 1900;
    joueurs[nombre].dateScore.mois = ptm->tm_mon + 1;
    joueurs[nombre].dateScore.jour = ptm->tm_mday;
    joueurs[nombre].dateScore.heure = ptm->tm_hour + 1;
    joueurs[nombre].dateScore.minute = ptm->tm_min;
    joueurs[nombre].dateScore.seconde = ptm->tm_sec;

    joueurs[nombre].score = joueurs[nombre].score + 21 - nombreManche;
    //printf("\n%s score : %d", joueurs[nombre].nomJ, joueurs[nombre].score);
}

void scoreDim(int nombre) {
    time_t heure;
    struct tm * ptm;

    time(&heure);
    ptm = gmtime(&heure);

    joueurs[nombre].dateScore.annee = ptm->tm_year + 1900;
    joueurs[nombre].dateScore.mois = ptm->tm_mon + 1;
    joueurs[nombre].dateScore.jour = ptm->tm_mday;
    joueurs[nombre].dateScore.heure = ptm->tm_hour + 1;
    joueurs[nombre].dateScore.minute = ptm->tm_min;
    joueurs[nombre].dateScore.seconde = ptm->tm_sec;

    joueurs[nombre].score = joueurs[nombre].score - 5;
}

int getScore(int nombreJ) {
    return joueurs[nombreJ].score;
}

void getListeJoueursScore(paramJoueurs listeScore[]) {
    int i = 0;

    for (i = 0; i < nombreJoueurs; i++) {
        strcpy(listeScore[i].nomJ, joueurs[i].nomJ);
        listeScore[i].score = joueurs[i].score;

        listeScore[i].dateScore.annee = joueurs[i].dateScore.annee;
        listeScore[i].dateScore.mois = joueurs[i].dateScore.mois;
        listeScore[i].dateScore.jour = joueurs[i].dateScore.jour;
        
        listeScore[i].dateScore.heure = joueurs[i].dateScore.heure;  
        listeScore[i].dateScore.minute = joueurs[i].dateScore.minute;
        listeScore[i].dateScore.seconde = joueurs[i].dateScore.seconde;
        
    }

}