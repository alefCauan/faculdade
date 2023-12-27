#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idade;
    char comprador[30];
    char nome[50];
    char genero[20];
    float preco;
    char premiacao[30];
} Jogo;

void comprar_jogos(int contador, Jogo jogos[], int max);
void jogo_preço(int cont, Jogo jogos[], int esc);
void genero(int cont, Jogo jogos[], int esc);
void adicionais(int cont, Jogo jogos[], int esc);
void listar_jogos(int contador, Jogo jogos[]);
void buscar_jogo(int contador, Jogo jogos[]);
void Atualizar(Jogo jogos[], int max);
void RecadastroJogo(int contador, Jogo jogos[]);

int main() {
    int opcao, contador = 0, MAX_JOGOS;
    printf("Quantidade maxima de compras: ");
    scanf("%d", &MAX_JOGOS);

    Jogo jogos[MAX_JOGOS];

    do {
        printf("\n__________Menu principal__________\n");
        printf("(1) - Comprar jogos\n");
        printf("(2) - Listar compras\n");
        printf("(3) - Buscar compras\n");
        printf("(4) - Atualizar situação da compra\n");
        printf("(5) - Quantidade de compras realizadas\n");
        printf("(6) - Finalizar aplicação\n");
        printf("_____________________________________\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if(contador == MAX_JOGOS){
                    printf("Limite de compras foi atingido!\n");
                    break;
                }
                comprar_jogos(contador, jogos, MAX_JOGOS);
                contador++;
                break;
            case 2:
                if(contador == 0){
                    printf("Não há jogos para serem listados!\n");
                    break;
                }
                listar_jogos(contador, jogos);
                break;
            case 3:
                if(contador == 0){
                    printf("Não há compras para serem buscadas!\n");
                    break;
                }
                buscar_jogo(contador, jogos);
                break;
            case 4:
                if(contador == 0){
                    printf("Não há compras para serem atualizadas!\n");
                    break;
                }
                Atualizar(jogos, contador);
                break;

            case 5:
                printf("A quantidade de jogos comprados foi de %d", contador);
                break;
            case 6:
                printf("Finalizando a aplicação...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

void comprar_jogos(int contador, Jogo jogos[], int max) {
    int escolha;

    if (contador < max) {
        printf("Nome do usuario: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", jogos[contador].comprador);
        printf("Idade: ");
        scanf("%d", &jogos[contador].idade);

        printf("-----------------=|Jogos disponiveis|=----------------\n");
        printf("-------|JOGO|------------------------------|PREÇO|-----\n");
        printf("[1] - The Last Of Us \t\t\t|- R$210.00\n");
        printf("[2] - God of War \t\t\t|- R$110.00\n");
        printf("[3] - GTA San Andreas \t\t\t|- R$350.00\n");
        printf("[4] - Black \t\t\t\t|- R$150.00\n");
        printf("[5] - Resident Evil 4 \t\t\t|- R$300.00\n");
        printf("[6] - Dragon Ball Budokai Tenkaichi 3   |- R$350.00\n");
        printf("-------------------------------------------------------\n");
        do{
            printf("Sua escolha: ");
            scanf("%d", &escolha);
        }while(escolha > 6 || escolha < 1);

        escolha -= 1;

        jogo_preço(contador, jogos, escolha);

        genero(contador, jogos, escolha);

        adicionais(contador, jogos, escolha);

    } 
    else {
        printf("Limite de compras foi atingido!\n");
    }
}

void jogo_preço(int cont, Jogo jogos[], int esc){
    if(esc == 0){
        strcpy(jogos[cont].nome,"The Last Of Us");
        jogos[cont].preco = 210;
    }
    else if(esc == 1){
        strcpy(jogos[cont].nome,"God of War");
        jogos[cont].preco = 110;
    }
    else if(esc == 2){
        strcpy(jogos[cont].nome,"GTA San Andreas");
        jogos[cont].preco = 350;
    }
    else if(esc == 3){
        strcpy(jogos[cont].nome,"Black");
        jogos[cont].preco = 150;
    }
    else if(esc == 4){
        strcpy(jogos[cont].nome,"Resident Evil 4");
        jogos[cont].preco = 300;
    }
    else if(esc == 5){
        strcpy(jogos[cont].nome,"Dragon Ball Budokai Tenkaichi 3");
        jogos[cont].preco = 350;
    }

}

void genero(int cont, Jogo jogos[], int esc){
    if(esc == 0){
        strcpy(jogos[cont].genero,"Zumbi");
    }
    else if(esc == 1){
        strcpy(jogos[cont].genero,"Ação");
    }
    else if(esc == 2){
        strcpy(jogos[cont].genero,"Aventura");
    }
    else if(esc == 3){
        strcpy(jogos[cont].genero,"Tiro");
    }
    else if(esc == 4){
        strcpy(jogos[cont].genero,"Terror");
    }
    else if(esc == 5){
        strcpy(jogos[cont].genero,"Luta");
    }
}

void adicionais(int cont, Jogo jogos[], int esc){
    if (esc == 0){
        strcpy(jogos[cont].premiacao,"Action Figure Ellie com Violão");
        printf("Parabéns, você ganhou uma Action Figure Ellie com Violão!\n");
    }
    else if (esc == 1){
        strcpy(jogos[cont].premiacao,"Lamina do Caos (tamanho Real)");
        printf("Parabéns, você ganhou uma Lamina do Caos de (tamanho Real)!\n");
    }
    else if (esc == 2){
        strcpy(jogos[cont].premiacao,"CJ's story book");
        printf("Parabéns, você ganhou o CJ's story book!\n");
    }
    else if (esc == 3){
        strcpy(jogos[cont].premiacao," Colar Prata M4A1");
        printf("Parabéns, você ganhou um Colar Prata M4A1!\n");
    }
    else if (esc == 4){
        strcpy(jogos[cont].premiacao,"Cachecol e Chapeu Leon mafioso");
        printf("Parabéns, você ganhou o Cachecol e Chapeu do Leon mafioso!\n");
    }
    else if (esc == 5){
        strcpy(jogos[cont].premiacao,"Boneco 3d Goku SSJ God");
        printf("Parabéns, você ganhou um Boneco 3d Goku SSJ God!\n");
    }
}

void listar_jogos(int contador, Jogo jogos[]) {
    printf("Listagem de compras:\n\n");
    for (int i = 0; i < contador; i++) {
        printf("_________[COMPRA N°%d]__________\n", i+1);
        printf("--[NOME]--------------[IDADE]--\n");
        printf("%s \t| %d\n", jogos[i].comprador, jogos[i].idade);
        printf("-------------JOGO--------------\n");
        printf("%s\n", jogos[i].nome);
        printf("-------------------------------\n");
        printf("---------[CATEGORIA]-----------\n");
        printf("%s\n", jogos[i].genero);
        printf("-------------------------------\n");
        printf("-----------[PREÇO]-------------\n");
        printf("R$%.2f\n", jogos[i].preco);
        printf("---------[PREMIAÇÃO]-----------\n");
        printf("%s\n", jogos[i].premiacao);
        printf("-------------------------------\n");
        printf("_______________________________\n\n");
    }
}

void buscar_jogo(int contador, Jogo jogos[]) {
    char genero[30];
    char name[30];
    float preço;
    int esc, i, oi = 0;

    printf("________Procurar_Compra_______\n");
    printf("[1] - Nome do jogo\n[2] - Categoria\n[3] - preço\n");
    printf("______________________________\n");
    do{
        printf("Procurar por: ");
        scanf("%d", &esc);
    }while(esc > 3 || esc < 1);

    if(esc == 1){
        printf("Nome do jogo: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", name);
    }
    else if(esc == 2){
        printf("Categoria do jogo: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", genero);
    }
    else if(esc == 3){
        printf("Preço do jogo: ");
        scanf("%f", &preço);
    }

    for(i = 0; i < contador; i++){
        if(strstr(jogos[i].nome, name) != NULL || strstr(jogos[i].genero, genero) != NULL 
        || preço == jogos[i].preco)
        {   
            if(oi == 0){
                printf("______COMPRA-ENCONTRADA______\n");
            }
            oi++;
            printf("_________[COMPRA N°%d]__________\n", i+1);
            printf("-------------JOGO--------------\n");
            printf("%s\n", jogos[i].nome);
            printf("-------------------------------\n");
            printf("---------[CATEGORIA]-----------\n");
            printf("%s\n", jogos[i].genero);
            printf("-------------------------------\n");
            printf("-----------[PREÇO]-------------\n");
            printf("R$%.2f\n", jogos[i].preco);
            printf("---------[PREMIAÇÃO]-----------\n");
            printf("%s\n", jogos[i].premiacao);
            printf("-------------------------------\n");
            printf("_______________________________\n\n");
        }
    }
    if(oi == 0){
        printf("Nenhuma compra foi encontrada\n");
    }

}

void Atualizar(Jogo jogos[], int max){
    int esc, id;
    printf("____ATUALIZAR_DADOS_DE_COMPRA____\n");
    printf("(1) - Jogo comprado\n");
    printf("(2) - Nome do cliente\n");
    printf("(3) - Idade do cliente\n");
    printf("__________________________________\n");
    do{
        printf("Sua escolha: ");
        scanf("%d", &esc);
    }while(esc > 3 || esc < 1);
    do{
        printf("n° da compra: ");
        scanf("%d", &id);
    }while(id > max || id < 1);

    id--;

    if(esc == 1){
        RecadastroJogo(id, jogos);
    }
    else if(esc == 2){
        printf("Novo nome para o comprador: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", jogos[id].comprador);
    }
    else if(esc == 3){
        printf("Nova idade do comprador: ");
        scanf("%d", &jogos[id].idade);
    }
}

void RecadastroJogo(int contador, Jogo jogos[]){
    int escolha;
    printf("-----------------=|Jogos disponiveis|=----------------\n");
    printf("-------|JOGO|------------------------------|PREÇO|-----\n");
    printf("[1] - The Last Of Us \t\t\t|- R$210.00\n");
    printf("[2] - God of War \t\t\t|- R$110.00\n");
    printf("[3] - GTA San Andreas \t\t\t|- R$350.00\n");
    printf("[4] - Black \t\t\t\t|- R$150.00\n");
    printf("[5] - Resident Evil 4 \t\t\t|- R$300.00\n");
    printf("[6] - Dragon Ball Budokai Tenkaichi 3   |- R$350.00\n");
    printf("-------------------------------------------------------\n");
    do{
        printf("Sua escolha: ");
        scanf("%d", &escolha);
    }while(escolha > 6 || escolha < 1);

    escolha -= 1;

    jogo_preço(contador, jogos, escolha);

    genero(contador, jogos, escolha);

    adicionais(contador, jogos, escolha);

}

