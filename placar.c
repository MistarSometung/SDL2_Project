#include "placar.h"
#include <stdio.h>


char str[12];

void init_placar(struct pl *plc){
    plc->pt[0] = 0;
    
}

char *pontos(int pts){
    
    sprintf(str, "%d", pts);

    return str;
    
}