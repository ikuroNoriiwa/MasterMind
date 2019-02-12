/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pions.h
 * Author: mnoyelle
 *
 * Created on 23 janvier 2018, 10:43
 */

#ifndef PIONS_H
#define PIONS_H

#ifdef __cplusplus
extern "C" {
#endif


    void choisir4Couleurs(int c, int pions[]);
    int verifPionsDifferents(int tab[4], int i , int temp);
    int aleatFunct();
    void trouverLesPions(int compteurManche);
    void recupPionsDepart(int choix );
    int recherchePionCache(int compteurManche);
    void relancerIA(int compteurManche,int *pions){
    int winner(int compteurManche);

#ifdef __cplusplus
}
#endif

#endif /* PIONS_H */

