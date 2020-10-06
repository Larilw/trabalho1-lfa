#ifndef ESTADO_H
#define ESTADO_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "transicao.h"

typedef struct{
    char nome_do_estado[150];
    int final;
    int inicial;
    Transicao_unitaria *transicoes;
    int numero_de_transicoes;
} Estado;

void carrega_transicao(Estado *estado, int numero_de_transicoes, Transicao_unitaria transicoes[]);


int busca_transicao(Estado estado, char caractere_lido);

void deleta_estado(Estado *estado);

#endif