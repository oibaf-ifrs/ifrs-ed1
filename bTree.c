/* 
 * File:   FilaEnc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "bTree.h"

int isLittleEndian(){
    short int number = 0x1;
    char *numPtr = (char*)&number;
    return (numPtr[0] == 1);
}