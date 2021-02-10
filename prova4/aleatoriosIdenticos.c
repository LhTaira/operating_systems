#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>

int certo1, certo2, size = 0;
unsigned int expected;
int toPrint[1000000];
unsigned int printSize = 0;
sem_t semaforo2;

void * thread1Function(void * _semente) {
    unsigned int semente = *((unsigned int*) _semente);
    // for(int i=0;i<size;i++) {
        for(int j=1;j<100000;j++)
            rand_r(&semente);
        if(rand_r(&semente)%8 != expected) {
            certo1 = 0;
            // break;
        }
    // }
}

void * thread2Function(void * _semente) {
    unsigned int semente = *((unsigned int*) _semente);
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
    sem_init(&semaforo2, 0, 2);
    int hasRun = 0;
    unsigned int min, max;
    unsigned int semente1, semente2;
    
    scanf("%u %u %u", &min, &max, &expected);
    
    while (min <= max) {
    pthread_t thread1, thread2;
        hasRun = 0;
        semente1 = min;
        certo1 = 1;
        certo2 = 1;
        pthread_create(&thread1, NULL, &thread1Function, (void *) &semente1);

        if((min + 1) <= max) {
            hasRun = 1;
            semente2 = (min + 1);
            pthread_create(&thread2, NULL, &thread2Function, (void *) &semente2);
        }

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        if(certo1 == 1) {
            toPrint[printSize++] = semente1;
        }
        if(certo2 == 1 && hasRun == 1) {
            min++;
            toPrint[printSize++] = semente2;
        }

        min++;
    }
    for(int i=0; i<printSize; i++) {
        printf("%d\n", toPrint[i]);
    }
}