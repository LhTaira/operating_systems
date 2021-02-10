#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>

int semente1, semente2, certo1, certo2, expected;
// int toPrint[1000];
// int printSize = 0;
sem_t semaforo2;

void * thread1Function() {
    int semente = semente1;
    // for(int i=0;i<size;i++) {
        for(int j=1;j<100000;j++)
            rand_r(&semente);
        if(rand_r(&semente)%8 != expected) {
            certo1 = 0;
            // break;
        }
    // }
}

void * thread2Function() {
    int semente = semente2;
    // for(int i=0;i<size;i++) {
        for(int j=1;j<100000;j++)
            rand_r(&semente);
        if(rand_r(&semente)%8 != expected) {
            certo2 = 0;
            // break;
        }
    // }
}

int main(){
    // sem_init(&semaforo2, 0, 2);
    int hasRun = 0, min, max;
    pthread_t thread1, thread2;
    
    scanf("%d %d %d", &min, &max, &expected);
    
    while (min <= max) {
        hasRun = 0;
        semente1 = min;
        certo1 = 1;
        certo2 = 1;
        pthread_create(&thread1, NULL, &thread1Function, NULL);
        // min_m_1 = min + 1;
        if(min < max) {
            hasRun = 1;
            semente2 = min + 1;
            pthread_create(&thread2, NULL, &thread2Function, NULL);
        }

        pthread_join(thread1, NULL);

        if(certo1 == 1) {
            printf("%d\n", semente1);
            // toPrint[printSize++] = semente1;
        }
        if(hasRun == 1) {
            pthread_join(thread2, NULL);
            min++;
            if(certo2 == 1) {
                printf("%d\n", semente2);
                // toPrint[printSize++] = semente2;
            }
        }

        min++;
    }
    // for(int i=0; i<printSize; i++) {
    //     printf("%d\n", toPrint[i]);
    // }
}