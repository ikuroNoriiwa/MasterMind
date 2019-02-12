#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "coco.h"
#include "couleur.h"

#define FALSE 0
#define TRUE 1

/**
 *  affiche MASTER, le nom du jeu 
 */
void affichTitre() {
    printf(" "
            " .--------------.  .--------------.  .--------------.  .--------------.  .--------------.  .--------------. \n"
            "  | ____    ____ |  |      __      |  |    _______   |  |  _________   |  |  _________   |  |  _______     | \n"
            "  ||_   \\  /   _||  |     /  \\     |  |   /  ___  |  |  | |  _   _  |  |  | |_   ___  |  |  | |_   __ \\    | \n"
            "  |  |   \\/   |  |  |    / /\\ \\    |  |  |  (__ \\_|  |  | |_/ | | \\_|  |  |   | |_  \\_|  |  |   | |__) |   | \n"
            "  |  | |\\  /| |  |  |   / ____ \\   |  |   '.___`-.   |  |     | |      |  |   |  _|  _   |  |   |  __ /    | \n"
            "  | _| |_\\/_| |_ |  | _/ /    \\ \\_ |  |  |`\\____) |  |  |    _| |_     |  |  _| |___/ |  |  |  _| |  \\ \\_  | \n"
            "  ||_____||_____||  ||____|  |____||  |  |_______.'  |  |   |_____|    |  | |_________|  |  | |____| |___| | \n"
            "  |              |  |              |  |              |  |              |  |              |  |              | \n"
            "  '--------------'  '--------------'  '--------------'  '--------------'  '--------------'  '--------------' \n"
            "");

}

/**
 * affichage du menu principal 
 */
void affichMenu() {
    printf("\n\n"
            "\t\t\t\t\t -1- R%cgles du jeu \n"
            "\t\t\t\t\t -2- Chercher les pions de l'IA\n"
            "\t\t\t\t\t -3- Jouer %c 2 joueurs \n"
            "\t\t\t\t\t -4- Top Scores \n"

            "\n \t\t\t\t\t -0- Quitter\n ", 138, 133);
}

/**
 * lance le mnu principal avec les couleurs 
 */
void ecranAccueil() {
    color(12, 0);
    affichTitre();
    color(2, 0);
    affichMenu();
    color(15, 0);
}

/**
 * permet de faire le choix dans le menu 
 * @return : le caractère selected par l'utilisateur
 */
char choixJeu() {
    char c;

    printf("\n\n\t\t\t\t Que voulez vous faire ? ");
    c = getch();// récupère la selection du clavier
    //scanf("%d",&choix);

    return c;
}

/**
 * affiche l'histoire du jeu et les règles 
 */
void regles() {
    system("cls");
    color(ROUGE, 0);
    printf("\n  Petite Histoire :\n");
    color(BLANC, 0);
    printf("  Le Mastermind ou Master Mind est un jeu de soci%ct%c pour deux joueurs dont le but est de trouver un code.\n"
            "  C'est un jeu de  r%cflexion, et de d%cduction, invent%c par Mordecai  Meirowitz dans les ann%ces 1970 alors \n"
            "  qu'il travaillait comme expert en t%cl%ccommunications. Au d%cpart, il est %cdit%c par Capi%cpa.\n\n", 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130);
    color(8, 0);
    printf("\tEnter pour continuer");
    color(0, 0);
    system("pause");
    color(BLANC, 0);
    color(ROUGE, 0);
    printf("\n  Les r%cgles : \n", 138);

    color(BLANC, 0);
    printf("  Un joueur commence par placer son choix de pions sans qu'ils soient vus de l'autre joueur %c l'arri%cre\n  d'un cache \n"
            "  qui les masquera %c la vue de celui-ci jusqu'%c la fin de la manche.\n\n\n", 133, 138, 133, 133);

    printf("  Le joueur qui n'a pas s%clectionn%c les pions doit trouver quels sont les quatre pions, c'est-%c-dire \n  leurs couleurs et positions."
            "  Pour cela, %c chaque tour, le joueur doit se servir de pions pour remplir \n  une rang%ce selon l'id%ce qu'il se fait des pions dissimul%cs.\n"
            "  Une fois les pions plac%cs, l'autre joueur indique :\n\n"
            "  \tle nombre de pions de la bonne couleur bien plac%cs en utilisant le m%cme nombre de pions rouge \n"
            " \tle nombre de pions de la bonne couleur, mais mal plac%cs, avec les pions blancs.\n\n\n", 130, 130, 133, 133, 130, 130, 130, 130, 130, 136, 130);
    color(8, 0);
    printf("\tEnter pour continuer\n");
    color(0, 0);
    system("pause");
    color(BLANC, 0);

    printf("  Il arrive donc surtout en d%cbut de partie qu'il ne fasse rien concr%ctement et qu'il n'ait %c dire qu'aucun\n  pion ne correspond, en couleur"
            "  ou en couleur et position.\n"
            "  La tactique du joueur actif consiste %c s%clectionner en fonction des coups pr%cc%cdents, couleurs et positions,\n  de mani%cre %c obtenir le maximum"
            "  d'informations de la r%cponse \n  du partenaire puisque le nombre de propositions est limit%c par le nombre de rang%ces de trous du jeu.", 130, 138, 133, 133, 130, 130, 130, 138, 133, 130, 130, 130);
    printf("\n\n  Dans la plupart"
            " des cas, il s'efforce de se rapprocher le plus possible de la solution, compte tenu\n  des r%cponses pr%cc%cdentes, mais il peut aussi former une combinaison"
            "  dans le seul but de v%crifier une partie\n  des conclusions des coups pr%cc%cdents et de faire en cons%cquence la proposition la plus propice %c la\n  d%cduction"
            " d'une nouvelle information.\n"
            "  Le joueur gagne cette manche s'il donne la bonne combinaison de pions sur la derni%cre rang%ce ou avant.\n  Dans tous les cas, c'est %c son tour de choisir"
            " les pions %c d%ccouvrir.\n\n", 130, 130, 130, 130, 130, 130, 130, 133, 130, 138, 130, 133, 133, 130);
    color(8, 0);
    printf("\tEnter pour continuer");
    color(0, 0);
    system("pause");
    color(BLANC, 0);
}

/**
 * affiche le menu des joueurs (OBSOLETE)
 */
void menuJoueurAffiche() {
    printf("\n\n"
            "\t\t\t\t\t -1- Tous les Joueurs \n"
            "\t\t\t\t\t -2- Nouveau Joueur\n"
            "\t\t\t\t\t -3- Modifier Joueur\n"
            "\n \t\t\t\t\t -0- retour\n ");
}

/**
 * lance le menu des joueurs 
 */
void ecranAccueilJoueur() {
    color(12, 0);
    affichTitre();
    color(2, 0);
    menuJoueurAffiche();
    color(15, 0);
}

/**
 * affiche en ASCII art YOU WIN 
 * 
 */
void youWin() {
    color(BLANC, ROUGE);
    gotoxy(15, 20);
    printf(" _  _  _____  __  __    _    _  ____  _  _ ");
    gotoxy(15, 21);
    printf("( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( )");
    gotoxy(15, 22);
    printf(" \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( ");
    gotoxy(15, 23);
    printf(" (__) (_____)(______)  (__/\\__)(____)(_)\\_)");
    gotoxy(15, 24);
    printf("                                           ");
    color(BLANC, 0);


}


/**
 * affiche en ASCII art GAME OVER
 */
void youLose() {

            gotoxy(15, 20);
            color(JAUNE, 0);
            printf(" (  (      )     )      (          )      (   (    ");
            gotoxy(15, 21);
            color(ROUGE, 0);
            printf(" )\\))(  ( /(    (      ))\\    (   /((    ))\\  )(   ");
            gotoxy(15, 22);
            printf(" ((_))\\  )(_))   )\\  ' /((_)   )\\ (_))\\  /((_)(()\\ ");
            gotoxy(15, 23);
            printf(" (()(_)((_)_  _((_)) (_))    ((_)_)((_)(_))   ((_) ");
            gotoxy(15, 24);
            color(BLANC, 0);
            printf(" / _` | / _` || '  \\()/ -_)  / _ \\ V / / -_) | '_| ");
            gotoxy(15, 25);
            printf(" \\__, | \\__,_||_|_|_| \\___|  \\___/ \\_/  \\___| |_|   ");
            gotoxy(15, 26);
            printf(" |___/");

}

/**
 * Affiche un feu d'artifice pour le gagnant 
 */
void artifice() {
    int x = 0, y = 0, i = 0, heure1 = 0, heure2 = 0, verif = FALSE;
    const short lCouleur[8] = {ROUGE, JAUNE, VERT, BLEU, VERTFLUO, BLANC, POURPRE, TURQUOISE};

    heure1 = clock() / 1000;
    while (heure2 < heure1 + 5) {

        x = feuxArtifice(1);
        y = feuxArtifice(2);
        while (verif == FALSE) {
            for (i = 0; i < 43; i++) {
                if (x == 13 && y == 18) {
                    x = feuxArtifice(1);
                    y = feuxArtifice(2);
                } else {
                    verif = TRUE;
                }
            }
        }

        gotoxy(x, y);
        color(0, lCouleur[aleatFunct() - 1]);
        printf(" ");
        color(BLANC, 0);
        gotoxy(0, 0);
        heure2 = clock() / 1000;
        youWin();
    }
}

/**
 * premier menu, ou les joueurs peuvent se connecter 
 */
void choixNbrJoueur() {
    printf("\n\n"
            "\t\t\t\t\t -1- Se connecter\n"
            "\t\t\t\t\t -2- Cr%cer un nouveau joueur\n"
            "\n \t\t\t\t\t -0- Jouer sans se connecter\n ", 130);

    /*printf("\n\n"
           "\t\t\t\t LOGIN :+"*/
}

/**
 * met les couleurs et les position sur le menu
 */
void ecranAccueilChoixJoueur() {
    color(12, 0);
    affichTitre();
    color(2, 0);
    choixNbrJoueur();
    color(15, 0);
}

/**
 * affiche et récupère les données de connexions 
 * @param login : pointeur de tableau vide pour le login du joueur
 * @param mdp : pointeur de tabelau vide pour le mot de passe du joueur
 */
void afficheConnexion(char login[], char mdp[]) {

    gotoxy(15, 15);
    color(2, 0);
    printf("LOGIN : ");
    color(BLANC, 0);
    fgets(login, 21, stdin);
    gotoxy(15, 17);
    color(2, 0);
    printf("Mot de Passe : ");
    color(BLANC, 0);
    fgets(mdp, 11, stdin);
}

/**
 * met les couelurs sur le titre 
 */
void ecranConnexion() {
    clrscr();
    color(12, 0);
    affichTitre();
    color(2, 0);

}