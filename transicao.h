#ifndef TRANSICAO_H
#define TRANSICAO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char estado_atual[150];
    char caractere_lido;
    char estado_posterior[150];
    char retorno[150];
} Transicao_unitaria;

/*Descrição
  Entrada: 
  Retorno:
  Pré-condição:
  Pós-condição:
*/
void printa_transicao(Transicao_unitaria t);

/*Descrição
  Entrada: 
  Retorno:
  Pré-condição:
  Pós-condição:
*/
void cria_transicao( Transicao_unitaria *transicao, char *estado_atual,
    char *caractere_lido, char *estado_posterior, char *retorno);


#endif