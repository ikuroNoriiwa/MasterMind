#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data.h"
#include "couleur.h"

#define RETOUR_LIGNE 4
#define TAB 5

/**
 * permet au joueur de choisir les pions qu'il souhaite jouer 
 * @param c : 1, 2 ou 3 pour pions a cacher, a choisir ou IA 
 * @param pions
 */
void choisir4Couleurs(int c, int pions[]) {
    const short lCouleur[8] = {ROUGE, JAUNE, VERT, BLEU, VERTFLUO, BLANC, POURPRE, TURQUOISE};
    int i = 0, temp, verif = FALSE;

    affichVidePion(1);

    for (i = 0; i < 4; i++) {
        while (verif == FALSE) {
            gotoxy(5, 10 + i);
            temp = couleurPion(i, c);
            if ((temp >= 1)&&(temp <= 8)) {
                verif = verifPionsDifferents(pions, i, lCouleur[temp - 1]);
                if (verif) {
                    pions[i] = lCouleur[temp - 1];
                }
            }
        }
        verif = FALSE;
    }
}

/**
 * recherche si le pions qui vient d'etre joué n'est pas deja présent dans la manche
 * @param code : numéro des 4 couleurs en cours
 * @param indice : couleurs déjà saisies (allant de 0 à 3)
 * @param couleur : couleur en cours de vérification
 * @return : TRUE 
 */
int verifPionsDifferents(int code[4], int indice, int couleur) {
    int verif = TRUE, j = 0;

    for (j = 0; j < indice; j++) {
        if (couleur == code[j]) {
            affichVidePion(3);
            verif = FALSE;
            break;
        }
    }
    return verif;
}

/**
 * fonctoin aléatoire pour des couleurs random
 * @return : un nombre entre 1 et 8 
 */
int aleatFunct() {
    int ret = 0;

    ret = rand() % 8 + 1;
    return ret;
}

int feuxArtifice(int choix) {
    int ret = 0;
    switch (choix) {
        case 1:
            ret = rand() % 69 + 4;
            return ret;
            
            break;
        case 2:
            ret = rand() % 50 + 9;
            return ret;
            
            break;
    }
}

/**
 * sert a montrer si ole pions est de la bonne couleur et s'il est bien placé 
 * @param compteurManche : le numéro de la manche en cours 
 */
void trouverLesPions(int compteurManche) {
    master jeuDepart, jeuEnCours[NOMBRE_DE_TENTATIVE];
    int i = 0;
    //récupère les pions de départ et de la manche en cours  
    for (i = 0; i < 4; i++) {
        jeuDepart.couleur[i] = getPionsDepart(i);
        jeuEnCours[compteurManche].couleur[i] = getPionsEnCours(compteurManche, i);
    }

    affichVidePion(RETOUR_LIGNE);
    for (i = 0; i < 4; i++) {
        affichVidePion(TAB);
        if (jeuDepart.couleur[i] == jeuEnCours[compteurManche].couleur[i]) {
            setPionsBienPlace(compteurManche);
            //printf("0x1");
        } else if (jeuDepart.couleur[0] == jeuEnCours[compteurManche].couleur[i]) {
            setPionsMalPlace(compteurManche);
            //printf("0x2");
        } else if (jeuDepart.couleur[1] == jeuEnCours[compteurManche].couleur[i]) {
            setPionsMalPlace(compteurManche);
            //printf("0x3");
        } else if (jeuDepart.couleur[2] == jeuEnCours[compteurManche].couleur[i]) {
            setPionsMalPlace(compteurManche);
            //printf("0x4");
        } else if (jeuDepart.couleur[3] == jeuEnCours[compteurManche].couleur[i]) {
            setPionsMalPlace(compteurManche);
            //printf("0x5");
        }
    }
    jeuEnCours[compteurManche].bienPlace = getPionsBienPlace(compteurManche);
    jeuEnCours[compteurManche].malPlace = getPionsMalPlace(compteurManche);
    //printf("bien plac : %d mal place : %d", jeuEnCours[compteurManche].bienPlace,jeuEnCours[compteurManche].malPlace);

    for (i = 0; i < jeuEnCours[compteurManche].bienPlace; i++) {
        placement(2, compteurManche, i);
    }
    for (i = 0; i < jeuEnCours[compteurManche].malPlace; i++) {
        placement(1, compteurManche, i);
    }
}

/**
 * remplie les 4 pions de départ 
 */
void recupPionsDepart(int choix) {
    int pions[4];
    switch (choix) {
        case 1:
            choisir4Couleurs(1, pions);
            setPionsDepart(pions);
            break;
        case 2:
            choisir4Couleurs(4, pions);
            setPionsDepart(pions);
            break;
    }

}

/**
 * rempli les 4 couleurs des pions a trouver et les vérifie
 * @param compteurManche : numéro de la manche 
 */
void recherchePionCache(int compteurManche) {
    int pions[4];
    choisir4Couleurs(2, pions);
    setPionsEnCours(compteurManche, pions);
}

/**
 * 
 * @param compteurManche : nombre de manche éffectués 
 * @return TRUE s'il y a un gagnant sinon FALSE
 */
int winner(int compteurManche) {
    int i = 0, j = 0, verif = FALSE;
    master listeDebut, listeCoursDePartie[NOMBRE_DE_TENTATIVE];

    for (i = 0; i < 4; i++) {
        listeDebut.couleur[i] = getPionsDepart(i);
        listeCoursDePartie[compteurManche].couleur[i] = getPionsEnCours(compteurManche, i);
    }


    //vérification des pions
    for (j = 0; j < 4; j++) {
        if (listeDebut.couleur[0] == listeCoursDePartie[compteurManche].couleur[0] && listeDebut.couleur[1] == listeCoursDePartie[compteurManche].couleur[1] &&
                listeDebut.couleur[2] == listeCoursDePartie[compteurManche].couleur[2] && listeDebut.couleur[3] == listeCoursDePartie[compteurManche].couleur[3]) {
            verif = TRUE;
        } else {
            verif = FALSE;
        }
    }
    return verif;
}

void IA(int compteurManche) {
    int pions[4], liste[4] = {0};
    int i = 0;


    if (compteurManche == 1) {
        choisir4Couleurs(3, pions);
        setPionsEnCours(compteurManche, pions);
    } else if (compteurManche > 1) {
        relancerIA(compteurManche - 1, liste);
        choisir4Couleurs(3, pions);
        //relancerIA(compteurManche-1,liste);
        for (i = 0; i < 4; i++) {
            if (liste[i] != 0) {
                pions[i] = liste[i];
                /*color(POURPRE,0);
                printf("pions [%d] : %d \t liste[%d] : %d",i,pions[i],i,liste[i]);*/
            }
        }
        setPionsEnCours(compteurManche, pions);
    }
}

/**
 * 
 * @param compteurManche : nombre de manches 
 * @param pions : liste des pions ( code )
 */
void relancerIA(int compteurManche, int pions[]) {
    int i = 0;
    master listeDebut, listeCoursDePartie[NOMBRE_DE_TENTATIVE];

    for (i = 0; i < 4; i++) {
        listeDebut.couleur[i] = getPionsDepart(i);
        listeCoursDePartie[compteurManche].couleur[i] = getPionsEnCours(compteurManche, i);
        listeCoursDePartie[compteurManche].bienPlace = getPionsBienPlace(compteurManche);

        if (listeCoursDePartie[compteurManche].bienPlace == TRUE) {
            //printf("\n pions[i] = %d",pions[i]);
            pions[i] = listeCoursDePartie[compteurManche].couleur[i];
        } else {
            pions[i] = 0;
        }
        // printf(" liste :  %d",pions[i]);
    }
}

void remiseZeroGoto() {
    gotoxy(0, 0);
}


