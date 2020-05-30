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