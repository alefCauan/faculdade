#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char nome[30];
    char data[12];
} Data;

typedef struct {
    int dia, mes, ano;
} DataNascimento;

int calcularIdade(int dia, int mes, int ano) {
    time_t tempoAtual;
    struct tm *infoTempo;
    int idade;

    time(&tempoAtual); 
    infoTempo = localtime(&tempoAtual); 

    idade = infoTempo->tm_year + 1900 - ano; 

    if (infoTempo->tm_mon + 1 < mes || 
        (infoTempo->tm_mon + 1 == mes && infoTempo->tm_mday < dia)) {
        idade--;
    }

    return idade;
}

void AlocarPalavra(char *palavra){
    int cont;

    for(cont = 0;(palavra[cont - 1] != '\n'); cont++){
        palavra[cont] = getchar();
        palavra = realloc(palavra, (cont+1) * sizeof(char));
    }

    cont--;
    palavra[cont] = '\0';
}

int menu(){
    int esc;
    printf("\n_________________________\n");
    do{
        printf("[1] - cadastrar pessoa\n[2] - montar arquivo\n[0] - sair\n");
        scanf("%d", &esc);
    } while(esc > 2 || esc < 0);

    return esc;
}

int main() {
    Data pessoa;
    char *palavra = (char *)malloc(sizeof(char));
    int esc;

    do {
        esc = menu();

        switch (esc) {
            case 1:
                setbuf(stdin, NULL);
                printf("Nome da pessoa: "), AlocarPalavra(palavra);
                strcpy(pessoa.nome, palavra);
                free(palavra);

                palavra = (char *)malloc(sizeof(char));
                setbuf(stdin, NULL);
                printf("Data de nascimento (DD/MM/AAAA): "), AlocarPalavra(palavra);
                strcpy(pessoa.data, palavra);
                free(palavra);

                FILE *arq = fopen("data.txt", "a");
                if (arq == NULL) {
                    printf("ERRO ao abrir!\n");
                    break;
                }

                fprintf(arq, "%s ", pessoa.nome);
                fprintf(arq, "%s\n", pessoa.data);

                fclose(arq);
                break;
        
            case 2: 
                DataNascimento nascimento;

                FILE *arquivo = fopen("data.txt", "r");
                FILE *dados = fopen("dados.txt", "a");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }

                char c;
                int idade, dia, mes, ano;

                while (fscanf(arquivo, "%29[^0-9\n]s", pessoa.nome) != EOF) {
                    fscanf(arquivo, "%c", &c); 
                    fscanf(arquivo, "%11[^\n]s", pessoa.data);
                    fprintf(dados, "%s", pessoa.nome);

                    sscanf(pessoa.data, "%d/%d/%d", &dia, &mes, &ano);
                    idade = calcularIdade(dia, mes, ano);

                    fprintf(dados, " - Idade: %d anos\n", idade);

                    fscanf(arquivo, "%c", &c); 
                }
                
                fclose(arquivo);
                fclose(dados);
                break;
        
            default:
                break;
        }

    } while (esc != 0);
    
    return 0;
}
