#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int verificar(char ctr)
{
    if(ctr == '\0' || ctr == '\n')
        return 1;

    return ((ctr > 64 && ctr < 91 ) || (ctr > 93 && ctr < 126)) ? 1 : 0;
}

void AlocarPalavra(char *palavra){

    int cont, v;

    for(cont = 0;(palavra[cont - 1] != '\n'); cont++){
        do{
            palavra[cont] = getchar();
            v = verificar(palavra[cont]);
        }while(v!= 1);
        palavra = realloc(palavra, (cont+1)*sizeof(char));
    }

    cont--; palavra[cont] = '\0';
}

int menu(){
    printf("[1] - Inserir usuario\n");
    printf("[2] - Procurar letras repitidas\n");
    printf("[0] - Sair\n");
    int esc; scanf("%d", &esc); return esc;
}

void abrir(char *n_arquivo){

    FILE *arq = fopen(n_arquivo, "a+");
    int esc, cont = 0;

    if(arq == NULL)
        printf("Erro ao abrir arquivo!\n");

    char chr, c;


    do
    {   
        char *user = (char *)malloc(sizeof(char));

        esc = menu();

        switch (esc)
        {
        case 1:
            FILE *arq = fopen(n_arquivo, "a+");
            printf("Novo usuario: ");
            setbuf(stdin, NULL);
            AlocarPalavra(user);
            fprintf(arq, "%s \n", user);
            free(user);
            fclose(arq);

            break;
        
        case 2:     
            FILE *arq2 = fopen(n_arquivo, "r");
            printf("Caractere a ser contado: "), scanf(" %c", &chr);

            c = fgetc(arq2);
        
            while (c != EOF) {
                if (chr == c)
                    cont++;
                c = fgetc(arq2);
            }

            printf("A letra [%c] aparece %d vezes\n", chr, cont);
            cont = 0;
            fclose(arq2);

            break;
        }


    } while (esc != 0);

    fclose(arq);


}

int main(){

    char *palavra = (char *)malloc(sizeof(char));

    printf("Nome do arquivo: ");

    AlocarPalavra(palavra);

    FILE *arquivo = fopen(palavra, "w");
    fclose(arquivo);

    abrir(palavra);

    free(palavra);

    return 0;
}