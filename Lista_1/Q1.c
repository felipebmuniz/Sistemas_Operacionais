/*2.1 - Crie um programa que receba parâmetros na chamada 
do main e mostre na saída metade dos parâmetros pelo 
processo pai e a outra metade pelo processo filho*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int arg, char* argv[]){
    // Realização do processo pai
    pid_t pid;
    //Criação de um novo processo, denominado filho
    pid = fork();

    // Variavel para a contagens de parametros passados para o codigo
    int cont;

    // Para verificar qual processo sera impresso deve 
    // estar ciente que o processo pai é diferente de zero
    if(pid != 0){
        printf("Processo Pai: \n");

        // Realiza a amostragem da primeira metade dos parametros passados
        for(cont = 0; cont<(arg/2); cont++){
            printf("Parametro: %s \n", argv[cont]);
        }
        // Garante que o processo pai não encerre a execução antes que o filho termine
        wait(0);
    } else {
         printf("Processo Filho: \n");

        // Realiza a amostragem da segunda metade dos parametros passados
        for(cont = (arg/2); cont<arg; cont++){
            printf("Parametro: %s \n", argv[cont]);
        }
    }
}