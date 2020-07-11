#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define cadeiras 5          // Define a quantidades de cadeiras na barbearia
#define num_clientes 10     // Define o numero de clientes
#define true 1              // Define valor 1 como verdadeiro

pthread_t barbeiro;                 // Denominando a thread de barbeiro
pthread_t clientes[num_clientes];   // Denominando a thread de clientes

sem_t clientes_espera;        // Semáforo de espera de clientes
sem_t ocupado;               // Semáforo do barbeiro
sem_t mutex;                  // Semáforo de exclução mútua

int esperando = 0;            // Número de clientes em espera

void* novo_barbeiro( void * args);
void* novo_cliente( void * args);

void main () {
  sem_init(&ocupado, true, 0);           // Inicialização do semáforo
  sem_init(&clientes_espera, true, 0);    // Inicialização do semáforo
  sem_init(&mutex, true, 1);              // Inicialização do semáforo

  pthread_create(&barbeiro, NULL, &novo_barbeiro, NULL);  // Criação do barbeiro

  int i;
  for (i = 0; i < num_clientes; i++)
  {
    pthread_create(&clientes, NULL, &novo_cliente, NULL); // Criação dos clientes
    sleep(rand()%100);
  }

  for (i = 0; i < num_clientes; i++)
  {
    pthread_join(&clientes[i], NULL); // Criação dos clientes
  }

  printf('Fim do espediente do barbeiro.\n');
}

void* novo_barbeiro( void * args) {
  while (true)
  {
    sem_wait(&clientes_espera);   // Verifica o se há algum cliente em espera, se não vai dormir
    sem_wait(&mutex);             // Verifica o espaço crítico
    esperando--;                  // Diminui um cliente da fila de espera 
    sem_post(&ocupado);           // Muda o estado do semáforo
    sem_post(&mutex);             // Muda o estado do semáforo
    printf('O barbeiro está cortando o cabelo de um cliente.\n');
  }
  pthread_exit(NULL);             // Encerra a thread
}

void* novo_cliente( void * args) {
  sem_wait(&mutex);   // Verifica o espaço crítico

  if (esperando < cadeiras)
  {
    printf('Um novo cliente chegou.\n');
    esperando++;
    sem_post(&clientes_espera);
    sem_post(&mutex);
    sem_wait(&ocupado);
    printf('Cliente está cortando o cabelo.\n');
  } else
  {
    sem_post(&mutex);
    printf('Barbearia lotada um possível cliente foi embora.\n');
  }
  pthread_exit(NULL);
}