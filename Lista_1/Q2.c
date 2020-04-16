/*2.2 - Faça um programa que recebe como parâmetros os nomes dos comandos que tem
de executar. Você deverá escolher os comandos e inicialmente apresentá-los para o
usuário. O programa executará esses comandos e só quando lançar todos os comandos é
que fica à espera que eles terminem. Exemplo: executa ps ls date. Este exemplo deve
executar os comandos ps, ls e date e esperar que terminem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int arg,char* argv[]){
    // Realiza a criação do processo
    pid_t pid;

    // Denominação dos comandos que iram ser executados no terminal, para o conhecimento do usuario
    printf("O programa tem como parametros de execução de linhas de comandos para o terminal executar.\n"
            "OS comandos são: ps, ls e date;\n");
    
    // Variavel para percorrer o vetor de parametros
    int cont;

    // Execução do processo gerado
    if(pid == 0){
        // Percorendo o vetor de parametros para a execução
        // cont está em 1 pois o primeiro parametro é a chamada da execução do programa
        for(cont = 1; cont<arg; cont++){
            printf("\nExecucao do comando, %s:\n", argv[cont]);
            system(argv[cont]);
        }
        // Faz com que o processo espero toda execução terminar
        wait(0);
    }
}