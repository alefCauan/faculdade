#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{   
    FILE *fp = fopen("teste.txt", "r");

    int caractere;
    while ((caractere = fgetc(fp)) != EOF) {
        putchar(caractere);
    }
    printf("\n"); 
    rewind(fp); // resetei a posição do arquivo

    while ((caractere = fgetc(fp)) != EOF) {
        putchar(caractere);
    }

    fclose(fp);

    return 0;
}