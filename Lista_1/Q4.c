/*2.4 Crie um programa em C que demonstre uma hierarquia de processos com o comando
fork( ) -> Pai -> Filho ->Filho1.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int arg, char* argv[]){
    //Inicialização do processo pai
    pid_t pid;
    //Criação do processo filho
    pid = fork();
    //vetor para armazenar os id dos processos
    int proc[2], cont = 0;
    // Se o programa tiver somente o processo pai entao o pid dele será zero, 
    // então se estacia o processo filho pelo fork
    if(pid != 0){
        proc[0] = getpid(); //salvando o id do processo executando
        printf("Processo Pai: %d\n", proc[0]);
        // garante que o processo pai espere a execução dos procrssos filhos antes de seu fim
       wait(0);
    } else {
        printf("\n\n");
        proc[1] = getpid(); // Salvando o id do processo
        printf("\nProcesso Filho: %d\n\n", proc[1]);
        // Execução do comando ps para visualização dos processos em execução
        system("ps");
        printf("\n");
        // Comando de terminal para demonstração da árvore de execução
        system("pstree");

        // Loop para demonstrar que os processo filhos não dependem um dos outros
        while(cont < 1000000000){
            cont ++;
        }
        printf("\nFim Filho: %d\n", proc[1]);
        exit(0);
    }
    // Árvore de processos
    system("pstree");
    // Criação do processo filho 1
    pid = fork();

    if(pid!= 0){
        wait(0);
        printf("\nIDs de processos:\n");
        system("ps");
        printf("\nÁrvore antes do fim do processo pai.\n");
        system("pstree");
        printf("\nFim Pai: %d\n", proc[0]);
    } else {
        proc[2] = getpid(); // Salvamento do id de processo
        printf("\nFilho 1: %d\n", proc[2]);

         printf("\n\n");
        //visualização dos processos
        system("ps");
        printf("\n");
        system("pstree");
        while(cont < 1000000000){
            cont ++;
        }
        printf("\nFim Filho1: %d\n", proc[2]);
        exit(0);
    }
}