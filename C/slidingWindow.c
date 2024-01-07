#include <stdio.h>
#include <stdlib.h>

int Length(int *vetor) 
{
    int tamanho = 0;

    while (*(vetor + tamanho) != 0)
        tamanho++;

    return tamanho - 1;
}

int MaxValue(int Max, int Atual)
{
    if(Max > Atual) return Max;

    return Atual;
}

// sliding window Estatico para encontrar o maior valor

int MaiorSoma(int *vetor, int k)
{
    int Max = vetor[0], somaAtual;

    for(int i = 0; i < Length(vetor) - 1 ; i++)
    {
        somaAtual += vetor[i];

        if(i >= k - 1)
        {
            Max = MaxValue(Max, somaAtual);
            somaAtual -= vetor[i - (k - 1)];
        }
    }

    return Max;
}

// sliding window dinamico para encontrar subarrays com valores >= a um valor X

int Janelas(int *vetor, int Objetivo)
{
    int somaAtual = 0;
    int JanelaInicial = 0;
    int SubMaiores = 0;

    for(int JanelaFinal = 0; JanelaFinal < Length(vetor); JanelaFinal++)
    {
        somaAtual += vetor[JanelaFinal];

        while(somaAtual >= Objetivo)
        {
            SubMaiores++;
            somaAtual -= vetor[JanelaInicial];
            JanelaInicial++;
        }
    }
    
    return SubMaiores;
}

int main()
{
    int vetor[] = {1, 4, 3, 6, 2, 4, 7, 8, 2, 3, 5, 8 ,1 ,9, -1, 2, 3, 2, 2}, tamanho, janelas;

    // encontrar a maior soma dos valores contiguos de um vetor
    tamanho = MaiorSoma(vetor, 2);
    janelas = Janelas(vetor, 10);

    printf("maior soma %d\n", tamanho);
    printf("Janelas maiores que 10: %d\n", janelas);

    return 0;
}