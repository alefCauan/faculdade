#include <stdio.h>
#include <string.h>

#define CONVERTER_LETRA(c) (c >= 'a' && c <= 'z') ? (c - 32) : (c)

int verificaCaracter(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }else{
        return 0;
    }
}

void recebePalavra(char palavra[]);
void criarArquivo(char palavra[]);
void verificarRepeticoes(char palavra[]);

int main(){
    char palavra[100];

    recebePalavra(palavra);
    criarArquivo(palavra);
    verificarRepeticoes(palavra);

    return 0;
}

void recebePalavra(char palavra[]){
    char c;
    int i=0;

    printf("Digite uma palavra:");
    do{
        do{
            c = getchar();
            if(verificaCaracter(c) == 1){
                printf("%c", c);
                palavra[i] = c;
                i++;
            }else if(c == '\b'){
                printf("\b \b");
                palavra[i] = '\0';
                i--;
            }
            palavra[i] = '\0';

        }while(verificaCaracter(c) == 1);

    }while(c != 13);
}

void criarArquivo(char palavra[]){
    FILE *arquivo;

    arquivo = fopen("palavraRepetida.txt","w");

    fputs(palavra, arquivo);

    fclose(arquivo);
}

void verificarRepeticoes(char palavra[]){
    int tam = strlen(palavra), repeticao, c;

    for(int i=0; i < tam; i++){
        repeticao=0;c=1;
        for(int j=0; j < tam; j++){
            if((CONVERTER_LETRA(palavra[i])) == (CONVERTER_LETRA(palavra[j])) && i != j){
                repeticao++;
            }
        }

        for(int j=0; j < i; j++){
            if((CONVERTER_LETRA(palavra[i])) == (CONVERTER_LETRA(palavra[j])) && i != j){
                c=0;
            }
        }

        if(repeticao > 0 && c != 0){
            printf("\nA letra %c se repete %d vezes", palavra[i], repeticao);
        }
    }
}
