/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: mnoyelle
 *
 * Created on 23 janvier 2018, 09:36
 */

#ifndef DATA_H
#define DATA_H

#include <time.h>


#ifdef __cplusplus
extern "C" {
#endif
#define FALSE 0
#define TRUE 1
#define TAILLE_NOM_JOUEURS 21
#define NOMBRE_DE_TENTATIVE 14

    typedef struct{
        int couleur[4];
        int bienPlace;
        int malPlace;
    }master;
    
    typedef struct{
        int jour;
        int mois;
        int annee;
        int heure;
        int minute;
        int seconde;
    }dateCreation;
    
    typedef struct{
        char nomJ[TAILLE_NOM_JOUEURS];
        int age ;
        int score ;
        dateCreation dateScore;
        char mdp[11];
        dateCreation date ;
    }paramJoueurs;
    
    void setPionsDepart(int tab[4]);
    int getPionsDepart(int compt);
    void setPionsEnCours(int positionListe, int tab[4]);
    int getPionsEnCours(int compteurManche, int compt);
    void setPionsBienPlace(int compteurManche);
    void setPionsMalPlace(int compteurManche);
    int getPionsBienPlace(int compteurManche);
    int getPionsMalPlace(int compteurManche);
    void remiseAZeroListe();

#ifdef __cplusplus
}
#endif

#endif /* DATA_H */

