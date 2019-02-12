/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pionsAffiche.h
 * Author: mnoyelle
 *
 * Created on 23 janvier 2018, 10:48
 */

#ifndef PIONSAFFICHE_H
#define PIONSAFFICHE_H

#ifdef __cplusplus
extern "C" {
#endif
    
    int couleurPion(int nombreDuPion);
    void affichVidePion(int choix); 
    void diffPion(int couleur);
    void numeroManche(int compteurManche);
    void placement(int choix, int numeroManche, int position);
    void nomJoueur(char nom[]);
    int ageJoueur();
    void affiche_plateau();
    void positionPion(int manche);
    
#ifdef __cplusplus
}
#endif

#endif /* PIONSAFFICHE_H */

