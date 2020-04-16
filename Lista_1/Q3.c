/*2.3 Faça um programa que gere um processo filho e através deste inicie um aplicativo do SO.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int arg, char* argv[]){
    //Inicialização do processo pai
    pid_t pid;

    // Se o programa tiver somente o processo pai entao o pid dele será zero, 
    // então se estacia o processo filho pelo fork
    if(pid == 0){
        pid = fork();

        // Realiza a verificação de qual processo está em execução,
        // apartir do momento que o processo pai possui um filho ele terá um id de perocesso diferente de zero
        // sendo assim possibilitando a verificação
        if(pid != 0){
            printf("Inicio do processo pai\n");
            // Como para essa questão não precisamos trabalhar com o processo pai mas com seu filho, porem,
            // Temos que garantir que o processo pai não termine primeiro que o filho e impeça sua execuçao até o fim
            wait(0);
            printf("Fim do processo pai\n");
        } else {
            printf("Iniciodo processo filho\n");
            // O aplicativo que será aberto pelo processo filho pelo terminal e uma janela do VScode
            system("code .");
            printf("Fim do processo filho\n");
        }
    }
}