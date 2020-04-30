//@felipebmuniz

/*Implemente um programa em C que realize o cálculo das somas dos
 valores das linhas de uma matriz 5x5 de números inteiros e imprima o
 resultado na tela. O cálculo do somatório de cada linha deve ser realizado
 em paralelo por threads.*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>
 #include <windows.h>

 // Definindo o tamanho fixo da matriz a ser trabalhada
 #define LINHA 5
 #define COLUM 5
 #define NUMTHREADS 5

 // Declarando variável ponteiro para ponteiro
 int **matriz;
 
 void preecherMatriz() {
     // Aloca o vetor de ponteiros
     matriz = (int**)malloc(LINHA * sizeof(int*));

     // Alocando cada uma das linhas da matriz
     int i;
     for (i = 0; i < LINHA; i++) {
         matriz[i] = (int*)malloc(COLUM* sizeof(int));
     }

     // Preenchendo a matriz
     int j;
     for (i = 0; i < LINHA; i++) {
         for (j = 0; j < COLUM; j++) {
             //preenchimento de valores aleatorios entre 0 e 24;
             matriz[i][j] = (rand() % 24);
         }
     }

     // Mostra a matriz para o usuário
     for(i = 0; i < 5; i++) {
		 for(j = 0; j < 5; j++) {
			printf("%d\t", matriz[i][j]);
        }
        printf("\n");
	 }
     printf("\n");
 }

 void *somatorio (void *ard) {
     // Recebendo o endereço da linha do somatorio e convertendo seu valor
     int *linha = (int*) ard;
     
     //realizando a recpção do valor do ponteiro para passar na matriz
     int l = *linha;

     //variavel para realização do somatório
     int soma = 0;
     
     int i;
     for (i = 0; i < 5; i++) {
         // Realizando a soma dos valores das colunas nas linhas respctivas
         soma = soma + matriz[l][i];
     }
     
     printf("Valor do somatorio da linha %d: %d\n", l, soma);
     Sleep(0);
 }

 void main() {  
     // Instanciando o vetor de threads para somatorio de cada linha da matriz
     pthread_t thread[NUMTHREADS];

     // Cria a matriz dinâmica e demonstra ela para o usuario, preenchida por rand
     preecherMatriz();

     // Criando as threads no seu vetor e passando a função somatorio para a
     // execução e a linha que deve ser somada
     int aux = 0;
     for (;aux < NUMTHREADS; aux++) {
         printf("Thread: %d\t", aux);
         pthread_create(&thread[aux], NULL, somatorio(&aux), NULL);
     } 
     
     // Responsavel por esperar todas as threads criadas executarem
     pthread_exit(NULL);
 }