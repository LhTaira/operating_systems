#include <stdio.h>
#define MAX 1000000
int array[MAX];
int n;
int quadros;

void zero(int * memory, int max) {
    for(int i=0; i<max; i++) {
        memory[i] = 0;
    }
}

int isInMemory(int * memory, int number) {
    for(int i=0; i<quadros; i++) {
        if(memory[i] == number) {
            return 1;
        }
    }
    return 0;
}

int calculateFaults() {
    int memory[MAX];
    zero(memory, quadros);
    int faults = 0;
    int nextToDie = 0;
    for(int i=0; i<n; i++) {
        if(isInMemory(memory, array[i]) == 0) {
            faults++;

            memory[nextToDie++] = array[i];
            if (nextToDie == quadros) {
                nextToDie = 0;
            }
        }
    }
    return faults;
}

int main() {
    int baseQuadros = 0;
    int baseFaults;
    int mostFaults = 0;
    int cases = 0;
    int faults;

    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }

    while(scanf("%d", &quadros)!= EOF) {
        faults = calculateFaults();
        if(cases == 0 || quadros < baseQuadros) {
            baseQuadros = quadros;
            baseFaults = faults;
        }
        if(faults > mostFaults) {
            mostFaults = faults;
        }

        printf("%d %d\n", quadros, faults);
        cases++;
    }

    if(mostFaults > baseFaults) {
        printf("Belady detectado\n");
    } else {
        printf("Sem anomalia\n");
    }

    return 0;
}