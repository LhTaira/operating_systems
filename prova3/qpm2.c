#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <math.h>
#include <semaphore.h>

#define MAX 1000

typedef struct parametro_thread {
    int n;
    pthread_t thread;
    int result;
} parametro_thread;

sem_t semaforo2;
sem_t semaforo10;

parametro_thread parametros[MAX];

int precalculado(int n) {
    if(n < 508079)
        return 508079;

    return -1;
}

int eh_quase_primo(int n) {
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

void * calculaPrimo(void * parametro) {
    int numero = (* (parametro_thread *) parametro).n;
    if(numero < 508079) {
      sem_wait(&semaforo2);
      (* (parametro_thread *) parametro).result = 508079;
      sem_post(&semaforo2);
      void * oloco;
      sem_post(&semaforo10);
      return oloco;
    }
    while(eh_quase_primo(++numero) != 1);
    sem_wait(&semaforo2);
    (* (parametro_thread *) parametro).result = numero;
    sem_post(&semaforo2);
    sem_post(&semaforo10);
}

int main() {
    sem_init(&semaforo2, 0, 2);
    sem_init(&semaforo10, 0, 10);
    int quantidade, n, i = 0, nextThread = 0;

    scanf("%d", &quantidade);
    while(scanf("%d", &parametros[i].n) != EOF) {
        sem_wait(&semaforo10);
        pthread_create(&parametros[i].thread, NULL, calculaPrimo, (void *) &parametros[i]);
        i++;
    }

    for(int j=0; j<i; j++) {
        pthread_join(parametros[j].thread, NULL);
        printf("%d\n", parametros[j].result);
    }

    return 0;
}
