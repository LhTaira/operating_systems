#include <stdio.h>
#include <stdlib.h>

int mi, mf, valor_invalido;
int * possibilidades; //vetor com as possiveis sementes de mi ate mf
int aleatorio, gerei, igual, tamanho;

void preenchePossibilidades();
void compara();
    
int main(){

    scanf(" %d %d", &mi, &mf);

    if(mi == mf){
        printf("%d\n", mi);
        return 0;
    }//end if mi == mf

    tamanho = (int) mf-mi+1; //qtd de possibilidades de sementes

    if(mi == 0){
        valor_invalido = mf+1;
    }
    else{
        valor_invalido = mi-1;
    }

    printf("valor invalido e %d\n", valor_invalido);

    preenchePossibilidades();

    while(scanf(" %d", &aleatorio) != EOF){
        compara();
    }//end while

    printf("cheguei no final\n");

    for(int i=0; i<tamanho; i++){
        if(possibilidades[i] != valor_invalido){
            printf("%d\n", possibilidades[i]);
            break;
        }
    }

    return 0;
}

void compara(){

    int semente;

    for(int j=0; j<tamanho; j++){

        //printf("AQUI\n");

        if(possibilidades[j] == valor_invalido){
            continue;
        }//end if semente na posicao j ja foi descartada

        semente = possibilidades[j];

        printf("SEMENTE %d\n\n", semente);

        for(int i=1; i<10000; i++){
            rand_r(&semente);
        }//end for 9999 chamadas na rand_r

        gerei = rand_r(&semente) % 256;

        printf("gerei %d --- aleatorio %d\ncom a semente %d e possibilidade %d\n\n", gerei, aleatorio, semente, possibilidades[j]);

        if(gerei != aleatorio){
            possibilidades[j] = valor_invalido; //descarta essa semente === TALVEZ DE ERRADO MARCAR UNSIGNED COM -1
        }//end if valor gerado diferente do valor lido

    }//end for j em possibilidades

}//end compara

void preenchePossibilidades(){

    //printf("AQUI aloca tamanho %d\n", tamanho);

    possibilidades = (int *)calloc(tamanho, sizeof(int));

    //if(possibilidades == NULL){
    //    printf("NULL\n");
    //    exit(0);
    //}

    //printf("AQUI\n");

    int i = mi;

    for(int j=0; i<=mf; j++){
        //printf("AQUI i %d j %d\n", i, j);
        possibilidades[j] = i;
        printf("%d\n", possibilidades[j]);
        i++;
    }

    //printf("AQUI\n");

    return;
}//end preenche possibilidades