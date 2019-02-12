/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mathieu
 *
 * Created on 22 janvier 2018, 22:30
 */

#include <stdio.h>
#include <stdlib.h>

#include "start.h"

int main(){
    system("mode con lines=50 cols=110");
    UnJoueurDeuxJoueur();
    return 0;
}