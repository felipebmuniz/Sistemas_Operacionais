/*Crie um programa em C que apresente duas funções para threads (produtor e
consumidor), nesse devem ser criadas a quantidade de threads definidas por uma
variável global QTD e utilizar outra variável global chamada “valor”. O produtor só
pode produzir um número se essa variável tiver sido consumida (valor=0), quando ele
for produzir é atribuído um número aleatório a variável “valor”. O consumido só pode
consumir um número, se ele já tiver sido produzido (valor≠0), quando ele consome é
atribuído valor=0. O programa deve seguir as seguintes especificações:

- A função produtor e consumidor devem receber o id da thread como parâmetro no
momento de sua criação.

- O produtor deve produzir um número aleatório menor que 100 e armazenar na
variável “valor”. Após produzir esse número deve apresentar a mensagem "produtor
%d: produziu %d", onde o primeiro campo é o id da thread e o segundo é o valor
aleatório que foi obtido.

- Essa mensagem e o processo de obtenção do valor devem estar dentro do loop do
produtor, logo a verificação da variável "valor" deve ser dentro do loop. Utilize um
valor alto para o número de iterações nesse laço de repetição.

- Ao sair do loop, seja do produtor ou consumido, finalize a thread.

- O consumidor deve apresentar a mensagem "consumidor %d: consumiu %d", onde
o primeiro campo é o numero do processo e o segundo é o valor da variável
compartilhada "valor", que foi produzido aleatoriamente pelo processo produtor.

- Essa mensagem deve está dentro do loop do consumidor, logo a verificação da
variável "valor" deve ser dentro do loop.

- Caso a variável "valor" seja diferente de zero, então ele apresenta essa mensagem, e
deve alterar o valor da variável "valor" para zero (valor=0).

- Crie 4 pares de threads com esses processos (4 threads para consumidores e 4 threads
para produtores).
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LOOP 100000
#define QTD 4
int valor = 0;

void *produtor(int id)
{
    int cont = 0;
	while (cont < LOOP)   /* Loop de repetição para verificação de produção */
	{
        if (valor == 0) /* Condição que o produtor so pode produzir se o valor for zero */
        {
            valor = ((rand() % 98) + 1);    /* gera algo para por no buffer entre 1 e 99 */
            printf("Produtor %d produziu %d\n", id, valor);
        }
        cont ++;
	}
}

void *consumidor(int id)
{
	int cont = 0;
	while (cont < LOOP) /* Loop para verificação de consumir produto */
	{ 
        if (valor != 0)
        {
            printf("Consumidor %d consumiu %d\n", id, valor);
             valor = 0;
        }
        cont ++;
	}
}

void main()  
{
    pthread_t prod[QTD];
	pthread_t cons[QTD];

    int id;

	printf("Programa Produtor-Consumidor\n");

    printf("Disparando threads produtores\n");

    for (id = 0; id < QTD; id++)
    {
        pthread_create(&prod[id], NULL, produtor, id);
    }

    printf("Disparando threads consumidores\n");
	
    for (id = 0; id < QTD; id++)
    {
        pthread_create(&cons[id], NULL, consumidor, id);
    }

	pthread_join(prod[0],NULL);
	pthread_join(prod[1],NULL);
	pthread_join(prod[2],NULL);
	pthread_join(prod[3],NULL);
	pthread_join(cons[0],NULL);
	pthread_join(cons[1],NULL);
	pthread_join(cons[2],NULL);
	pthread_join(cons[3],NULL);
	
    printf("Terminado processo Produtor-Consumidor.\n\n");
}