#include "estado.h"

void carrega_transicao(Estado *estado, int numero_de_transicoes, Transicao_unitaria transicoes[]){
    int i;
    estado->numero_de_transicoes = numero_de_transicoes;
    estado->transicoes = malloc(sizeof(Transicao_unitaria) * numero_de_transicoes);
    for(i = 0; i < numero_de_transicoes; i++){
        estado->transicoes[i] = transicoes[i];
    }
}

int busca_transicao(Estado estado, char caractere_lido){
    int i;
    for(i = 0; i < estado.numero_de_transicoes; i++){
        if(estado.transicoes->caractere_lido == caractere_lido) return i;
    }
    return -1;
}

void deleta_estado(Estado *estado){
    free(estado->transicoes); 
}