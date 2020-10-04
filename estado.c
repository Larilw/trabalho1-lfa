#include "estado.h"

void cria_estado(Estado *estado, char *nome_do_estado, int final, int inicial,
     int numero_de_transicoes, Transicao_unitaria transicoes[]){
    int i;
    strcpy(estado->nome_do_estado, nome_do_estado);
    estado->final = final;
    estado->inicial = inicial;
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