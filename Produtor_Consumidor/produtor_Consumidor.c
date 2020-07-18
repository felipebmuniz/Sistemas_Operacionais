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

#define LOOP 1000000
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
        if (valor != 0) /* Condição que o consumidor so pode consumir se o valor diferente de zero */
        {
            printf("Consumidor %d consumiu %d\n", id, valor);
             valor = 0;     /* Consome o valor que foi produzido pelo produtor */
        }
        cont ++;
	}
}

void main()  
{
    /* Definindo os vetores de threads */
    pthread_t prod[QTD];
	pthread_t cons[QTD];

    int id, i;     /* ID de cada thread na sua criação */

	//printf("Programa Produtor-Consumidor\n\n");

    //printf("Disparando threads produtores\n\n");

    for (id = 0; id < QTD; id++)
    {
        pthread_create(&prod[id], NULL, produtor, id);
    }

    //printf("Disparando threads consumidores\n");
	
    for (id = 0; id < QTD; id++)
    {
        pthread_create(&cons[id], NULL, consumidor, id);
    }

    for (i = 0; i < QTD; i++)
    {
        pthread_join(prod[i],NULL);
        pthread_join(cons[i],NULL);
    }
	
    printf("Terminado processo Produtor-Consumidor.\n\n");
}

/* Execute os threads algumas vezes, observe as saídas e responda as observações:

3.1-Por que alguns consumidores consumiram mais de uma vez em seguida o mesmo
número?

R: Pois na criação do algoritmo não se tem um controle bem definido sobre os processos em execução, portanto,
quando um consumidor terminou de consumir o escalonador trocou para outro consumidor antes de encerrar o anterior
ocasionando um erro no consumo dos produtos.

3.2-Por que o consumidor consumiu um determinado número, mas o produtor só o
produziu depois?

R: Se da ao mesmo problema da pergunta anterior, os processos tem uma variável em comum na região crítia,
onde o valor do produto é constantemente alterado, sendo que não foi implementado um metodo de anulação de corridas
o escalonador tem livre acesso a troca de processos em execução, sendo assim antes o produtor foi executado e
produziu e pois na variável de produtos, porém, antes de ser encerrado o escalonador trocou para um processo de 
consumidor e consumiu o valor encontrado em produtos e só depois o produtor foi encerrado.

3.3-Tirando o fato de ser gerado números aleatórios, por que a execução sempre ocorre
em ordem diferente?

Se dá ao fato de não ter um controle de fluxo entre os processos, para a resolução deste problema envolvendo o
algoritmo produtor/consumidor pode-se implementar diferentes soluções, como: a utilização de buffer e variável de acesso
, porém, nesse método ocorre espera ocupada e desperdício de recursos de processamento; outro método é a utilização de 
semáforos e o mutex, tendo assim um resultado mais satisfatório e um bom controle da ordem de execução dos processos do algoritmo.
*/