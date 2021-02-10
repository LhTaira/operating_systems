
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    struct Pilha * prev;
} Pilha;

Pilha * append(Pilha * pilha, int elemento) {
    Pilha * no;
    
    // if(pilha->prev == NULL) {
    //     pilha->n = elemento;

    //     return pilha;
    // } else {
        no = (Pilha *) malloc(sizeof(Pilha));

        no->n = elemento;
        no->prev = pilha;
    // }

    return no;
}

Pilha * pop(Pilha * pilha) {

    Pilha * aux = pilha->prev;

    free(pilha);

    return aux;
}

Pilha * createPilha(Pilha * pilha) {
    pilha = malloc(sizeof(Pilha));

    pilha->prev = NULL;

    return pilha;
}

int main() {

    int commands[10000];
    int numberOfCommands, biggestCommand = 0, arrowUp;

    while(scanf("%d", &numberOfCommands) && numberOfCommands!=0) {
    arrowUp = 0;
    Pilha * pilha;
        for(int i=0; i<numberOfCommands; i++){
            scanf("%d", &commands[i]);
            if(commands[i] > biggestCommand) {
                biggestCommand = commands[i];
            }
        }

        pilha = createPilha(pilha);
        pilha->n = biggestCommand;
        for(int i=(biggestCommand-1); i>=1; i--) {
            pilha = append(pilha, i);
        }

        for(int i=0; i<numberOfCommands; i++) {
            Pilha * pilhaAux = pilha;
            arrowUp++;
            while(pilhaAux->n != commands[i]) {
                arrowUp++;
                pilhaAux = pilhaAux->prev;
            }
            // printf("command %d\n", commands[i]);
            pilha = append(pilha, commands[i]);

        }
        printf("%d\n", arrowUp);

    }
}