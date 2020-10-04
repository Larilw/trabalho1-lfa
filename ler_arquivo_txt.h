#ifndef LER_ARQUIVO_TXT_H
#define LER_ARQUIVO_TXT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

}Leitura_do_arquivo;

/*Guarda o estado inicial do automato
  Entrada: String com a linha lida, ponteiro que aponta para a struct automato
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido de acordo com o número da linha 
  Pós-condição: Preenchimento do campo de estado inicial na struct automato
*/
void grava_inicial(char *linha_lida, Leitura_do_arquivo *automato);

void grava_transicoes(char *linha_lida, Leitura_do_arquivo *automato, int i);


/*Classifica as linhas lidas conforme o número da linha, 
chama as funções de gravação para cada caso diferente
  Entrada: String com a linha lida, inteiro representando o número da linha, 
  ponteiro que aponta para a struct automato
  Retorno: Nenhum
  Pré-condição: Arquivo ter sido lido com sucesso
  Pós-condição: O arquivo é dividido para gravação 
*/
void gravacao_do_txt(char *linha_lida, int numero_da_linha, Leitura_do_arquivo *automato,
        Transicao transicao[],int *tamanho_alfabeto_entrada, int *tamanho_alfabeto_saida,
        int *numero_de_estados, int *numero_de_estados_finais, int *numero_de_transicoes);

/*Lê o arquivo fornecido pelo usuário linha por linha e exibe 
uma mensagem de erro caso não consiga ler corretamente o arquivo
  Entrada: String com o nome do arquivo
  Retorno: Inteiro que representa sucesso ou não na leitura do arquivo
  Pré-condição: Receber um arquivo
  Pós-condição: O arquivo é lido e processado 
*/
int leitura_do_txt(char *nome_do_arquivo, Transicao *trans);





void grava_final();
#endif