#ifndef LER_ARQUIVO_TXT_H
#define LER_ARQUIVO_TXT_H

#include <stdio.h>
#include <string.h>
#define TAMANHO_MAX 150
#define TAMANHO_MATRIZ_MAX 20

//struct que define uma transição 
typedef struct{
    char estado_anterior[TAMANHO_MAX];
    char entrada[TAMANHO_MAX];
    char estado_posterior[TAMANHO_MAX];
    char saida[TAMANHO_MAX];
}Transicao;

//struct que define o arquivo de entrada
typedef struct{
    char alfabeto_entrada[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX];
    char alfabeto_saida[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX];
    char estados[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX];
    char estado_inicial[TAMANHO_MAX];
    char estados_finais[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX];
    Transicao transicao[TAMANHO_MAX];

}Leitura_do_arquivo;

/*Divisão da linha lida e gravação */
void grava_inicial(char *linha_lida, Leitura_do_arquivo *automato);

void grava_conjuntos(char *linha_lida,int numero_da_linha, Leitura_do_arquivo *automato);


void grava_transicoes(char *linha_lida);

void gravacao_do_txt(char *linha_lida, int numero_da_linha, Leitura_do_arquivo *automato);


int leitura_do_txt(char *nome_do_arquivo);





void grava_final();
#endif