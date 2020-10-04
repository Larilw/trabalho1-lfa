#include "automato.h"

void cria_automato(Automato *automato, int numero_de_estados, char *alfabeto_entrada, int tamanho_alfabeto_entrada,
     char *alfabeto_saida, int tamanho_alfabeto_saida){
    int i;
    automato->tamanho_alfabeto_entrada = tamanho_alfabeto_entrada;
    automato->tamanho_alfabeto_saida = tamanho_alfabeto_saida;
    for(i = 0; i < tamanho_alfabeto_entrada; i++){
        automato->alfabeto_entrada[i] = malloc(sizeof(char));
    }
    for(i = 0; i < tamanho_alfabeto_saida; i++){
        automato->alfabeto_saida[i] = malloc(sizeof(char));
    }
    automato->estado = malloc(sizeof(Estado) * numero_de_estados);
}

void deleta_automato(Automato *automato, int tamanho_alfabeto_entrada, int tamanho_alfabeto_saida){
    int i;
    for(i = 0; i < tamanho_alfabeto_entrada; i++){
        free(automato->alfabeto_entrada[i]);
    }
    for(i=0; i < tamanho_alfabeto_saida; i++){
        free(automato->alfabeto_saida[i]);
    }
    free(automato->estado);
}