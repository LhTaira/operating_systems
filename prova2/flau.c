#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void trata(int s) {
    char entrada[10];

    if(scanf("%s", &entrada) < 1) {
        exit(0);
    }

    switch(s) {
        case SIGUSR1:
            if(strcmp("Igor3k", entrada) == 0) {
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
            break;

        case SIGUSR2:
            if(strcmp("Monark", entrada) == 0) {
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
            break;

        case SIGINT:
            if(strcmp("Con1", entrada) == 0) {
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
            break;

        case SIGTERM:
            if(strcmp("Con2", entrada) == 0) {
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
            break;

        case SIGALRM:
            if(strcmp("Silencio", entrada) == 0) {
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
            break;

    }
}

int main() {
    signal(SIGUSR1, trata);
    signal(SIGUSR2, trata);
    signal(SIGINT, trata);
    signal(SIGTERM, trata);
    signal(SIGALRM, trata);

    while(1)
        pause();
}