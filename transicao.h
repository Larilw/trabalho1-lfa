#ifndef TRANSICAO_H
#define TRANSICAO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 150

typedef struct{
    char estado_atual[TAMANHO];
    char caractere_lido;
    char estado_posterior[TAMANHO];
    char retorno[TAMANHO];
} Transicao_unitaria;

void printa_transicao(Transicao_unitaria t);

void cria_transicao( Transicao_unitaria *transicao, char *estado_atual,
    char *caractere_lido, char *estado_posterior, char *retorno);


#endif