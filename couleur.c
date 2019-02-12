#include <windows.h>

/**
 * change la couleur texte/ fond 
 * 
 * @param texte : couleur du texte 
 * @param fond : couleur du fond 
 */
void color(int texte, int fond){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, fond * 16 + texte);
}