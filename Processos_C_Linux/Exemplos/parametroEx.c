#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* arcv[]){
    int cont;
    for(cont = 0; cont<argc; cont++){
        printf("%s \n", arcv[cont]);
    }
    system("ls");
}