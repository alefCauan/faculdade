#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define COLUNAS 15
#define LINHAS 15
#define TAMANHO_MAXIMO 256


struct SnakePart
{
    int x;
    int y;
};

struct Snake
{
    int comprimento;

    struct SnakePart corpo[TAMANHO_MAXIMO];
};

void LimparTela()
{
    system("clear || cls");
}

void GameOver()
{
    printf("FIM DE JOGO!\n");
    exit(EXIT_FAILURE);
}

void Desenhar_Jogo(char tela[][COLUNAS])
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if(i == 0 || j == 0 || j == COLUNAS - 1 || i == LINHAS - 1)
                tela[i][j] = '#';
            else
                tela[i][j] = ' ';

        }
    }
    
}

struct Snake snake;

void Mostrar_Jogo(char tela[][COLUNAS])
{
    printf("PONTOS = %d\n", snake.comprimento - 1);
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
            printf("%c ", tela[i][j]);

        printf("\n");
    }
}


void Desenhar_Cobra(char tela[][COLUNAS])
{
    for(int i = snake.comprimento - 1; i > 0 ; i--)
        tela[snake.corpo[i].x][snake.corpo[i].y] = '*';

    if(tela[snake.corpo[0].x][snake.corpo[0].y] != ' ')
        if(tela[snake.corpo[0].x][snake.corpo[0].y] != '+')
            GameOver();


    tela[snake.corpo[0].x][snake.corpo[0].y] = '@';
    
}


void Movimentar_Cobra(int DeltaX, int DeltaY)
{
    for(int i = snake.comprimento - 1; i > 0 ; i--)
    {
        snake.corpo[i] = snake.corpo[i - 1];
    }

    snake.corpo[0].x += DeltaX;
    snake.corpo[0].y += DeltaY;
}

int localX;
int localY;

void Desenhar_Comida(char tela[][COLUNAS], int *comidas)
{
    int quant = 0;
    if (*comidas == 0)
    {
        do{
            quant ++;
            localX = 1 + rand() % (LINHAS - 2);
            localY = 1 + rand() % (COLUNAS - 2);
        } 
        while(tela[localX][localY] != ' ');


        tela[localX][localY] = '+';
        *comidas = 1;
    }

    tela[localX][localY] = '+';
}


void Crescer(int *comidas)
{
    if (snake.corpo[0].x == localX && snake.corpo[0].y == localY)
    {
        *comidas = 0;
        snake.comprimento += 1;
    }
}

int direcao_x = 0;
int direcao_y = 0;

void Ler_Teclado()
{
    char mover = getchar();

    int novo_x = direcao_x;
    int novo_y = direcao_y;

    switch(mover)
    {
    case 'w':
        if (direcao_x != 1) 
        {
            novo_x = -1;
            novo_y = 0;
        }
        break;
    case 'a':
        if (direcao_y != 1) 
        {
            novo_x = 0;
            novo_y = -1;
        }
        break;
    case 's':
        if (direcao_x != -1) 
        {
            novo_x = 1;
            novo_y = 0;
        }
        break;
    case 'd':
        if (direcao_y != -1) 
        {
            novo_x = 0;
            novo_y = 1;
        }
        break;
    default:
        novo_x = direcao_x;
        novo_y = direcao_y;
        break;
    }

    direcao_x = novo_x;
    direcao_y = novo_y;
    
    Movimentar_Cobra(direcao_x, direcao_y);
    
    while (getchar() != '\n');
}

int main()
{
    char tela[LINHAS][COLUNAS];
    int comidas = 0;

    snake.comprimento = 1;
    snake.corpo[0].x = 2;
    snake.corpo[0].y = 2;

    while(true)
    {
        LimparTela();
        Desenhar_Jogo(tela);
        Desenhar_Cobra(tela);
        Crescer(&comidas);
        Desenhar_Comida(tela, &comidas);
        Mostrar_Jogo(tela);
        Ler_Teclado();
    }

    return 0;
}

