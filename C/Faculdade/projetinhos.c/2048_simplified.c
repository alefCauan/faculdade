#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int Cima, Baixo, Direita, Esquerda;
} Direção;

typedef struct {
    int LinI, LinF, IIn, ColI, ColF, InCol;
} LinhasColunas;

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
        pegar = rand() % 3;

        if(pegar == 1)
            pont = 4;
    }
    else if(*pontuação > 70)
    {
        pegar = rand() % 7;

        if(pegar == 1 || pegar == 2)
            pont = 4;

        else if(pegar == 3)
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

void Trocar(Direção *dir, int direção) 
{
    dir->Cima = dir->Baixo = dir->Direita = dir->Esquerda = 0;

    switch (direção) 
    {
        case 1: dir->Cima = 1; break;
        case 2: dir->Esquerda = 1; break;
        case 3: dir->Baixo = 1; break;
        case 4: dir->Direita = 1; break;
    }
}

void LinColInc(LinhasColunas *LinCol, int direção) 
{
    LinCol->LinI = LinCol->LinF = LinCol->IIn = LinCol->ColI = LinCol->ColF = LinCol->InCol = 0;

    switch (direção) 
    {
        case 1: LinCol->LinI = 3; LinCol->IIn = -1; LinCol->ColF = 4; LinCol->InCol = 1; break;
        case 2: LinCol->LinF = 4; LinCol->IIn = 1; LinCol->ColI = 4; LinCol->InCol = -1; break;
        case 3: LinCol->LinF = 3; LinCol->IIn = 1; LinCol->ColF = 4; LinCol->InCol = 1; break;
        case 4: LinCol->LinF = 4; LinCol->IIn = 1; LinCol->ColF = 3; LinCol->InCol = 1; break;
    }
}

void WASD(int **Jogo, int direção)
{
    Direção direc = {0, 0, 0, 0};
    LinhasColunas LinCol;

    Trocar(&direc, direção);
    LinColInc(&LinCol, direção);

    int ações = 0;

    do {
        ações = 0;

        for (int i = LinCol.LinI; i != LinCol.LinF; i += LinCol.IIn) 
        {
            for (int j = LinCol.ColI; j != LinCol.ColF; j += LinCol.InCol) 
            {
                if (Jogo[i][j] == 0) continue;

                else if (Jogo[i][j] != 0 && Jogo[i - direc.Cima + direc.Baixo][j - direc.Esquerda + direc.Direita] == Jogo[i][j]) {
                    Jogo[i - direc.Cima + direc.Baixo][j - direc.Esquerda + direc.Direita] += Jogo[i][j];
                    Jogo[i][j] = 0; ações++;
                }
                else if (Jogo[i - direc.Cima + direc.Baixo][j - direc.Esquerda + direc.Direita] == 0) {
                    Jogo[i - direc.Cima + direc.Baixo][j - direc.Esquerda + direc.Direita] += Jogo[i][j];
                    Jogo[i][j] = 0; ações++;
                }
            }
        }
    } while (ações >= 1);
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