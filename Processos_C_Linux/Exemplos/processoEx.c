#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int arg, char* argv[]) {
    //Realiza a criação do processo pai
    // Variavel para obtem o id do processo em execução
    pid_t pid;

    pid = fork(); // Cria um novo processo

    // Por não saber mais qual processo esta em execução
    // é feita a verificação se o pai está em primeiro, e o id de execução
     if(pid != 0){
         printf("Ola do Pai - PID = %d\n", getpid());
         // Faz com que o processo espere o fim do processo filho
         wait(0);
         printf("Fim do Pai\n");
     } else {
         printf("Ola do Filho - PID = %d\n", getpid());
         // Realiza um tempo mair de execução no processo filho
         int cont;
         for(cont = 0; cont<10; cont++){
         }
         printf("Fim do Filho\n");
     }
}