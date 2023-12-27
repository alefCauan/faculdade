#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{   
    float valorTemp[5];
    char nome[35];
    char sabor[20];
    char borda[10];
    char condimentos[30];
    int pacotes;
    char rfgr_adicionais[30];
    char rc_adicionais[30];
    float valor;

}Pizzaria;

void Menu(){
    printf("_______PIZZARIA BOM GOSTO_______\n");
    printf("1 - Adicionar pedidos\n2 - Apresentar notas fiscais\n3 - Buscar pedido\n4 - Atualizar situação do pedido\n5 - Pedidos realizados\n6 - Passar dia\n7 - sair\n");
    printf("________________________________\n");
}

// função dos sabores de pizza
void Sabores(int indice, Pizzaria dados[]){
    int opc, i;

    printf("____________Sabores____________\n");
    printf("[1] - Queijo \t\t-R$20-\n[2] - Calabresa \t-R$30-\n[3] - Carne de sol \t-R$24-\n[4] - Milho \t\t-R$15-\n[5] - Frango \t\t-R$25-\n");
    printf("_______________________________\n");
    do{
        printf("Opção escolhida: ");
        scanf("%d", &opc);
    }while(opc > 5 || opc < 1);

    if(opc == 1){
        strcpy(dados[indice].sabor,"Queijo");
        dados[indice].valor += 20;
        dados[indice].valorTemp[0] = 20;
    }
    else if(opc == 2){
        strcpy(dados[indice].sabor,"Calabresa");
        dados[indice].valor += 30;
        dados[indice].valorTemp[0] = 30;
    }
    else if(opc == 3){
        strcpy(dados[indice].sabor,"Carne de sol");
        dados[indice].valor += 24;
        dados[indice].valorTemp[0] = 24;
    }
    else if(opc == 4){
        strcpy(dados[indice].sabor,"Milho");
        dados[indice].valor += 15;
        dados[indice].valorTemp[0] = 15;
    }
    else if(opc == 5){
        strcpy(dados[indice].sabor,"Frango");
        dados[indice].valor += 25;
        dados[indice].valorTemp[0] = 25;
    }
}

// Função para saber e o cliente quis borda ou não
void Borda(int indice, Pizzaria dados[]){
    int opc, i;

    printf("_____ADICIONAR BORDA_____\n");
    printf("[1] - Sem borda\n[2] - Com borda -R$2.50-\n");
    printf("_________________________\n");

    do{
        printf("Escolha do cliente:");
        scanf("%d", &opc);

    }while(opc > 2 || opc < 1);

    if(opc == 1){
        strcpy(dados[indice].borda,"Sem borda");
        dados[indice].valorTemp[1] = 0;
    }
    else if(opc == 2){
        strcpy(dados[indice].borda,"Com borda");
        dados[indice].valor += 2.50;
        dados[indice].valorTemp[1] = 2.50;
    }
}

// Função para receber os codimentos requisitados pelo cliente e sua quantidade
void Condimentos(int indice, Pizzaria dados[]){
    int opc, quant;

    printf("______Condimentos______\n");
    printf("[1] - Ketchup  -R$0.10-\n[2] - Maionese -R$0.15-\n[3] - Catupiry -R$0.15-\n");
    printf("_______________________\n");

    do{
        printf("Condimento escolhido: ");
        scanf("%d", &opc);

    }while(opc > 3 || opc < 1);

    printf("Quantidade de pacotes: ");
    scanf("%d", &quant);

    if(opc == 1){
        strcpy(dados[indice].condimentos,"Ketchup");
        dados[indice].valor += (0.10 * quant);
        dados[indice].pacotes = quant;
        dados[indice].valorTemp[2] = (0.10 * quant);
    }
    else if(opc == 2){
        strcpy(dados[indice].condimentos,"Maionese");
        dados[indice].valor += (0.15 * quant);
        dados[indice].pacotes = quant;
        dados[indice].valorTemp[2] = (0.15 * quant);
    }
    else if(opc == 3){
        strcpy(dados[indice].condimentos,"Catupiry");
        dados[indice].valor += (0.15 * quant);
        dados[indice].pacotes = quant;
        dados[indice].valorTemp[2] = (0.15 * quant);
    }
}

// Função para saber se o o cliente adicionou "adicionais"
void Adicionais(int indice, Pizzaria dados[]){
    int opc;
    char op[10];

    do{
        printf("Houve adicionais? (s/n) ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", op);

    }while(strstr(op, "s") == NULL && strstr(op,"n") == NULL);

    if(strcmp(op, "s") == 0){
        printf(" _____Adicionais_____\n");
        printf("[1] - Refrigerantes\n[2] - Recheio\n[3] - Ambos\n");
        printf("_____________________\n");

        do{
            printf("Escolha do cliente: ");
            scanf("%d", &opc);
        }while(opc > 3 || opc < 1);

        RefriRecheio(opc, indice, dados);
    }
    else{
        strcpy(dados[indice].rfgr_adicionais,"Sem refrigerantes");
        strcpy(dados[indice].rc_adicionais,"Sem recheio extra");
        dados[indice].valorTemp[3] = 0;
        dados[indice].valorTemp[4] = 0;
    }
}

// Função para receber os adicionais do pedido 
void RefriRecheio(int valor, int indice, Pizzaria dados[]){
    int opc;

    if(valor == 1){
        strcpy(dados[indice].rc_adicionais,"Sem recheio extra");
        dados[indice].valorTemp[4] == 0;

        printf("__________Refrigerantes__________\n");
        printf("[1] - Coca-cola 350ml \t-R$4-\n[2] - Quaraná 350ml \t-R$4.50-\n[3] - Fanta 350ml \t-R$4.90-\n");
        printf("_________________________________\n");

        do{
            printf("Escolha do clinte: ");
            scanf("%d", &opc);
        }while(opc > 3 || opc < 1);

        if(opc == 1){
            strcpy(dados[indice].rfgr_adicionais,"Coca-Cola");
            dados[indice].valor += 4;
            dados[indice].valorTemp[3] = 4;
        }
        else if(opc == 2){
            strcpy(dados[indice].rfgr_adicionais,"Quaraná");
            dados[indice].valor += 4.50;
            dados[indice].valorTemp[3] = 4.50;
        }
        else if(opc == 3){
            strcpy(dados[indice].rfgr_adicionais,"Fanta");
            dados[indice].valor += 4.90;
            dados[indice].valorTemp[3] = 4.90;
        }
    }
    else if (valor == 2){
        strcpy(dados[indice].rfgr_adicionais,"Sem refrigerantes");
        dados[indice].valorTemp[3] = 0;

        printf("______Recheio_Extra______\n");
        printf("[1] - Queijo \t-R$4.50-\n[2] - Pepperoni -R$3.50-\n[3] - Bacon \t-R$4.50-\n");
        printf("_________________________\n");

        do{
            printf("Escolha do clinte: ");
            scanf("%d", &opc);

        }while(opc > 3 || opc < 1);

        if(opc == 1){
            strcpy(dados[indice].rc_adicionais,"Queijo");
            dados[indice].valor += 4.50;
            dados[indice].valorTemp[4] = 4.50;
        }
        else if(opc == 2){
            strcpy(dados[indice].rc_adicionais,"Pepperoni");
            dados[indice].valor += 3.50;
            dados[indice].valorTemp[4] = 3.50;
        }
        else if(opc == 3){
            strcpy(dados[indice].rc_adicionais,"Bacon");
            dados[indice].valor += 4.50;
            dados[indice].valorTemp[4] = 4.50;
        }
    }
    else if(valor == 3){
        printf("__________Refrigerantes__________\n");
        printf("[1] - Coca-cola 350ml \t-R$4-\n[2] - Quaraná 350ml \t-R$4.50-\n[3] - Fanta 350ml \t-R$4.90-\n");
        printf("_________________________________\n");

        do{
            printf("Escolha do clinte: ");
            scanf("%d", &opc);

        }while(opc > 3 || opc < 1);

        if(opc == 1){
            strcpy(dados[indice].rfgr_adicionais,"Coca-Cola");
            dados[indice].valor += 4;
            dados[indice].valorTemp[3] = 4;
        }
        else if(opc == 2){
            strcpy(dados[indice].rfgr_adicionais,"Quaraná");
            dados[indice].valor += 4.50;
            dados[indice].valorTemp[3] = 4.50;
        }
        else if(opc == 3){
            strcpy(dados[indice].rfgr_adicionais,"Fanta");
            dados[indice].valor += 4.90;
            dados[indice].valorTemp[3] = 4.90;
        }

        printf("______Recheio_Extra______\n");
         printf("[1] - Queijo \t-R$4.50-\n[2] - Pepperoni -R$3.50-\n[3] - Bacon \t-R$4.50-\n");
        printf("_________________________\n");
        printf("Escolha do clinte: ");
        scanf("%d", &opc);

        if(opc == 1){
            strcpy(dados[indice].rc_adicionais,"Queijo");
            dados[indice].valor += 4.50;
            dados[indice].valorTemp[4] = 4.50;
        }
        else if(opc == 2){
            strcpy(dados[indice].rc_adicionais,"Pepperoni");
            dados[indice].valor += 3.50;
            dados[indice].valorTemp[4] = 3.50;
        }
        else if(opc == 3){
            strcpy(dados[indice].rc_adicionais,"Bacon");
            dados[indice].valor += 4.50;
            dados[indice].valorTemp[4] = 4.50;
        }
    }
}

// Função principal onde os pedidos serão recebidos
void CadastrarPedido(int indice, Pizzaria dados[]){
    printf("Nome do cliente: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", dados[indice].nome);

    Sabores(indice, dados);
    Borda(indice,  dados);
    Condimentos(indice, dados);
    Adicionais(indice, dados);

    printf("----------------------------\n");
    printf("PEDIDO AGENDADO COM SUCESSO!\n");
    printf("----------------------------\n");
}


// Função para mostrar os pedidos realizados
void NotasFiscais(int indice, Pizzaria dados[]){
    int i, j;

    for(i = 0; i < indice; i++){
        printf("\n----------------------Comprovante----------------------\n");
        printf("---------------------Transação[0%d]--------------------\n", i+1);
        printf("Cliente....................... %24s\n", dados[i].nome);
        printf("Sabor da pizza................ %24s\n", dados[i].sabor);
        printf("Borda......................... %24s\n", dados[i].borda);
        printf("Condimentos................... %20s %2dx\n", dados[i].condimentos, dados[i].pacotes);
        printf("Refrigerante.................. %24s\n", dados[i].rfgr_adicionais);
        printf("Recheio extra................. %24s\n", dados[i].rc_adicionais);
        printf("_______________________________________________________\n");
        printf("VALOR TOTAL A PAGAR.........................   R$%6.2lf\n", dados[i].valor);
        printf("_______________________________________________________\n");
        printf("-------------------------------------------------------\n");
        printf("---------------AGRADECEMOS A PREFERÊNCIA---------------\n");
        printf("----------------------VOLTE SEMPRE---------------------\n\n");
        for(j = 0; j < 5; j++){
            printf("%f / ", dados[i].valorTemp[j]);
        }
        printf("\n");
    }
}


//Função para buscar por "palavra-chave"
void ProcurarPedido(int indice, Pizzaria dados[]){
    int i, op, achou = 0;
    char name[30], sabor[20];
    float preço;

    printf("----Procurar pedido----\n");
    printf("[1] - Cliente\n[2] - Sabor\n[3] - Preço\n");
    printf("-----------------------\n");

    do{
        printf("Procurar por: ");
        scanf("%d", &op);
    }while(op > 3 || op < 1);

    if(op == 1){

        printf("Nome do cliente: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", name);
    }
    else if(op == 2){

        printf("Sabor da pizza: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", sabor);
    }
    else if(op == 3){

        printf("Valor pago: ");
        setbuf(stdin, NULL);
        scanf("%f", &preço);
    }

    for(i = 0; i < indice; i++){
        if(strcmp(dados[i].nome, name) == 0 || strcmp(dados[i].sabor, sabor) == 0 || (fabs(dados[i].valor - preço) < 0.01)){

            achou++;

            if(achou==1)
                printf("__________________Pedido encontrado!__________________\n");

            printf("---------------------Transação[0%d]--------------------\n", i+1);
            printf("Cliente....................... %24s\n", dados[i].nome);
            printf("Sabor da pizza................ %24s\n", dados[i].sabor);
            printf("Borda......................... %24s\n", dados[i].borda);
            printf("Condimentos................... %20s %2dx\n", dados[i].condimentos, dados[i].pacotes);
            printf("Refrigerante.................. %24s\n", dados[i].rfgr_adicionais);
            printf("Recheio extra................. %24s\n", dados[i].rc_adicionais);
            printf("_______________________________________________________\n");
            printf("VALOR TOTAL A PAGAR.........................   R$%6.2lf\n", dados[i].valor);
            printf("_______________________________________________________\n");

        }

    }       
    if(achou == 0){
        printf("Não há nenhum pedido com essa informação!\n");
    }
        
}

void atualizarPedidos(int indice, Pizzaria dados[]){
    int op, id, opc;
    char continuar[10];

    do{
        printf("Número da transação: ");
        scanf("%d", &id);
    }while(id > indice || id < 1);

    id--;

    do{

        printf("_______Atualizar pedido_______\n");
        printf("[1] - Nome do cliente\n[2] - Sabor da pizza\n[3] - Borda\n[4] - Condimentos\n[5] - Adicionais\n");
        printf("______________________________\n");
        do{
            printf("Mudança desejada: ");
            scanf("%d", &op);

        }while(op > 6 || op < 1);

        if(op == 1){
            printf("Novo nome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", dados[id].nome);
        }
        else if(op == 2){
            dados[id].valor -= dados[id].valorTemp[0];
            Sabores(id, dados);
        }
        else if(op == 3){
            dados[id].valor -= dados[id].valorTemp[1];
            Borda(id, dados);
        }
        else if(op == 4){
            dados[id].valor -= dados[id].valorTemp[2];
            Condimentos(id, dados);
        }
        else if(op == 5){
            printf("______Adicionais_____\n");
            printf("[1] - Refrigerantes\n[2] - Recheio\n[3] - Ambos\n");
            printf("_____________________\n");
            do{
                printf("Escolha do cliente: ");
                scanf("%d", &opc);

            }while(opc > 3 || opc < 1);

            if(opc == 1)
                dados[id].valor -= dados[id].valorTemp[3];

            else if(opc == 2)
                dados[id].valor -= dados[id].valorTemp[4];

            else if(opc == 3){
                dados[id].valor -= dados[id].valorTemp[3];
                dados[id].valor -= dados[id].valorTemp[4];
            }    

            RefriRecheio(opc, indice, dados);

        } 
        do{
            printf("Deseja continuar? (s/n): ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", continuar);

        }while(strstr(continuar,"s") == NULL && strstr(continuar,"n") == NULL);

    }while(strstr(continuar,"n") == NULL);   

}