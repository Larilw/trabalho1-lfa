#include <stdio.h>
#include "ler_arquivo_txt.h"
#include "transicao.h"

int main(){
    Transicao_unitaria t;
    Transicao transicao;
    leitura_do_txt("teste.txt");
    cria_transicao(&t, transicao.estado_anterior, transicao.entrada, transicao.estado_posterior, transicao.saida);
    printa_transicao(t);
    return 0;
}