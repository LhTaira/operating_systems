#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>


int main(){
  int semente=6;
  for(int i=0;i<5;i++)
  {
    for(int j=1;j<100000;j++)
      rand_r(&semente);
    printf("%d\n",rand_r(&semente)%8);
  }
}