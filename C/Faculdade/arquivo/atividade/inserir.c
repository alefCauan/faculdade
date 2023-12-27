#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inserirPalavra(char *palavra) {
    FILE *arquivo;

    arquivo = fopen("palavra.txt", "w+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%s", palavra);

    fclose(arquivo);
}

int ContarLetra(char palavra[]){

    int cont;

    for(cont = 0;(palavra[cont - 1] != '\n'); cont++){
    
        palavra[cont] = getchar();
        palavra = realloc(palavra, (cont+1)*sizeof(char));
    }

    cont--;

    palavra[cont] = '\0';
    
    return cont;
}

int main() {
    
    char *palavra;
    int tam;

    palavra = (char *) malloc(sizeof(char));

    tam = ContarLetra(palavra);
    inserirPalavra(palavra);
    
    printf("A palavra %s tem %d letras!\n", palavra, tam);

    return 0;
}
