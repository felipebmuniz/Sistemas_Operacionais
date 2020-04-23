//@felipebmuniz
#include <stdio.h>
#include <pthread.h>

void *cont(void *ard) {
    int *v = (int *) ard;
    int i;
    if (*v == 0)
    {
        for (i = 1; i <= 500; i++) {
            printf("%d\n", i);
        }
    } else
    {
        for (i = 500; i > 0; i--) {
            printf("%d\n", i);
        }
    }
}

int main() {
    pthread_t thread1, thread2;
    int c = 0;
    int d = 1;
    pthread_create(&thread1, NULL, cont, &c);
    pthread_create(&thread2, NULL, cont, &d);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}