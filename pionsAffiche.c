#include <stdio.h>
#include <stdlib.h>

#include "coco.h" //conio.h
#include "viderTampon.h"
#include "couleur.h"
#include "data.h"
#include <time.h>

#define LIGNE 75
#define TRUE 1
#define FALSE 0
#define HAUTEUR 2

/**
 * permet de selectionner les pions 
 * @param nombreDuPion : position du pion dans la liste 
 * @param cache : affichage du joueur et de l'ia pour le choix des pions
 * @return renvoie la liste des pions 
 */
int couleurPion(int nombreDuPion, int cache) {
    int pion = 0, i = 0;
    int saisieOk = FALSE, verif = TRUE;
    master listeDebut;
    const short lCouleur[8] = {ROUGE, JAUNE, VERT, BLEU, VERTFLUO, BLANC, POURPRE, TURQUOISE};
    char c, nom[21];
    int debut, fin;

    switch (cache) {
        case 1:
        case 2:

            if (cache == 1) {
                color(JAUNE, 0);
                printf(" %s", "Le joueur J2");
                color(BLANC, 0);
                printf(" choisis la couleur du pion numero %d ( %c %s): ", nombreDuPion + 1, 133, "cacher");
            } else {
                color(JAUNE, 0);
                printf(" %s", getJ1(nom));
                color(BLANC, 0);
                printf(" choisis la couleur du pion numero %d ( %c %s): ", nombreDuPion + 1, 133, "trouver");
            }
            do {
                c = getch();
                if ((c >= '1')&&(c <= '8')) {
                    saisieOk = TRUE;
                } else if (c == 't') {
                    //time(&debut);

                    gotoxy(LIGNE + 1, 41);
                    debut = clock() / 1000;
                    TRICHE(listeDebut);
                    while (verif == TRUE) {
                        if (clock() / 1000 >= debut + 5) {
                            gotoxy(LIGNE + 1, 41);
                            for (i = 0; i < 4; i++) {
                                color(BLANC, 0);
                                printf("   %c", 186);
                            }
                            verif = FALSE;
                            gotoxy(69, 10);
                        }
                    }
                    verif = TRUE;
                } else if (c == 'q' || c == 'Q') {
                    menu();
                }
            } while (saisieOk == FALSE);
            pion = c - '1';
            color(0, lCouleur[pion]);
            pion++;
            printf("  ");
            color(BLANC, 0);
            break;
        case 3://IA 
            printf("\n %s choisis la couleur du pion numero %d ( a %s): ", "L'IA", nombreDuPion + 1, "trouver");
            printf("\npion : %d\n", pion = aleatFunct());
            break;
        case 4:
            printf("\n %s choisis la couleur du pion numero %d ( a %s): ", "L'IA", nombreDuPion + 1, "cacher");
            printf("\npion : %d\n", pion = aleatFunct());
            break;
    }


    return pion;
}

/**
 * permet de tricher en affichant les couleurs gagnantes 
 * @param listeDebut : les 4 couleurs du début 
 */
void TRICHE(master listeDebut) {
    int i = 0;
    
    for (i = 0; i < 4; i++) {
        listeDebut.couleur[i] = getPionsDepart(i);
        color(0, listeDebut.couleur[i]);
        printf("   ");
        color(BLANC, 0);
        printf("%c", 186);

    }
}

/**
 * affiche les 4 pions sélectionnés par le premier joueur (quand le J2 a gagné )  
 * @param pions : liste de 4 couleur
 */
void affichePionsGagnant(int pions[4]) {
    int i = 0;
    
    gotoxy(LIGNE + 1, 41);
    for (i = 0; i < 4; i++) {
        pions[i] = getPionsDepart(i);
        color(0, pions[i]);
        printf("   ");
        color(BLANC, 0);
        printf("%c", 186);

    }
}

/**
 * affiche le choix des pions, couleur deja selected 
 * @param choix : 1 = sekection des couleurs    3 = couleur deja selected   4-5= \n \t
 */
void affichVidePion(int choix) {
    int i = 0;
    switch (choix) {
        case 1:
            //clrscr();
            gotoxy(20, 3);
            printf("%c", 201);
            for (i = 0; i < 52; i++) {
                printf("%c", 205);
            }
            printf("%c", 187);
            gotoxy(20, 4);
            printf("%c      choisir 4 pions de couleurs diff%crentes       %c", 186, 130, 186);
            gotoxy(20, 5);
            color(BLANC, 0);
            printf("%c\t     1 : ", 186);
            color(0, ROUGE);
            printf("  ");
            color(BLANC, 0);
            printf("\t 2 : ");
            color(0, JAUNE);
            printf("  ");
            color(BLANC, 0);
            printf("\t 3 : ");
            color(0, VERT);
            printf("  ");
            color(BLANC, 0);
            printf("\t 4 : ");
            color(0, BLEU);
            printf("  ");
            color(BLANC, 0);
            printf("         %c", 186);
            gotoxy(20, 6);
            printf("%c\t     5 : ", 186);
            color(0, VERTFLUO);
            printf("  ");
            color(BLANC, 0);
            printf("\t 6 : ");
            color(0, BLANC);
            printf("  ");
            color(BLANC, 0);
            printf("\t 7 : ");
            color(0, POURPRE);
            printf("  ");
            color(BLANC, 0);
            printf("\t 8 : ");
            color(0, TURQUOISE);
            printf("  ");
            color(BLANC, 0);
            printf("         %c", 186);
            gotoxy(20, 7);
            printf("%c", 200);
            for (i = 0; i < 52; i++) {
                printf("%c", 205);
            }
            printf("%c", 188);
            break;
        case 2:
            printf("/\\\n"
                    "\\/");
            break;
        case 3:

            printf("\n        /!\\ Couleur d%cj%c s%clection%ce /!\\\n", 130, 133, 130, 130);
            break;
        case 4:
            printf("\n");
            break;
        case 5:
            printf("\t");
            break;
        case 6:
            printf("%c", 186);
            break;
    }
}

/**
 * affiche un pion de la couleur choisie en parametre 
 * @param couleur : correspond a la couleur du pion
 */
void diffPion(int couleur) {
    switch (couleur) {
        case ROUGE://rouge
            color(0, ROUGE);
            printf("   ");
            color(BLANC, 0);
            break;
        case JAUNE://jaune
            color(0, JAUNE);
            printf("   ");
            color(BLANC, 0);
            break;
        case VERT://vert
            color(0, VERT);
            printf("   ");
            color(BLANC, 0);
            break;
        case BLEU://bleu
            color(0, BLEU);
            printf("   ");
            color(BLANC, 0);
            break;
        case VERTFLUO://vert fluo
            color(0, VERTFLUO);
            printf("   ");
            color(BLANC, 0);
            break;
        case BLANC://blanc
            color(0, BLANC);
            printf("   ");
            color(BLANC, 0);
            break;
        case POURPRE://pourpre
            color(0, POURPRE);
            printf("   ");
            color(BLANC, 0);
            break;
        case TURQUOISE://turquoise
            color(0, TURQUOISE);
            printf("   ");
            color(BLANC, 0);
            break;
    }
    color(BLANC, 0);

}

/**
 * affiche le numéro de la manche,et l'aide pour quitter ou les pions bien / mal placé
 * @param compteurManche
 */
void numeroManche(int compteurManche) {
    color(TURQUOISE, 0);
    gotoxy(78, 4);
    printf("Appuyez sur Q pour quitter");
    color(POURPRE, 0);
    gotoxy(80, 6);
    printf("Vous %ctes %c la manche %d ", 136, 133, compteurManche);
    color(BLANC, 0);
    gotoxy(77,8);
    color(ROUGE,0);
    printf("%c ",169);
    color(8,0);
    printf(": bonne couleur, bien plac%ce",130);
    gotoxy(77,10);
    color(BLANC,0);
    printf("%c ",169);
    color(8,0);
    printf(": bonne couleur, mal plac%ce",130);
    color(BLANC,0);
}

/**
 * affiche un pion rouge ou blanc en fonction de si la couleur est bien placée ou pas
 * @param choix : 1 = mal placé         2 = bien placé 
 * @param numeroManche : numéro de la mnache en cours
 * @param position : nombre de pion déja placé 
 */
void placement(int choix, int numeroManche, int position) {
    switch (choix) {
        case 1://bonne couleur mais mal placé 
            color(BLANC, 0);
            position += 4;
            positionPionBienMal(numeroManche, position);
            printf("%c", 169);
            break;
        case 2: // bonne couleur bien placé 
            color(ROUGE, 0);
            positionPionBienMal(numeroManche, position);
            printf("%c", 169);
            break;
    }
}

/**
 * saisie du nom
 * @param nom : pointeur de tableau vide
 */
void nomJoueur(char nom[]) {
    printf("\nEntrez votre Nom (20 characteres):");
    viderTamponEntree();
    //fflush(stdin);
    fgets(nom, 21, stdin);
}

/**
 * saisie du mdp 
 * @param mdp : pointeur de tableau vide
 */
void motDePasse(char mdp[]) {
    printf("\nEntrez votre Mot de Passe (10 characteres):");
    viderTamponEntree();
    //fflush(stdin);
    fgets(mdp, 11, stdin);
}

/**
 * saisie de l'age 
 * @return : age saisie par le joueur
 */
int ageJoueur() {
    int age = 0;
    printf("\nentrez votre %cge (entre 3 et 150 ans): ", 131);
    scanf("%d", &age);

    return age;
}

/**
 * affiche connexion échouée si le mdp ou le pseudo est incorrect
 */
void afficheMauvaiseConnexion(){
    color(ROUGE,0);
    printf("\n\t IDENTIFIANT OU MOT DE PASSE INCORRECT ");
    color(BLANC,0);
    system("pause");
}

/**
 * affiche le plateau sur lequel se déroule la partie
 */
void affiche_plateau() {
    int i = 0, j = 0, k = 0;
    clrscr();
    gotoxy(LIGNE, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
    for (j = 0; j < 26; j++) {
        if (j % 2 == 0) {
            gotoxy(LIGNE, 14 + j);
            printf("%c", 204);
            for (k = 0; k < 3; k++) {
                for (i = 0; i < 3; i++) {
                    printf("%c", 205);
                }
                printf("%c", 206);
            }
            printf("%c%c%c%c", 205, 205, 205, 185);
            // printf("+---+---+---+---+");
        } else {
            gotoxy(LIGNE, 12 + j);
            printf("%c   %c   %c   %c   %c", 186, 186, 186, 186, 186);
        }
    }
    gotoxy(LIGNE, 12 + j);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    //printf("+---+---+---+---+\n");


    gotoxy(LIGNE, 40);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
    gotoxy(LIGNE, 41);
    printf("%c   %c   %c   %c   %c", 186, 186, 186, 186, 186);
    gotoxy(LIGNE, 42);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);

}

/**
 * met le curseur a la position ou doit se ranger le pion
 * @param manche : numéro de la manche
 */
void positionPion(int manche) {
    if (manche == 1) {
        gotoxy(LIGNE + 1, 13);
    } else if (manche == 2) {
        gotoxy(LIGNE + 1, 15);
    } else if (manche == 3) {
        gotoxy(LIGNE + 1, 17);
    } else if (manche == 4) {
        gotoxy(LIGNE + 1, 19);
    } else if (manche == 5) {
        gotoxy(LIGNE + 1, 21);
    } else if (manche == 6) {
        gotoxy(LIGNE + 1, 23);
    } else if (manche == 7) {
        gotoxy(LIGNE + 1, 25);
    } else if (manche == 8) {
        gotoxy(LIGNE + 1, 27);
    } else if (manche == 9) {
        gotoxy(LIGNE + 1, 29);
    } else if (manche == 10) {
        gotoxy(LIGNE + 1, 31);
    } else if (manche == 11) {
        gotoxy(LIGNE + 1, 33);
    } else if (manche == 12) {
        gotoxy(LIGNE + 1, 35);
    } else if (manche == 13) {
        gotoxy(LIGNE + 1, 37);
    }
}

/**
 * met le curseur a la position ou doit se placer le pion 
 * @param manche : numéro de la manche
 * @param pos : nombre de pion déja placé 
 */
void positionPionBienMal(int manche, int pos) {
    if (manche == 1) {
        gotoxy(LIGNE + 20 + pos, 13);
    } else if (manche == 2) {
        gotoxy(LIGNE + 20 + pos, 15);
    } else if (manche == 3) {
        gotoxy(LIGNE + 20 + pos, 17);
    } else if (manche == 4) {
        gotoxy(LIGNE + 20 + pos, 19);
    } else if (manche == 5) {
        gotoxy(LIGNE + 20 + pos, 21);
    } else if (manche == 6) {
        gotoxy(LIGNE + 20 + pos, 23);
    } else if (manche == 7) {
        gotoxy(LIGNE + 20 + pos, 25);
    } else if (manche == 8) {
        gotoxy(LIGNE + 20 + pos, 27);
    } else if (manche == 9) {
        gotoxy(LIGNE + 20 + pos, 29);
    } else if (manche == 10) {
        gotoxy(LIGNE + 20 + pos, 31);
    } else if (manche == 11) {
        gotoxy(LIGNE + 20 + pos, 33);
    } else if (manche == 12) {
        gotoxy(LIGNE + 20 + pos, 35);
    } else if (manche == 13) {
        gotoxy(LIGNE + 20 + pos, 37);
    }
}

/**
 * efface la partie gauche de l'écran
 */
void effacer_gauche() {
    int i = 0, j = 0;
    for (j = 9; j < 48; j++) {
        gotoxy(1, j);
        for (i = 0; i < 74; i++) {
            printf(" ");
        }
    }
}


/**
 * affiche le tableau des meilleur joueurs 
 */
void affichTableauMeilleurScore(){
   /* gotoxy(10,10);
    printf("+---+---------------------+-----------------------------------------------------+");
    gotoxy(10,11);
    printf("| 1 + mathieu             +              Le 28/02/2018 a 19h24:32               +");*/
    
    gotoxy(14,HAUTEUR+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(14,HAUTEUR+11);
    printf("%c                     %c                                        %c            %c",186,186,186,186);
    gotoxy(10,HAUTEUR+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,201,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,185);       
    gotoxy(10,HAUTEUR+13);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+14);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+15);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,204,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,185);    gotoxy(10,HAUTEUR+17);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+18);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+19);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,204,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,185);    gotoxy(10,HAUTEUR+21);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+22);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+23);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,204,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,185);    gotoxy(10,HAUTEUR+25);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+26);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+27);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,204,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,185);    gotoxy(10,HAUTEUR+29);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+30);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+31);
    printf("%c   %c                     %c                                        %c            %c",186,186,186,186,186);
    gotoxy(10,HAUTEUR+32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,200,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,188);       

}

/**
 * affiche dans le tableau les scores, la date du score, et le pseudo
 * @param score : liste des 5 meilleur joueur
 */
void titreTopScore(paramJoueurs score[5]){
    gotoxy(21,HAUTEUR+11);
    color(VERT,0);
    printf("PSEUDO");
    gotoxy(40,HAUTEUR+11);
    printf("score r%calis%c le ",130,130);
    gotoxy(81,HAUTEUR+11);
    printf("SCORE");
    
    
    gotoxy(12,HAUTEUR+14);
    color(JAUNE,0);
    printf("1");
    gotoxy(16,HAUTEUR+14);
    printf(" %s ",score[0].nomJ);
    gotoxy(40,HAUTEUR+14);
    printf("Le %d/%d/%d %c %dh%d:%d",score[0].dateScore.jour, score[0].dateScore.mois, score[0].dateScore.annee, 133, score[0].dateScore.heure, score[0].dateScore.minute, score[0].dateScore.seconde);
    gotoxy(81,HAUTEUR+14);
    printf(" %d ",score[0].score);
    
    
    gotoxy(12,HAUTEUR+18);
    color(7,0);
    printf("2");
    gotoxy(16,HAUTEUR+18);
    printf(" %s ",score[1].nomJ);
    gotoxy(40,HAUTEUR+18);
    printf("Le %d/%d/%d %c %dh%d:%d",score[1].dateScore.jour, score[1].dateScore.mois, score[1].dateScore.annee, 133, score[1].dateScore.heure, score[1].dateScore.minute, score[1].dateScore.seconde);
    gotoxy(81,HAUTEUR+18);
    printf(" %d ",score[1].score);
    
    gotoxy(12,HAUTEUR+22);
    color(ROUGE,0);
    printf("3");
    gotoxy(16,HAUTEUR+22);
    printf(" %s ",score[2].nomJ);
    gotoxy(40,HAUTEUR+22);
    printf("Le %d/%d/%d %c %dh%d:%d",score[2].dateScore.jour, score[2].dateScore.mois, score[2].dateScore.annee, 133, score[2].dateScore.heure, score[2].dateScore.minute, score[2].dateScore.seconde);
    gotoxy(81,HAUTEUR+22);
    printf(" %d ",score[2].score);
    
    
    gotoxy(12,HAUTEUR+26);
    color(8,0);
    printf("4");
    gotoxy(16,HAUTEUR+26);
    printf(" %s ",score[3].nomJ);
    gotoxy(40,HAUTEUR+26);
    printf("Le %d/%d/%d %c %dh%d:%d",score[3].dateScore.jour, score[3].dateScore.mois, score[3].dateScore.annee, 133, score[3].dateScore.heure, score[3].dateScore.minute, score[3].dateScore.seconde);
    gotoxy(81,HAUTEUR+26);
    printf(" %d ",score[3].score);
    
    
    gotoxy(12,HAUTEUR+30);
    color(8,0);
    printf("5");
    gotoxy(16,HAUTEUR+30);
    printf(" %s ",score[4].nomJ);
    gotoxy(40,HAUTEUR+30);
    printf("Le %d/%d/%d %c %dh%d:%d",score[4].dateScore.jour, score[4].dateScore.mois, score[4].dateScore.annee, 133, score[4].dateScore.heure, score[4].dateScore.minute, score[4].dateScore.seconde);
    gotoxy(81,HAUTEUR+30);
    printf(" %d ",score[4].score);
    gotoxy(20,HAUTEUR+38);
    color(BLANC,0);
    
    
}