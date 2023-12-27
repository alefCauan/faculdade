#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, tam, passos, c = 0, op = 0, cont, lim;

    printf("tamanho: "), scanf("%d", &tam);

    int **matriz = (int **)malloc(tam * sizeof(int *));

    
    for(i = 0; i < tam; i++)
        *(matriz + i) = (int *)malloc(tam * sizeof(int));

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++, cont++)
            matriz[i][j] = cont;
    }
    
    lim = tam * tam;

    int *vet = (int *)malloc(lim * sizeof(int));

    i = 0, j = 0;

    vet[c] = matriz[i][j];

    do
    {

        (op == 0) ? passos++ : passos --; c++;
        (op == 0) ? j++ : i++;
 
        vet[c] = matriz[i][j];

        if(j == tam - 1) // decrementar matriz a partir do quina - pares
            op = 1;

        for(int x = 0; x < passos; x++){
            i++, j--, c++;
            vet[c] = matriz[i][j];
        }
        
        (op == 0) ? passos++ : passos --; c++;
        (op == 0) ? i++ : j++;

        vet[c] = matriz[i][j];

        if(c == lim - 1) // limite de impar e par
            break;

        for (int x = 0; x < passos; x++){
            i--, j++, c++;
            vet[c] = matriz[i][j]; 
        }

        if(j == tam - 1) // decrementar matriz a partir do quina - impares
            op = 1;

    }while(1);
    
    printf("vetor: ");
    for(i = 0; i < lim; i++)
        printf("[%d] ", vet[i]);
    
    free(vet);

    for(i = 0; i < tam; i++)
        free(*(matriz + i));
        
    free(matriz);
    
    return 0;
}