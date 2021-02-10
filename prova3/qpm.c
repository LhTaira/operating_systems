#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <math.h>
#include <semaphore.h>

sem_t semaforo2;
sem_t semaforo10;

typedef struct parametro_thread {
    int n;
    int tid;
    int result;
} parametro_thread;

int precalculado(int n) {
    if(n < 508079)
        return 508079;

    return -1;
}

int eh_quase_primo(int n) {
// printf("shonk %d\n", n);
  if(n==1|| n%2==0)
    return 0;

  int count=0;
  for(int i=3,f=floor(sqrt(n));i<f;i+=2)
    if(n%i==0 && i<11)
      return 0;
    else if(n%i==0 && i>10)
      count++;

  if(count>=10) return 1;
  return 0;
}
void * calcule_sequaseprimo_maluco(void * parametro) {
    int numero = (* (parametro_thread *) parametro).n;
    // int cache = precalculado(numero);
    if((508079 - numero) > 0) {
        sem_wait(&semaforo2);
        (* (parametro_thread *) parametro).result = 508079;
        sem_post(&semaforo2);
        void * oloco;
        return oloco;
    }
    while(eh_quase_primo(++numero) != 1) {
        sem_wait(&semaforo2);
        (* (parametro_thread *) parametro).result = numero;
        sem_post(&semaforo2);
    }
}

void imprime(int result) {
    printf("%d\n", result);
}

int main(void) {
    sem_init(&semaforo2, 0, 2);
    sem_init(&semaforo10, 0, 10);
    int quantidade, numero;
    scanf("%d", &quantidade);
    int quantidade_memento = quantidade;
    while(scanf("%d", &numero)!= EOF) {
        parametro_thread PARAMETRO_A;
        PARAMETRO_A.n=numero;
        pthread_t thread1;
        sem_wait(&semaforo10);
        pthread_create(&thread1, NULL, calcule_sequaseprimo_maluco, (void *) &PARAMETRO_A);
        quantidade--;

        parametro_thread PARAMETRO_B;
        if(quantidade > 0 && scanf("%d", &numero) != EOF) {
            PARAMETRO_B.n=numero;
            pthread_t thread2;
            sem_wait(&semaforo10);
            pthread_create(&thread2, NULL, calcule_sequaseprimo_maluco, (void *) &PARAMETRO_B);
            pthread_join(thread2, NULL);
            sem_post(&semaforo10);
            quantidade--;
        }

        pthread_join(thread1, NULL);
        sem_post(&semaforo10);
            // printf("shonk\n");
        // imprime(PARAMETRO_A.result);
        printf("%d\n", PARAMETRO_A.result);

        if((quantidade>0 && quantidade_memento%2!=0) || (quantidade>=0 && quantidade_memento%2==0)) {
            printf("%d\n", PARAMETRO_B.result);
            // imprime(PARAMETRO_B.result);
        }

    }
    return 0;
}