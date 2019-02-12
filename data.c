#include <stdio.h>
#include <stdlib.h>

#include "data.h"



//static master listeTemp;
static master listeFinale[NOMBRE_DE_TENTATIVE];
static master pionsDepart;


/**
 * initialise les pions de départ par rapport a ce que rentre l'utilisateur / IA
 * @param tab[4] : correspond aux couleurs de pions
 */
void setPionsDepart(int tab[4]){
    int i=0;
    for(i=0 ; i < 4 ; i++){
        pionsDepart.couleur[i]=tab[i];
    }
    
    /*for(i=0 ; i<4 ; i++){
        printf("\ncouleur : %d",pionsDepart.couleur[i]);
    }*/}


/**
 * renvoie les pions de départ pions par pions 
 * @param compt : numéros de la couleur 
 * @return la couleur du pion 
 */
int getPionsDepart(int compt){
    return pionsDepart.couleur[compt];
}

/**
 * initialise les pions de cahque manches
 * @param positionListe : position dans la liste principale (de 0 à 11)
 * @param positionCouleur : position de la couleur ( de 0 à 3)
 * @param couleur : couleur du pion 
 */
void setPionsEnCours(int compteurManche,int tab[]){
    int i=0;
    
    for(i=0 ; i < 4 ; i++){
        listeFinale[compteurManche].couleur[i]=tab[i];
        //printf("\ntest01 : %d \t tab : %d",listeFinale[compteurManche].couleur[i],tab[i]);
    }
}

/**
 * 
 * @param compteurManche : nombre de manche faites de 1 à 12
 * @param compt : compteur de couleur (de 0à 4)
 * @return la liste des couleurs en cours
 */
int getPionsEnCours(int compteurManche, int compt){
    return listeFinale[compteurManche].couleur[compt];
}

/**
 * rentre dans la liste si le pion est bien placé
 * @param compteurManche : numéro de la manche 
 * @param placePion : place du pions ( entre 0 et 3 )
 * @param bien : TRUE or TRUE +1 
 */
void setPionsBienPlace(int compteurManche){
    listeFinale[compteurManche].bienPlace++;
}

/**
 * rentre dans la liste si le pion est mal placé
 * @param compteurManche : numéro de la manche 
 * @param placePion : place du pions ( entre 0 et 3 )
 * @param bien : TRUE or TRUE+1 
 */
void setPionsMalPlace(int compteurManche){
    listeFinale[compteurManche].malPlace++;
}

int getPionsBienPlace(int compteurManche){
    return  listeFinale[compteurManche].bienPlace;
}

int getPionsMalPlace(int compteurManche){
    return  listeFinale[compteurManche].malPlace;
}

void remiseAZeroListe(){
    int i=0, j=0;
    
    for(i = 0 ; i <= NOMBRE_DE_TENTATIVE ; i++){
        for(j = 0; j < 4 ; j++){
            listeFinale[i].bienPlace=0;
            listeFinale[i].malPlace=0;
            listeFinale[i].couleur[j]=0;
            pionsDepart.couleur[j]=0;
        }
    }
}