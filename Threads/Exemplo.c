//@felipebmuniz
#include <stdio.h>
#include <pthread.h>
#include <windows.h>

int global = 0;

void *func1(void *ard) {
    global++;
    printf("T1: %d\n", global);
    //int *v = (int *) ard;
    //printf("Chegou T1: %d\n", *v);
}

void *func2(void *ard) {
    global++;
    printf("T2: %d\n", global);
    //char *nome = (char *) ard;
    //Sleep(2000);
    //printf("Nome T2: %s \n", nome);
}

int main() {
    pthread_t thread1[5], thread2[5];

    //int v = 10;
    //char nome[10] = "Felipe";

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        pthread_create(&thread1[i], NULL, func1, NULL);
        pthread_create(&thread2[i], NULL, func2, NULL);
    }
    
    //pthread_join(thread1, NULL);
    printf("Main\n");
    pthread_exit(NULL);
    return 0;
}