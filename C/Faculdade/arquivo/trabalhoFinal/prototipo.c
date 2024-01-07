#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


typedef struct
{
    char nome[30];
    float preço;
    int quantidade;
} Produtos;

Produtos tempo;

// FILE *Abrir_Arquivo(char *nome, char *modo)
// {
//     FILE *arquivo = fopen(nome, modo);

//     return arquivo;
// }

void Atualizar_Estoque(Produtos produto, int modo)
{
    Produtos temp;
    int redução = 1; 

    FILE *Estoque_retirar = fopen("estoque.txt", "r");
    FILE *Estoque_temp = fopen("estoque_temp.txt", "w+");

    if(modo == 0)
    {
        while (fscanf(Estoque_retirar, "%s %f %d", temp.nome, &temp.preço, &temp.quantidade) == 3)
        {
            if(strstr(temp.nome, produto.nome) != NULL)
            {
                redução = temp.quantidade - produto.quantidade;
                if(redução == 0) continue;
                
                fprintf(Estoque_temp, "%s %.2f %d\n", produto.nome, produto.preço, redução);
            }
            else
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", temp.nome, temp.preço, temp.quantidade);
            } 
        }
        
    }
    else if(modo == 1)
    {
        char item[30]; setbuf(stdin, NULL);
        printf("Nome do produto: "), scanf("%[^\n]", item);
        while (fscanf(Estoque_retirar, "%s %f %d", temp.nome, &temp.preço, &temp.quantidade) == 3)
        {
            if(strstr(temp.nome, produto.nome) != NULL)
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", item, temp.preço, temp.quantidade);
            }
            else
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", temp.nome, temp.preço, temp.quantidade);
            } 
        }
        
    }
    else if(modo == 2)
    {
        while (fscanf(Estoque_retirar, "%s %f %d", temp.nome, &temp.preço, &temp.quantidade) == 3)
        {
            if(strstr(temp.nome, produto.nome) != NULL)
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", temp.nome, produto.preço, temp.quantidade);
            }
            else
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", temp.nome, temp.preço, temp.quantidade);
            } 
        }
        
    }
    else if(modo == 3)
    {
        while (fscanf(Estoque_retirar, "%s %f %d", temp.nome, &temp.preço, &temp.quantidade) == 3)
        {
            if(strstr(temp.nome, produto.nome) != NULL)
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", produto.nome, temp.preço, produto.quantidade);
            }
            else
            {
                fprintf(Estoque_temp, "%s %.2f %d\n", temp.nome, temp.preço, temp.quantidade);
            } 
        }
    }

    fclose(Estoque_retirar);
    fclose(Estoque_temp);

    remove("estoque.txt");
    rename("estoque_temp.txt","estoque.txt");

}

void Adicionar_Estoque(Produtos produto)
{
    char nome[30]; int quant, trocou; float preço; 

    FILE *Stock = fopen("estoque.txt", "r+");

    // Verifica a primeira ocorrencia, se o estoque estiver vazio, adiciona o primeior item

    if(feof(Stock))
    {
        fprintf(Stock, "%s %.2f %d\n", produto.nome, produto.preço, produto.quantidade);

        fclose(Stock);
        return;
    }

    FILE *Stock_temp = fopen("estoque_temp.txt", "w+");
 
    // Copia o arquivo de stock, se o item salvo na struct for o mesmo do Stock, subistitui os valores

    while(fscanf(Stock, "%s %f %d", nome, &preço, &quant) == 3) 
    {
        if(strstr(produto.nome, nome) != NULL)
        {
            int total = quant + produto.quantidade;
            fprintf(Stock_temp, "%s %.2f %d\n", produto.nome, produto.preço, total);
            trocou = 1;
        }
        else
        {
            fprintf(Stock_temp, "%s %.2f %d\n", nome, preço, quant);
        }
    }

    // se substituiu, fecha

    if(trocou == 1)
    {
        fclose(Stock);
        fclose(Stock_temp);

        remove("estoque.txt");
        rename("estoque_temp.txt", "estoque.txt");
        return;
    }

    // caso não, coloca o item no final do arquivo 

    fclose(Stock_temp);

    FILE *Stock_temp2 = fopen("estoque_temp.txt", "a");

    fprintf(Stock_temp2, "%s %.2f %d\n", produto.nome, produto.preço, produto.quantidade);

    fclose(Stock);
    fclose(Stock_temp2);

    remove("estoque.txt");
    rename("estoque_temp.txt", "estoque.txt");
}

void Registro_Compras() 
{   
    Produtos produto;
    printf("Realizar registro automático (ler arquivo de compras)? s/n\n");
    setbuf(stdin, NULL);
    char registro;
    scanf(" %c", &registro);
    getchar();

    if (registro == 's' || registro == 'S') 
    {
        
        char arquivo[50];

        printf("Coloque o nome do arquivo a ser analisado: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", arquivo);

        FILE *Fornecedor = fopen(arquivo, "r");

        if (Fornecedor == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        FILE *Compras_F = fopen("compras.txt", "a");

        if(Compras_F == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        while (fscanf(Fornecedor, "%s %f %d", produto.nome, &produto.preço, &produto.quantidade) == 3) 
        {
            fprintf(Compras_F, "%s %.2f %d\n", produto.nome, produto.preço, produto.quantidade); 
            Adicionar_Estoque(produto);
        }

        fclose(Fornecedor);
        fclose(Compras_F);

        printf("Dados do arquivo foram lidos e escritos em 'compras.txt'.\n");
        return;
    }

    FILE *Compras_C = fopen("compras.txt", "a");

    printf("Quantidade de produtos que foram comprados: ");
    int qtd; scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        setbuf(stdin, NULL);

        printf("Nome produto: "), scanf("%[^\n]", produto.nome);
        printf("preço do produto: "), scanf("%f", &produto.preço);
        printf("Quantidade de Unidades/Quilo: "), scanf("%d", &produto.quantidade);

        fprintf(Compras_C, "%s %.2f %d\n", produto.nome, produto.preço, produto.quantidade);
        Adicionar_Estoque(produto);
    }
    fclose(Compras_C);
}


void Registrar_Vendas()
{
    Produtos produto; char registro, arquivo[30];
    printf("Realizar registro de vendas automático (ler arquivo de compras)? s/n\n");
    setbuf(stdin, NULL);
    scanf(" %c", &registro);
    getchar();

    FILE *Vendas = fopen("vendas.txt", "r+");

    if(registro == 's' || registro == 'S')
    {

        printf("Coloque o nome do arquivo a ser analisado: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", arquivo);

        FILE *Cliente = fopen(arquivo, "r+");

        if (Cliente == NULL)
        {
            printf("Erro ao abrir o arquivo de vendas.\n");
            return;
        }

        while(fscanf(Cliente, "%s %f %d", produto.nome, &produto.preço, &produto.quantidade) == 3)
        {
            fprintf(Vendas, "%s %.2f %d\n", produto.nome, produto.preço, produto.quantidade);
            Atualizar_Estoque(produto, 0);
        }       

        fclose(Vendas);
        fclose(Cliente);
        return;
    }

    int itens;

    printf("Quantidade de itens vendidos: "), scanf("%d", &itens);

    for( int i = 0; i < itens; i++)
    {
        setbuf(stdin, NULL);
        printf("Nome do produto: "), scanf("%[^\n]", produto.nome);
        printf("Preço de venda: "), scanf("%f", &produto.preço);
        printf("Quantidae vendida: "), scanf("%d", &produto.quantidade);

        fprintf(Vendas, "%s %.2f %d\n", produto.nome, produto.preço, produto.quantidade);

        Atualizar_Estoque(produto, 0);
    }

    fclose(Vendas);
    
}

void Exibir_Estoque()
{
    Produtos produto;

    FILE *Exibir_Stock = fopen("estoque.txt", "r");

    while(fscanf(Exibir_Stock, "%s %f %d", produto.nome, &produto.preço, &produto.quantidade) == 3)
    {
        printf("Produto ................. %s\n", produto.nome);
        printf("Preço de venda........... R$%.2f\n", produto.preço);
        printf("Estoque ................. %d\n", produto.quantidade);
        printf("\n");
    }

    fclose(Exibir_Stock);
}

void Verificar_Nome();

void Item_Atualizar()
{
    Produtos produto; int esc = 0;

    setbuf(stdin, NULL);
    printf("Nome do item que deseja atualizar: "), scanf("%[^\n]", produto.nome);

    do
    {
        printf("Qual informação irá mudar: \n");
        printf("[1] - Nome\n");
        printf("[2] - Preço\n");
        printf("[3] - Quantidade\n");
        scanf("%d", &esc);
    } while( esc > 3 || esc < 0);

    switch(esc)
    {
    case 1:
        Atualizar_Estoque(produto, 1);
        break;
    
    case 2: 
        printf("Preço de venda: "), scanf("%f", &produto.preço);
        Atualizar_Estoque(produto, 2);
        break;
    
    case 3: 
        printf("Quantidade vendida: "), scanf("%d", &produto.quantidade);
        Atualizar_Estoque(produto, 3);
        break;
    }
}

void Remover_Produto(Produtos produto)
{
    FILE *Remover_Estoque = fopen("estoque.txt", "r");
    FILE *Novo_Estoque = fopen("estoque_temp.txt", "w+");

    while(fscanf(Remover_Estoque, "%s %f %d", tempo.nome, &tempo.preço, &tempo.quantidade) == 3)
    {
        if(strstr(tempo.nome, produto.nome) != NULL) continue;

        fprintf(Novo_Estoque, "%s %.2f %d\n", tempo.nome, tempo.preço, tempo.quantidade);
    }
    
    fclose(Remover_Estoque);
    fclose(Novo_Estoque);

    remove("estoque.txt");
    rename("estoque_temp.txt", "estoque.txt");
}

int menu()
{
    int saida;
    do
    {
        // system("clear");
        printf("________GERENCIA_DUAS-BARRAS________\n");
        printf("[1] - REGISTRAR COMPRAS DE PRODUTOS\n");
        printf("[2] - REGISTRAR VENDAS DE PRODUTOS\n");
        printf("[3] - EXIBIR PRODUTOS NA LOJA\n");
        printf("[4] - ATUALIZAR INFORMAÇÃO DO PRODUTO\n");
        printf("[5] - RELATÓRIO DE VENDAS\n");
        printf("[6] - REMOVER PRODUTO DO ESTOQUE\n");
        printf("[0] - SAIR\n");

        scanf("%d", &saida);

    }while(saida > 6 || saida < 0);
    
    return saida;
    
}

int main()
{
    Produtos produto;
    int escolha;

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            system("clear");
            Registro_Compras();
            break;
        case 2: 
            Registrar_Vendas();
            break;
        case 3: 
            Exibir_Estoque();
            break;
        case 4: 
            Item_Atualizar();
            break;
        
        case 5: 
            break;

        case 6: 
            setbuf(stdin, NULL);
            printf("Nome do item para remover: "), scanf("%[^\n]", produto.nome);
            Remover_Produto(produto);
            break;
        default:
            break;
        }


        
    } 
    while (escolha != 0);
    
    





    return 0;
}