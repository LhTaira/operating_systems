#include <stdio.h>
#include <stdlib.h>

int main(){
    int min, max, size = 0;
    int expected[10000];
    scanf("%d %d", &min, &max);
    while(scanf("%d", &expected[size]) != EOF) {
        size++;
    }
    int number, semente, certo = 1;
    while (min <= max) {
        semente = min;
        certo = 1;
        for(int i=0;i<size;i++) {
            for(int j=1;j<10000;j++)
                rand_r(&semente);
            number = rand_r(&semente)%256;
            if(number != expected[i]) {
                // printf("coco\n");
                certo = 0;
                break;
            }
        }
        if(certo == 1) {
            break;
        }
        min++;
    }
    printf("%d\n", min);
}