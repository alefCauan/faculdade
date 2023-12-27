#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char servico[3][20];
int quantcadastrados, quant, indiceEncontrado = -1;
float preco[3][1];

typedef struct // usei typedef para falitar a vida kk
{
    char nome[100], empresa[100], telefone[20];
    int id;
}cliente;

// tem que passar a struct como parametro, do jeito que você tava fazendo não funcionava
int cadastrar (cliente func[]);
int calcular (cliente func[]);
void listar (cliente func[]);
int buscar (cliente func[]);

int main () {

    // Precisa definir a quantidade (quant) antes de passar ele para a struct 
    printf("\nDigite a quantidade de clientes que podem ser cadastrados: ");
    scanf(" %d", &quant); 

    int l, op;

    cliente func[quant];

    //Definição dos tipos de serviço
    for (l = 0; l < 3; l++)
    {
        printf("\nInforme o %d tipo de servico: ", l+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]", servico[l]); // esse scanf é melhor para pegar mais de uma palavra, troquei pelo gets
    }
    
    //Definição dos preços
    for (l = 0; l < 3; l++)
    {
        printf("\nDigite o preco que sera cobrado quando o servico for %s: ", servico[l]);
        setbuf(stdin, NULL);
        scanf(" %f", &preco[l][0]);
    }

    //system("CLS"); não sei a utilidade, só comentei pq podia tá atrapalhando
    
    do
    {
        printf("\n===============MENU===============");
        printf("\n1 - Cadastrar.");
        printf("\n2 - Clientes ja cadastrados.");
        printf("\n3 - Calcular servico.");
        printf("\n4 - Buscar por clientes.");
        printf("\n5 - Atualizar precos.");
        printf("\n6 - Analisar o armazenamento.");
        printf("\n7 - Finalizar a aplicacao.");
        printf("\n==================================\n");

        //Blindagem
        do
        {
            printf("Informe o que deseja realizar: ");
            scanf(" %d", &op);
        } while (op > 7 || op < 1);
    
        switch (op)
        {
        case 1:
            printf("\n==================================\n");
            printf("Cadastrando cliente:\n");
            cadastrar(func); 
            break;

        case 2:
            printf("\n==================================\n");
            printf("Listando os clientes ja cadastrados:\n");
            listar(func);
            break;

        case 3:
            printf("\n==================================\n");
            printf("Calculando o servico:\n");
            calcular(func);
            break;

        case 4:
            printf("\n==================================\n");
            printf("Buscando por clientes:\n");
            buscar(func);
            break;
        
        case 5:
            printf("\n==================================\n");
            printf("Atualizando precos:\n");
            do
            {
                for (l = 0; l < 3; l++)
                {
                    printf("\t%d: %s \t%.2f", l, servico[l], preco[l][0]);
                    printf("\n");
                }
                printf("\n4: Sair.");
                
                printf("\nEscolha o servico que queira atualizar o preco: ");
                setbuf(stdin, NULL);
                scanf(" %d", &l);

                if(l == 4){ // Não estava saindo, coloquei essa condição
                    break;
                }

                printf("\nPara qual valor? ");
                setbuf(stdin, NULL);
                scanf(" %f", &preco[l][0]);

            } while (l != 4);
            break;

        case 6:
            printf("\n==================================\n");
            printf("Analisando armazenamento:\n");
            if (quantcadastrados < quant)
            {
                printf("\n%d / %d: Armazenamento disponivel!", quantcadastrados, quant);
            }

            else
            {
                printf("\n%d / %d: Armazenamento indisponível!", quantcadastrados, quant);
            }
            break;

        default:
            printf("\n==================================\n");
            printf("Finalizando o programa...\n");
            break;
        }
    
    } while (op != 7);      
}

int cadastrar (cliente func[]) {


    if (quantcadastrados < quant)
    {
        printf("\nInforme o nome do cliente: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", func[quantcadastrados].nome);

        printf("\nInforme a empresa na qual o cliente pertence: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", func[quantcadastrados].empresa);

        printf("\nInforme o telefone para contato: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", func[quantcadastrados].telefone);
        
        func[quantcadastrados].id = quantcadastrados;
    
        printf("\nCliente cadastrado!");
        printf("\n%d: %s | %s | %s\n", func[quantcadastrados].id, func[quantcadastrados].nome, func[quantcadastrados].empresa, func[quantcadastrados].telefone);

        quantcadastrados++;
    }
    
    else 
    {
        printf("\nArmazenamento Indisponível!");
    }
}

int calcular (cliente func[]) {

    float total, valor; 
    int pecas, i;

    buscar(func);

    total = 0;
    do
    {
        valor = 0;
        for (i = 0; i < 3; i++)
        {
            printf("\n");
            printf("%d: %s \t%.2f", i, servico[i], preco[i][0]);
            printf("\n");
        }
        printf("\n4 - Sair.\n");
    
        printf("\nInforme o servico que foi ofertado: ");
        setbuf(stdin, NULL);
        scanf("%d", &i);

        if(i == 4){ // Não tava saindo, então coloquei essa condição
            break;
        }

        printf("\nInforme a quantidade de pecas feitas: ");
        setbuf(stdin, NULL);
        scanf("%d", &pecas);

        valor = (preco[i][0]) * (pecas);
        total = (total) + (valor);
        
        printf("\nO total do servico foi: %.2f", valor);
        printf("\nO total da conta do cliente %s e: %.2f", func[indiceEncontrado].nome, total);

    } while (i != 4);

    //return 0; não parece ser útil, eu acho
}

void listar (cliente func[]) {

    int i;

    for (i = 0; i < quantcadastrados; i++)
    {
        printf("\n%d: %s | %s | %s", func[i].id, func[i].nome, func[i].empresa, func[i].telefone);
    }
    
}

int buscar (cliente func[]) {

    int idBusca, i;

    indiceEncontrado = -1;
    
    printf("\nDigite o ID do cliente: ");
    setbuf(stdin, NULL);
    scanf("%d", &idBusca);
   
    for (i = 0; i < quantcadastrados; i++) 
    {
        if (func[i].id == idBusca) 
        {
            indiceEncontrado = i;
        }
    }

    if (indiceEncontrado != -1) 
    {
        printf("\n%d: %s | %s | %s\n", func[indiceEncontrado].id, func[indiceEncontrado].nome, func[indiceEncontrado].empresa, func[indiceEncontrado].telefone);
    } 
    
    else 
    {
        printf("\nCliente não encontrado.\n");
    }

    return indiceEncontrado;
}