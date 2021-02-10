#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

int certo1, certo2, size = 0;
int expected[10000];

void * thread1Function(void * _semente) {
    int semente = *((int*) _semente);
    for(int i=0;i<size;i++) {
        for(int j=1;j<10000;j++)
            rand_r(&semente);
        if(rand_r(&semente)%256 != expected[i]) {
            certo1 = 0;
            break;
        }
    }
}

void * thread2Function(void * _semente) {
    int semente = *((int*) _semente);
    for(int i=0;i<size;i++) {
        for(int j=1;j<10000;j++)
            rand_r(&semente);
        if(rand_r(&semente)%256 != expected[i]) {
            certo2 = 0;
            break;
        }
    }
}

int main(){
    int min, max;
    int number, semente1, semente2;
    pthread_t thread1, thread2;
    
    scanf("%d %d", &min, &max);
    while(scanf("%d", &expected[size]) != EOF) {
        size++;
    }
    
    while (min <= max) {
        semente1 = min;
        certo1 = 1;
        certo2 = 1;
        pthread_create(&thread1, NULL, &thread1Function, (void *) &semente1);

        if(min <= max) {
            semente2 = min;
            pthread_create(&thread2, NULL, &thread2Function, (void *) &semente2);
        }

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        if(certo1 == 1) {
            break;
        }
        if(certo2 == 1) {
            min++;
            break;
        }

        min++;
    }
    printf("%d\n", min);
}