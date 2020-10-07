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

/*Cria a transição
  Entrada: Ponteiro para struct de transição, string com o estado atual da transição, string com
  o caractere lido, string com o estado posterior à transição, string com o retorno da transição
  Retorno: Nenhum
  Pré-condição: Arquivo ter sido lido e dividido
  Pós-condição: Transição é criada
*/
void cria_transicao( Transicao_unitaria *transicao, char *estado_atual,
    char *caractere_lido, char *estado_posterior, char *retorno);


#endif