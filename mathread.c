#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int size;
int matriz_a[2000][2000];
int matriz_b[2000][2000];
int matriz_c[2000][2000];

void multiplica_1() {
    int aux = 0;
    for (int i=0; i<size/2; i++) {
        for (int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                aux = aux + (matriz_a[i][k] * matriz_b[k][j]);
            }
            matriz_c[i][j] = aux;
            aux = 0;
        }
    }
}

void multiplica_2() {
    int aux = 0;
    for (int i=size/2; i<size; i++) {
        for (int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                aux = aux + (matriz_a[i][k] * matriz_b[k][j]);
            }
            matriz_c[i][j] = aux;
            aux = 0;
        }
    }
}

int main() {
    scanf("%d", &size);

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf("%d", &matriz_a[i][j]);
        }
    }

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf("%d", &matriz_b[i][j]);
        }
    }

    pthread_t thread_1;
    pthread_t thread_2;

    pthread_create(&thread_1, NULL, &multiplica_1, NULL);
    pthread_create(&thread_2, NULL, &multiplica_2, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", matriz_c[i][j]);
        }
        printf("\n");
    }
}