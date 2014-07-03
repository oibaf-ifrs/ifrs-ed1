/* 
 * File:   auxFunc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Funções auxiliares.
 * 
 */

#include "auxFunc.h"

int isLittleEndian(){
    short int number = 0x1;
    char *numPtr = (char*)&number;
    return (numPtr[0] == 1);
}
