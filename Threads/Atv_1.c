//@felipebmuniz

/*Escreva um programa em C composto por duas threads: a primeira deve contar e exibir na tela todos os números
 entre 1 e 500 (de forma crescente); a segunda deve contar e exibir na tela todos os números entre 500 e 1
 (de forma decrescente). As duas threads devem ser executadas em paralelo. */
 
#include <stdio.h>
#include <pthread.h>
#include <windows.h>

// Função para realizar a contagem decrescente e crescente
void *cont(void *ard) {
    int *v = (int *) ard;
    int i;

    // Realiza a verificação de que meio de contagem irá ser realizado
    if (*v == 0)
    {
        // Crescente
        for (i = 1; i <= 500; i++) {
            printf("T1: %d\n", i);
        }
    } else
    {
        for (i = 499; i > 0; i--) {
            // Decrescente
            printf("T2: %d\n", i);
        }
    }
    Sleep(0);
}

int main() {
    // Definindo as threads para a criação
    pthread_t thread1, thread2;

    // Indentificadores para saber qual operação a função irá realizar
    int c = 0;
    int d = 1;

    // Criando as threads e passando a função cont e o metodo de contador
    pthread_create(&thread1, NULL, cont, &c);
    pthread_create(&thread2, NULL, cont, &d);

    // Realiza a espera pelas threads em execução
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}