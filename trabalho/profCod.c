#include <stdio.h>
#include <stdlib.h>

int main(){
  int semente=928;
  for(int i=0;i<5;i++)
  {
    for(int j=1;j<10000;j++)
      rand_r(&semente);
    printf("%d\n",rand_r(&semente)%256);
  }
}