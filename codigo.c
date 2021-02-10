#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int senha=0;

// void trata_sinal(int sinal) {
//     printf("Recebi %d\n", sinal);
    
//     if(senha==0) {
//         if(sinal==2) {
//             senha=1;
//         }
//     } else if(senha==1) {
//         if(sinal==12) {
//             senha=2;
//         } else if(sinal==2){
//             1+1;
//         } else {
//             senha=0;
//         }
//     } else if(senha==2) {
//         if(sinal==15) {
//             printf("Senha acionada\n");
//             senha=3;

//         } else {
//             senha=0;
//         }
//     } else if(senha==3) {
//         if(sinal==10) {
//             printf("Tchau\n");
//             exit(0);
//         } else {
//             senha=0;
//         }
//     }
// }

void trata_sinal(int sinal) {
    printf("Recebi %d\n", sinal);
    if(senha==0 && sinal==2) {
        senha++;
    } else if(senha==1 && sinal==12) {
        senha++;
    } else if(senha==2 && sinal==15) {
        senha++;
        printf("Senha acionada\n");
    } else if(sinal==2) {
        senha=1;
    } else if(senha==3 && sinal==10) {
        printf("Tchau\n");
        exit(0);
    } else {
        senha=0;
    }

}

int main() {
    signal(SIGINT, trata_sinal);
    signal(SIGTERM, trata_sinal);
    signal(SIGUSR1, trata_sinal);
    signal(SIGUSR2, trata_sinal);

    while(1) {
        pause();
    }
}