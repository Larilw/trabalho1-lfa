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

/*Carrega o vetor de transições
  Entrada: Ponteiro para struct de estado, inteiro que representa o número de transições, struct de 
  vetor de transições
  Retorno: Nenhum
  Pré-condição: Transições terem sido criadas
  Pós-condição: Transições são carregadas
*/
void carrega_transicao(Estado *estado, int numero_de_transicoes, Transicao_unitaria transicoes[]);

/*Busca a transição de acordo com as transições do estado e o caractere de entrada
  Entrada: Struct de estado, caractere lido
  Retorno: Inteiro que representa a posição da transição ou -1 se não existir transição de acordo 
  com a entrada e o estado
  Pré-condição: Estado preenchido e possuir o caractere lido
  Pós-condição: Posição da transição é conhecida
*/
int busca_transicao(Estado estado, char caractere_lido);

/*Libera as partes alocadas dinâmicamentes na struct de estado
  Entrada: Ponteiro para a struct de estado
  Retorno: Nenhum
  Pré-condição: Estado ter sido peenchido
  Pós-condição: Memória é liberada
*/
void deleta_estado(Estado *estado);

#endif