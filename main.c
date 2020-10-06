#include <stdio.h>
#include "ler_arquivo_txt.h"
#include "transicao.h"
#include "automato.h"
#include "processamento.h"

int main(){
    Automato automato;
    leitura_do_txt("teste.txt", &automato);
    processa(automato);
    deleta_automato(&automato);
    return 0;
}