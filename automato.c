#include "automato.h"

int busca_estado(Automato automato, char *nome_do_estado){
    int i;
    for(i=0; i < automato.numero_de_estados; i++){
        if(strcmp(automato.estado->nome_do_estado, nome_do_estado)== 0) return i;
    }
    return -1;
}

int busca_estado_inicial(Automato automato){
    int i;
    for(i=0; i < automato.numero_de_estados; i++){
        if(automato.estado[i].inicial == 1) return i;
    }
    return -1;
}

void cria_automato(Automato *automato, Estado estados[], int numero_de_estados, char alfabeto_entrada[][200], int tamanho_alfabeto_entrada,
     char alfabeto_saida[][200], int tamanho_alfabeto_saida){
    int i;
    automato->tamanho_alfabeto_entrada = tamanho_alfabeto_entrada;
    automato->tamanho_alfabeto_saida = tamanho_alfabeto_saida;
    automato->alfabeto_entrada = malloc(sizeof(char)*tamanho_alfabeto_entrada);
    for(i = 0; i < tamanho_alfabeto_entrada; i++){
        automato->alfabeto_entrada[i] = alfabeto_entrada[i][0];
    }
    automato->alfabeto_saida = malloc(sizeof(char)*tamanho_alfabeto_saida);
    for(i = 0; i < tamanho_alfabeto_saida; i++){
        automato->alfabeto_saida[i] = alfabeto_saida[i][0];
    }
    automato->estado = malloc(sizeof(Estado) * numero_de_estados);
    for(i=0; i < numero_de_estados; i++){
        automato->estado[i] = estados[i];
    }
}

void deleta_automato(Automato *automato){
    free(automato->alfabeto_entrada);
    free(automato->alfabeto_saida);
    free(automato->estado);
}