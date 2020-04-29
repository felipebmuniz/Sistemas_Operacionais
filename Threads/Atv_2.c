//@felipebmuniz

/*Implemente um programa em C que realize o cálculo das somas dos
 valores das linhas de uma matriz 5x5 de números inteiros e imprima o
 resultado na tela. O cálculo do somatório de cada linha deve ser realizado
 em paralelo por threads.*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>

// Definindo o tamanho fixo da matriz a ser trabalhada
 #define LINHA 5
 #define COLUM 5

void *somatorio (void *ard, void **mat) {
     // Recebendo o endereço da linha do somatorio
     int **matriz = (int**) mat;
     int *linha = (int*) ard;
     int l = *linha;
     int soma = 0;

     int i;
     for (i = 0; i < 5; i++) {
         soma = soma + matriz[1][i];
     }

     printf("Valor do somatorio da linha %d: %d\n", l, soma);
}

 int main()
 {  
     // Instanciando o vetor de threads para somatorio de cada linha da matriz
     pthread_t thread[5];
     

     // Declarando variável ponteiro para ponteiro
     int **matriz;

     // Aloca o vetor de ponteiros
     matriz = (int**)malloc(LINHA * sizeof(int*));

     // Alocando cada uma das linhas da matriz
     int i;
     for (i = 0; i < LINHA; i++) {
         matriz[i] = (int*)malloc(COLUM * sizeof(int));
     }

     // Preenchendo a matriz
     int j;
     for (i = 0; i < LINHA; i++) {
         for (j = 0; j < COLUM; j++) {
             //preenchimento de valores aleatorios entre 0 e 24;
             matriz[i][j] = rand() % 24;
         }
     }

     // Mostra a matriz para o usuário
     for(i = 0; i < LINHA; i++) {
		 for(j = 0; j < COLUM; j++) {
			printf("%d\t", matriz[i][j]);
        }
        printf("\n");
	}

     // Criando as threads no seu vetor e passando a função somatorio para a execução e a linha que deve ser somada
     int l = 0;
     while (l < 5) {
         pthread_create(&thread[l], NULL, somatorio, (&l, matriz));
         l++;
    }
     
     
     // Responsavel por esperar todas as threads criadas executarem
     pthread_exit(NULL);
     
     return 0;
 }