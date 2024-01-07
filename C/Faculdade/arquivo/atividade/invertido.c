#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void AlocarPalavra(char *palavra){

    int cont;

    printf("nome do arquivo: ");

    for(cont = 0;(palavra[cont - 1] != '\n'); cont++){
    
        palavra[cont] = getchar();
        palavra = realloc(palavra, (cont+1)*sizeof(char));
    }

    cont--;

    palavra[cont] = '\0';
}

void inverter_texto(char *palavra){
    int len = strlen(palavra);
    char aux;

    for(int i = 0; i < len / 2; i++){
        aux = palavra[i];
        palavra[i] = palavra[(len - 1) - i];
        palavra[(len - 1) - i] = aux;
    }

    printf("%s", palavra);


}

void abrir(char *nome)
{
    FILE *arq = fopen(nome, "w+");

    if(arq == NULL)
        printf("ERRO ao abrir arquivo!\n");
    

    fclose(arq);
}

int main(){

    char *nome;

    nome = (char *)malloc(sizeof(char));

    AlocarPalavra(nome);

    abrir(nome);

    inverter_texto(nome);

    abrir(nome);
}