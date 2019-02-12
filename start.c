#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "coco.h"

//#include "pageAccueil.h"

#define TRUE 1
#define FALSE 0
#define TAILLE_PION 2
#define RETOUR_LIGNE 4
#define TAB 5

void menu() {
    int /*choixMenu=0,*/ i = 0, pions[4];
    char choixMenu;
    srand(time(NULL));

    while (TRUE) {

        clrscr();
        ecranAccueil();
        choixMenu = choixJeu();
        switch (choixMenu) {
            case '1'://regles du jeu
                regles();
                break;
            case '2': //chercherles pions de l'IA
                parametreJeu();
                chercherPionsIa();
                break;
            case '3': //joueur contre joueur
                parametreJeu();
                jeuxVShumain();
                break;
            case '4': //meilleur Score
                affichTableauMeilleurScore();
                topScore();
                system("pause");

                break;
                /*case '5':
                    menuJoueur();
                    break;*/
            case '0': // quitter
                base_enregistrement();
                exit(0);
                break;
            default:
                break;
        }
    }


}

void chercherPionsIa() {
    int compteurManche = 1, verif = FALSE, win = 0, pions[4], i = 0, j = 0;
    master listeCoursDePartie[NOMBRE_DE_TENTATIVE];

    recupPionsDepart(2);

    for (j = 0; j < TAILLE_PION; j++) {
        for (i = 0; i < 4; i++) {
            pions[i] = getPionsDepart(i); //récupère les pions de départ
        }
    }



    while (verif == FALSE) {
        remiseZeroGoto();
        effacer_gauche();
        numeroManche(compteurManche); // affiche le numéro de manche
        recherchePionCache(compteurManche); //récupère les pions a trouver

        for (j = 0; j < TAILLE_PION; j++) {
            for (i = 0; i < 4; i++) {
                listeCoursDePartie[compteurManche].couleur[i] = getPionsEnCours(compteurManche, i);
            }
        }
        positionPion(compteurManche);
        for (i = 0; i < 4; i++) {
            diffPion(listeCoursDePartie[compteurManche].couleur[i]);
            affichVidePion(6);
        }
        trouverLesPions(compteurManche);
        win = winner(compteurManche);
        affichVidePion(RETOUR_LIGNE);

        gotoxy(5, 40);
        if (win == TRUE) {
            effacer_gauche();
            affichePionsGagnant(pions);
            youWin();
            artifice();
            gotoxy(16, 30);
            scoreWin(compteurManche);
            system("pause");
            verif = TRUE;
        }
        if (compteurManche == 13) {
            gotoxy(16, 30);
            affichePionsGagnant(pions);
            scoreLose();
            youLose();
            system("pause");
            verif = TRUE;
        }
        compteurManche++;

    }
}

/**
 * 
 */
void jeuxVShumain() {
    int compteurManche = 1, win = FALSE, verif = FALSE, pions[4], i = 0, j = 0;
    master listeCoursDePartie[NOMBRE_DE_TENTATIVE];

    recupPionsDepart(1);

    for (j = 0; j < TAILLE_PION; j++) {
        for (i = 0; i < 4; i++) {
            pions[i] = getPionsDepart(i); //récupère les pions de départ
        }
    }

    while (verif == FALSE) {
        remiseZeroGoto();
        effacer_gauche();
        numeroManche(compteurManche); // affiche le numéro de manche
        recherchePionCache(compteurManche); //récupère les pions a trouver

        for (j = 0; j < TAILLE_PION; j++) {
            for (i = 0; i < 4; i++) {
                listeCoursDePartie[compteurManche].couleur[i] = getPionsEnCours(compteurManche, i);
            }
        }
        positionPion(compteurManche);
        for (i = 0; i < 4; i++) {
            diffPion(listeCoursDePartie[compteurManche].couleur[i]);
            affichVidePion(6);
        }
        trouverLesPions(compteurManche);
        win = winner(compteurManche);
        affichVidePion(RETOUR_LIGNE);

        gotoxy(5, 40);
        if (win == TRUE) {
            effacer_gauche();
            affichePionsGagnant(pions);
            youWin();
            artifice();
            gotoxy(16, 30);
            scoreWin(compteurManche);
            system("pause");
            verif = TRUE;
        }
        if (compteurManche == 13) {
            gotoxy(16, 30);
            affichePionsGagnant(pions);
            scoreLose();
            youLose();
            system("pause");
            verif = TRUE
                    ;
        }
        compteurManche++;

    }

}

/**
 * initialise les paramètres de jeux
 */
void parametreJeu() {
    clrscr();
    affiche_plateau();
    remiseAZeroListe();
}

void nouveauJoueur() {
    paramJoueurs newPlayer;
    time_t heure;
    struct tm * ptm;
    char nom[TAILLE_NOM_JOUEURS], motPasse[11];
    int verif = FALSE, nombreJoueur = 0;

    time(&heure);
    ptm = gmtime(&heure);
    nombreJoueur = getNombreJoueurs();
    nomJoueur(nom);
    motDePasse(motPasse);
    strcpy(newPlayer.nomJ, nom);
    newPlayer.nomJ[strlen(newPlayer.nomJ) - 1] = '\0';
    strcpy(newPlayer.mdp, motPasse);
    newPlayer.mdp[strlen(newPlayer.mdp) - 1] = '\0';

    newPlayer.date.annee = ptm->tm_year + 1900;
    newPlayer.date.mois = ptm->tm_mon + 1;
    newPlayer.date.jour = ptm->tm_mday;
    newPlayer.date.heure = ptm->tm_hour + 1;
    newPlayer.date.minute = ptm->tm_min;
    newPlayer.date.seconde = ptm->tm_sec;

    //printf("%s, cree le : %d/%d/%d a %d:%d:%d mdp :%s ", newPlayer.nomJ, newPlayer.date.jour, newPlayer.date.mois, newPlayer.date.annee, newPlayer.date.heure, newPlayer.date.minute, newPlayer.date.seconde, newPlayer.mdp);

    while (verif == FALSE) {
        newPlayer.age = ageJoueur();
        if (newPlayer.age < 3 || newPlayer.age > 150) {
            verif = FALSE;
        } else {
            verif = TRUE;
        }
    }
    setNomJoueurs(nombreJoueur, newPlayer);
    setNombreJoueurs();
    connexionNewJoueur(newPlayer.nomJ, newPlayer.mdp);
}

void menuJoueur() {
    int ver = TRUE;
    char choixMenu;

    while (ver == TRUE) {
        clrscr();
        ecranAccueilJoueur();
        choixMenu = choixJeu();

        switch (choixMenu) {
            case '1':
                break;
            case '2':
                nouveauJoueur();

                break;
            case '3':
                break;
            case '0':
                clrscr();
                menu();
                break;
        }
    }
}

void UnJoueurDeuxJoueur() {
    int ver = TRUE;
    char choixMenu;

    base_recup();

    while (ver == TRUE) {
        clrscr();
        ecranAccueilChoixJoueur();
        choixMenu = choixJeu();

        switch (choixMenu) {
            case '1'://2joueurs

                ver = connexionJoueur();

                break;
            case '2'://nouveau joueur
                nouveauJoueur();
                ver = TRUE;
                break;
            case '0'://ne pas se connecter
                clrscr();
                joueurInconnuJ1();
                //menu();
                ver = FALSE;
                break;
        }
    }
    menu();
}

int connexionJoueur() {
    char login[21], mdp[11], nomJ[21], mdpJ[11];
    int i = 0, verif = TRUE;

    //while (verif == TRUE) {
    clrscr();
    ecranConnexion();
    afficheConnexion(login, mdp);
    login[strlen(login) - 1] = '\0';
    mdp[strlen(mdp) - 1] = '\0';


    for (i = 0; i < getNombreJoueurs(); i++) {
        if (strcmp(getNomJoueur(i, nomJ), login) == 0 && strcmp(mdp, getMotPass(i, mdpJ)) == 0) {
            setJ1(i);
            verif = FALSE;
            menu();
        } else {
            verif = TRUE;
        }
        //}
    }
    if (verif == TRUE) {
        afficheMauvaiseConnexion();
    }
    return verif;
}

void connexionNewJoueur(char login[21], char mdp[11]) {
    char nomJ[21], mdpJ[11];
    int i = 0;

    clrscr();
    ecranConnexion();
    /* afficheConnexion(login, mdp);
     login[strlen(login) - 1] = '\0';
     mdp[strlen(mdp) - 1] = '\0';*/

    for (i = 0; i < getNombreJoueurs(); i++) {
        if (strcmp(getNomJoueur(i, nomJ), login) == 0 && strcmp(mdp, getMotPass(i, mdpJ)) == 0) {
            setJ1(i);
            menu();
        }
    }
}

void scoreWin(int nombreCoup) {
    int i = 0;
    char nomJ[21], nom[21];

    getJ1(nomJ);
    for (i = 0; i < getNombreJoueurs(); i++) {
        getNomJoueur(i, nom);
        if (strcmp(nomJ, nom) == 0) {
            scoreAugm(i, nombreCoup);
        }
    }

}

void scoreLose() {
    int i = 0;
    char nomJ[21], nom[21];

    getJ1(nomJ);
    for (i = 0; i < getNombreJoueurs(); i++) {
        getNomJoueur(i, nom);
        if (strcmp(nomJ, nom) == 0) {
            scoreDim(i);
        }
    }

}

void topScore() {
    paramJoueurs listeScore[30], score[5];
    int i = 0, j = 0, verif = TRUE;

    for (i = 0; i < 30; i++) {
        //initialisation des paramètres
        listeScore[i].score = 0;

        listeScore[i].dateScore.annee = 0;
        listeScore[i].dateScore.mois = 0;
        listeScore[i].dateScore.jour = 0;

        listeScore[i].dateScore.heure = 0;
        listeScore[i].dateScore.minute = 0;
        listeScore[i].dateScore.seconde = 0;
    }

    getListeJoueursScore(listeScore);

    for (i = 0; i < 31; i++) {
        for (j = 0; j < 30; j++) {
            if (listeScore[j].score > listeScore[j - 1].score) {
                //on stock dans le temp
                strcpy(score[0].nomJ, listeScore[j - 1].nomJ);
                score[0].score = listeScore[j - 1].score;

                score[0].dateScore.annee = listeScore[j - 1].dateScore.annee;
                score[0].dateScore.mois = listeScore[j - 1].dateScore.mois;
                score[0].dateScore.jour = listeScore[j - 1].dateScore.jour;
                score[0].dateScore.heure = listeScore[j - 1].dateScore.heure;
                score[0].dateScore.minute = listeScore[j - 1].dateScore.minute;
                score[0].dateScore.seconde = listeScore[j - 1].dateScore.seconde;


                //i dans i-1
                strcpy(listeScore[j - 1].nomJ, listeScore[j].nomJ);
                listeScore[j - 1].score = listeScore[j].score;

                listeScore[j - 1].dateScore.annee = listeScore[j].dateScore.annee;
                listeScore[j - 1].dateScore.mois = listeScore[j].dateScore.mois;
                listeScore[j - 1].dateScore.jour = listeScore[j].dateScore.jour;
                listeScore[j - 1].dateScore.heure = listeScore[j].dateScore.heure;
                listeScore[j - 1].dateScore.minute = listeScore[j].dateScore.minute;
                listeScore[j - 1].dateScore.seconde = listeScore[j].dateScore.seconde;


                //temp dans i
                strcpy(listeScore[j].nomJ, score[0].nomJ);
                listeScore[j].score = score[0].score;

                listeScore[j].dateScore.annee = score[0].dateScore.annee;
                listeScore[j].dateScore.mois = score[0].dateScore.mois;
                listeScore[j].dateScore.jour = score[0].dateScore.jour;
                listeScore[j].dateScore.heure = score[0].dateScore.heure;
                listeScore[j].dateScore.minute = score[0].dateScore.minute;
                listeScore[j].dateScore.seconde = score[0].dateScore.seconde;

            }
        }
    }

    for (i = 0; i < 5; i++) {
        strcpy(score[i].nomJ, listeScore[i].nomJ);
        score[i].score = listeScore[i].score;

        score[i].dateScore.annee = listeScore[i].dateScore.annee;
        score[i].dateScore.mois = listeScore[i].dateScore.mois;
        score[i].dateScore.jour = listeScore[i].dateScore.jour;
        score[i].dateScore.heure = listeScore[i].dateScore.heure;
        score[i].dateScore.minute = listeScore[i].dateScore.minute;
        score[i].dateScore.seconde = listeScore[i].dateScore.seconde;


    }


    titreTopScore(score);

}