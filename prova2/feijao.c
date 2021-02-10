#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int arrayA[10000000];
int arrayB[10000000];
int zero = 0;
int size;

//int compare (const void * a, const void * b)
// {
//     if( *(int*)a - *(int*)b < 0 )
//         return -1;
//     if( *(int*)a - *(int*)b > 0 )
//         return 1;
//     return 0;
// }

int compare(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void * thread_sort() {
    qsort(arrayA, size, sizeof(int), compare);
}

//int main() {
//     printf("%d \n", sizeof(int));
// }

int main() {
   int iguais = 1;
    scanf("%d", &size);

    for(int i=0; i<size; i++) {
        scanf("%ld", &arrayA[i]);
    }

    for(int i=0; i<size; i++) {
        scanf("%ld", &arrayB[i]);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, &thread_sort, NULL);

    qsort(arrayB, size, sizeof(int), compare);

    pthread_join(thread, NULL);

    // for(int i=0; i<size; i++) {
    //     printf("%ld", arrayA[i]);
    // }
    // printf("\n");
    // for(int i=0; i<size; i++) {
    //     printf("%ld", arrayB[i]);
    // }

    // printf("\n");

    for(int i=0; i<size; i++) {
        if(compare(&arrayA[i], &arrayB[i]) != zero) {
            iguais = 0;
            break;
        }
    }

    if(iguais == 1) {
        printf("Mesmos elementos");
    } else {
        printf("Diferentes");
    }

    return 0;
}
