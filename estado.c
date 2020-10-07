#include "estado.h"

/*Carrega o vetor de transições
  Entrada: Ponteiro para struct de estado, inteiro que representa o número de transições, struct de 
  vetor de transições
  Retorno: Nenhum
  Pré-condição: Transições terem sido criadas
  Pós-condição: Transições são crarregadas
*/
void carrega_transicao(Estado *estado, int numero_de_transicoes, Transicao_unitaria transicoes[]){
    int i;
    estado->numero_de_transicoes = numero_de_transicoes;
    estado->transicoes = malloc(sizeof(Transicao_unitaria) * numero_de_transicoes);
    for(i = 0; i < numero_de_transicoes; i++){
        estado->transicoes[i] = transicoes[i];
    }
}

/*Busca a transição de acordo com as transições do estado e o caractere de entrada
  Entrada: Struct de estado, caractere lido
  Retorno: Inteiro que representa a posição da transição ou -1 se não existir transição de acordo 
  com a entrada e o estado
  Pré-condição: Estado preenchido e possuir o caractere lido
  Pós-condição: Posição da transição é conhecida
*/
int busca_transicao(Estado estado, char caractere_lido){
    int i;
    for(i = 0; i < estado.numero_de_transicoes; i++){
        if(estado.transicoes[i].caractere_lido == caractere_lido) return i;
    }
    return -1;
}

/*Libera as partes alocadas dinâmicamentes na struct de estado
  Entrada: Ponteiro para a struct de estado
  Retorno: Nenhum
  Pré-condição: Estado ter sido peenchido
  Pós-condição: Memória é liberada
*/
void deleta_estado(Estado *estado){
    free(estado->transicoes); 
}