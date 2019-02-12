#include <stdlib.h>
#include <stdio.h>
#include "data.h"

#define NOM_FICHIER "joueurs.bin"

void base_creation(){
    FILE *BDD;
    
    BDD = fopen(NOM_FICHIER,"w");
    if(BDD != NULL){
        fclose(BDD);
    }
}



int base_nombreJoueurs(){
    FILE *BDD;
    int taille;
    
    BDD = fopen(NOM_FICHIER, "rb");
    
    if(BDD == NULL){
        return 0;
    }
    
    fseek( BDD, 0, SEEK_END);
    taille = ftell(BDD);
    taille /= sizeof(paramJoueurs);
    
    fclose(BDD);
    return taille;
}


int base_existe(){
    FILE *BDD;
    
    if ((BDD = fopen(NOM_FICHIER,"r"))==NULL){        
        return FALSE;
    } else{
        fclose(BDD);
        return TRUE;
    }
}