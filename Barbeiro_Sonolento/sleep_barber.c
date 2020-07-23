#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define cadeiras 3          // Define a quantidades de cadeiras na barbearia
#define num_clientes 10     // Define o numero de clientes
#define true 1              // Define valor 1 como verdadeiro

pthread_t barbeiro;                 // Denominando a thread de barbeiro
pthread_t clientes[num_clientes];   // Denominando a thread de clientes

sem_t clientes_espera;       // Semáforo de espera de clientes
sem_t barbeiro_ocupado;      // Semáforo do barbeiro cortando o cabelo do cliente
sem_t ocupado;               // Semáforo do barbeiro

int id[num_clientes];        // Indentificador do número do cliente

void *novo_barbeiro( void * args);
void *novo_cliente( void * args);

void main () {
  
  sem_init(&barbeiro_ocupado, 0, 1);           // Inicialização do semáforo
  sem_init(&clientes_espera, 0, cadeiras);     // Inicialização do semáforo
  sem_init(&ocupado, 0, 0);                       // Inicialização do semáforo
  

  pthread_create(&barbeiro, NULL, novo_barbeiro, NULL);  // Criação do barbeiro

  int i;
  for (i = 0; i < num_clientes; i++)
  {
    id[i] = i;
    pthread_create(&clientes[i], NULL, novo_cliente, &id[i]); // Criação dos clientes
    usleep(rand()%100);
  }

  for (i = 0; i < num_clientes; i++)
  {
    pthread_join(clientes[i], NULL); // Criação dos clientes
  }

  printf("Fim do espediente do barbeiro.\n");
}

void *novo_barbeiro( void * args) {
  usleep(10);
  while (true)
  {
    sem_wait(&clientes_espera);   // Verifica o se há algum cliente em espera, se não vai dormir
    printf("Barbeiro em atendimento.\n");
    usleep(500);                  // realizando o atendimento
    sem_post(&ocupado);           // Muda o estado do semáforo, sinaliza que o cabelo foi cortado

    printf("O barbeiro está cortando o cabelo de um cliente.\n");
  }
  pthread_exit(NULL);             // Encerra a thread
}

void *novo_cliente( void * args) {
  int id = *(int *) args;
  usleep(id*2);
  if (sem_trywait(&clientes_espera) == 0)
  {
    printf("Um novo cliente chegou: id_%d.\n", id);
    sem_wait(&barbeiro_ocupado);                      // Aguarda o barbeiro
    sem_post(&clientes_espera);                       // Um cliente é atendido
    sem_wait(&ocupado);                               // Espera o corte de cabelo ser finalizado
    printf("Cliente %d cortou o cabelo.\n", id);
    sem_post(&clientes_espera);                       // Libera a cadeira de espera
    sem_post(&barbeiro_ocupado);                      // Barbeiro liberado
  } else
  {
    printf("Barbearia lotada um possível cliente foi embora.\n");
  }
  pthread_exit(NULL);
}