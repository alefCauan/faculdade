#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linha(){
    printf("-------------------\n");
}

void JogoAtual(int **jogo)
{
    for(int i = 0; i < 4; i++)
    {
        printf("|");
        for(int j = 0; j < 4; j++)
            printf("%3d ", jogo[i][j]);
        
        printf(" |\n");
    }
}


int VerPontuação(int *pontuação){
    int pegar, pont = 2;

    if(*pontuação > 20 && *pontuação < 70)
    {
        pegar = rand() % 2;

        if(pegar == 1)
            pont = 4;
    }
    else if(*pontuação > 70)
    {
        pegar = rand() % 3;

        if(pegar == 1)
            pont = 4;

        else if(pegar == 2)
            pont = 8;
    }

    return pont;
}

void Gerador(int **jogo, int *pontuação)
{
    int qtd = VerPontuação(pontuação);
    *pontuação = *pontuação + qtd;

    do
    {
        srand(time(NULL));
        int x = rand() % 4;
        int y = rand() % 4;    

        if(jogo[x][y] == 0){
            jogo[x][y] = qtd;
            break;
        }
    }
    while(1);
    
}

void Trocar(int *C, int *B, int *D, int *E, int direção) {
    (direção == 1) ? (*C = 1) : (direção == 2) ? (*E = 1) : (direção == 3) ? (*B = 1) : (*D = 1);
}

void LinColInc(int *LinI, int *LinF, int *IIn, int *ColI, int *ColF, int *InCol, int direção){
    if(direção == 1)
        (*LinI = 3), (*LinF = 0), (*IIn = -1), (*ColI = 0), (*ColF = 4), (*InCol = 1);

    else if(direção == 2)
        (*LinI = 0), (*LinF = 4), (*IIn = 1), (*ColI = 4), (*ColF = 0), (*InCol = -1);  

    else if(direção == 3)
        (*LinI = 0), (*LinF = 3), (*IIn = 1), (*ColI = 0), (*ColF = 4), (*InCol = 1);

    else if(direção == 4)
        (*LinI = 0), (*LinF = 4), (*IIn = 1), (*ColI = 0), (*ColF = 3), (*InCol = 1);
}

void WASD(int **Jogo, int direção)
{
    int Cima = 0, Baixo = 0, Direita = 0, Esquerda = 0;

    int LinI, LinF, IIn, ColI, ColF, InCol, ações = 0;

    Trocar(&Cima, &Baixo, &Direita, &Esquerda, direção);
    
    LinColInc(&LinI, &LinF, &IIn, &ColI, &ColF, &InCol, direção);

    int i = LinI;

   while(1)
   {
       ações = 0;

       if(i == LinF && ações < 1) break;

       if(i == LinF) i = LinI;

       for(int j = ColI ; j != ColF; j += InCol)
       {
           if(Jogo[i][j] != 0 && Jogo[(i - Cima) + Baixo][(j - Esquerda) + Direita] == 0 || Jogo[(i - Cima) + Baixo][(j - Esquerda) + Direita] == Jogo[i][j])
           {
               Jogo[(i - Cima) + Baixo][(j - Esquerda) + Direita] += Jogo[i][j];
               Jogo[i][j] = 0; ações++;
           }
       }

       (i != LinF) ? (i += IIn) : (i = i);
       
       // Adicionar condição de parada
       if(i == LinF && ações == 0) break;
   }
}
   

int ProcessarDireção()
{

    printf("Direção (WASD): ");
    setbuf(stdin, NULL);
    char direção = getchar();

    getchar();
    
    if((direção == 'w') || (direção ==  'W'))
        return 1;

    else if(direção == 'a' || direção ==  'A')
        return 2;

    else if(direção == 's' || direção == 'S')
        return 3;

    else if(direção == 'd' || direção ==  'D')
        return 4;

    printf("Entrada Invalidada!\n");
    return 0;
    
}

void Movimentacação(int **Jogo)
{
    int direção, *pontos = (int *)calloc(1, sizeof(int));
    linha();
    printf("PONTUAÇÃO TOTAL: 2\n");
    linha();
    Gerador(Jogo, pontos);
    JogoAtual(Jogo);
    linha();
    do
    {
        do
        {
            direção = ProcessarDireção();
        } 
        while (direção == 0);

        WASD(Jogo, direção);

        Gerador(Jogo, pontos);

        system("clear");
        linha();
        printf("PONTUAÇÃO TOTAL: %d\n", *pontos);
        linha();
        JogoAtual(Jogo);
        linha();

    } 
    while (1);
}


int main(){

    const int tam = 4;

    int **TwoFourEight = (int **)calloc(tam, sizeof(int *));

    for(int x = 0; x < tam; x++)
        *(TwoFourEight + x) = (int *)calloc(tam, sizeof(int));

    system("clear");

    Movimentacação(TwoFourEight);

    for(int x = 0; x < tam; x++)
        free(*(TwoFourEight + x));
    free(TwoFourEight);

    return 0;
}