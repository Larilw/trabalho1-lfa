#include "automato.h"

void printa_automato(Automato automato){
    int i, j;
    printf("alfabeto_entrada={%s}\n", automato.alfabeto_entrada);
    printf("alfabeto_saida={%s}\n", automato.alfabeto_saida);
    printf("estados={");
    for(i=0; i < automato.numero_de_estados; i++){
        printf("%s,", automato.estado[i].nome_do_estado);
    }
    printf("}\n");
    for(i=0; i < automato.numero_de_estados; i++){
        if(automato.estado[i].inicial != 0)printf("inicial=%s\n", automato.estado[i].nome_do_estado);
    }
    printf("finais={");
    for(i=0; i < automato.numero_de_estados; i++){
        if(automato.estado[i].final != 0)printf("%s,", automato.estado[i].nome_do_estado);
    }
    printf("}\n");
    for(i=0; i < automato.numero_de_estados; i++){
        for(j=0; j < automato.estado[i].numero_de_transicoes; j++){
            printf("(%s,%c) = (%s,%s)\n", automato.estado[i].transicoes[j].estado_atual,
             automato.estado[i].transicoes[j].caractere_lido,
              automato.estado[i].transicoes[j].estado_posterior, automato.estado[i].transicoes[j].retorno);
        }
    }
}

int busca_estado(Automato automato, char *nome_do_estado){
    int i;
    for(i=0; i < automato.numero_de_estados; i++){
        if(strcmp(automato.estado[i].nome_do_estado, nome_do_estado)== 0) return i;
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
    automato->numero_de_estados = numero_de_estados;
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
    int i;
    free(automato->alfabeto_entrada);
    free(automato->alfabeto_saida);
    for(i=0; i < automato->numero_de_estados;i++){
        deleta_estado(&automato->estado[i]);
    }
    free(automato->estado);
}