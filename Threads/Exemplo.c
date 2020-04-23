//@felipebmuniz
#include <stdio.h>
#include <pthread.h>
#include <windows.h>

void *func1(void *ard) {
    int *v = (int *) ard;
    printf("Chegou T1: %d\n", *v);
}

void *func2(void *ard) {
    char *nome = (char *) ard;
    Sleep(2000);
    printf("Nome T2: %s \n", nome);
}

int main() {
    pthread_t thread1, thread2;

    int v = 10;
    char nome[10] = "Felipe";
    pthread_create(&thread1, NULL, func1, &v);
    pthread_create(&thread2, NULL, func2, &nome);

    printf("Main\n");

    //pthread_join(thread1, NULL);
    pthread_exit(NULL);
    return 0;
}