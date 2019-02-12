#include <stdio.h>
#include <stdlib.h>

#include "coco.h"

/**
* Permet de vider le tampon d'entrée (stdin) (ex : après un scanf)
*/
void viderTamponEntree(){
    int c;
 
    /*while ((c = fgetc(stdin)) != '\n'){
        //puts("caractère supprimé");
    }*/
    while(kbhit()){
        getch();
    }
}