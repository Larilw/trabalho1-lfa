#include "transicao.h"

void printa_transicao(Transicao_unitaria t){
    printf("(%s,", t.estado_atual);
    printf("%c)", t.caractere_lido);
    printf(" = (%s,", t.estado_posterior);
    printf("%s)\n", t.retorno);
}

void cria_transicao( Transicao_unitaria *transicao, char *estado_atual,
    char *caractere_lido, char *estado_posterior, char *retorno){
        strcpy(transicao->estado_atual, estado_atual);
        transicao->caractere_lido = caractere_lido[0];
        strcpy(transicao->estado_posterior, estado_posterior);
        strcpy(transicao->retorno, retorno);
    }