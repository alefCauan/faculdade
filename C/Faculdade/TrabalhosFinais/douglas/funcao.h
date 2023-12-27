#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct para guardar os pedidos
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

void Menu();

void Sabores(int indice, Pizzaria dados[]);

void Borda(int indice, Pizzaria dados[]);

void Condimentos(int indice, Pizzaria dados[]);

void Adicionais(int indice, Pizzaria dados[]);

void RefriRecheio(int valor, int indice, Pizzaria dados[]);

void CadastrarPedido(int indice, Pizzaria dados[]);

void NotasFiscais(int indice, Pizzaria dados[]);

void ProcurarPedido(int indice, Pizzaria dados[]);

void atualizarPedidos(int indice, Pizzaria dados[]);