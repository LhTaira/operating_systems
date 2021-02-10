#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <math.h>

typedef struct parametro_thread {
    int n;
    int tid;
    int result;
} parametro_thread;

int eh_quase_primo(int n)
{
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
    while(eh_quase_primo(++numero) != 1);
    (* (parametro_thread *) parametro).result = numero;
}

void imprime(int result) {
    printf("%d\n", result);
}

int main(void) {
    int quantidade, numero;
    scanf("%d", &quantidade);
    int quantidade_memento = quantidade;
    while(1) {
        if(scanf("%d", &numero)== EOF) break;
        parametro_thread PARAMETRO_A;
        PARAMETRO_A.n=numero;
        pthread_t thread1;
        pthread_create(&thread1, NULL, calcule_sequaseprimo_maluco, (void *) &PARAMETRO_A);
        quantidade--;

        parametro_thread PARAMETRO_B;
        if(quantidade>0) {
            if(scanf("%d", &numero)== EOF) break;
            PARAMETRO_B.n=numero;
            pthread_t thread2;
            pthread_create(&thread2, NULL, calcule_sequaseprimo_maluco, (void *) &PARAMETRO_B);
            pthread_join(thread2, NULL);
            quantidade--;
        }

        pthread_join(thread1, NULL);
        imprime(PARAMETRO_A.result);

        if((quantidade>0 && quantidade_memento%2!=0) || (quantidade>=0 && quantidade_memento%2==0)) {
            imprime(PARAMETRO_B.result);
        }

    }
    return 0;
}