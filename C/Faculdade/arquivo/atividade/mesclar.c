#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void AlocarPalavra(char *palavra){

    int cont;

    for(cont = 0;(palavra[cont - 1] != '\n'); cont++){
    
        palavra[cont] = getchar();
        palavra = realloc(palavra, (cont+1)*sizeof(char));
    }

    cont--; palavra[cont] = '\0';
}

void abrir(char *nome, char *nome2, char *mescla){

    int num;

    FILE *arq = fopen(nome, "r+");

    if(arq == NULL){
        printf("ERRO ao abrir arquivo 1!\n");
    }

    FILE *arq2 = fopen(nome2, "r+");

    if(arq == NULL){
        printf("ERRO ao abrir arquivo 2!\n");
    }
    
    FILE *arq3 = fopen(mescla, "w+");

    if(arq3 == NULL){
        printf("ERRO ao abrir arquivo de mescla!\n");
    }

    do{

        if( fscanf(arq, "%d", &num) == 1)
            fprintf(arq3, "%d ", num);
        

        if(fscanf(arq2, "%d", &num) == 1)
            fprintf(arq3, "%d ", num);
        else
            break;
        

    }while(1);
    
}

int main(){

    char *nome1 = (char *)malloc(sizeof(char *));
    char *nome2 = (char *)malloc(sizeof(char *));
    char *nome3 = (char *)malloc(sizeof(char *));

    printf("nome do primeiro arquivo: ");

    AlocarPalavra(nome1);

    printf("nome do segundo arquivo: ");

    AlocarPalavra(nome2);

    printf("nome do arquivo de mescla: ");

    AlocarPalavra(nome3);

    abrir(nome1, nome2, nome3);

    return 0;
}