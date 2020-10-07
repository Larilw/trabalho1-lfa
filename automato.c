#include "automato.h"

/*Busca estado de acordo com seu nome
  Entrada: Struct automato, string com o nome do estado
  Retorno: Inteiro que possui a posição do estado ou -1 se não for encontrado
  Pré-condição: Automato preenchido e nome do estado conhecido
  Pós-condição: Estado procurado é encontrado pela posição
*/
int busca_estado(Automato automato, char *nome_do_estado){
    int i;
    for(i=0; i < automato.numero_de_estados; i++){
        if(strcmp(automato.estado[i].nome_do_estado, nome_do_estado)== 0) return i;
    }
    return -1;
}

/*Busca o estado inicial do automato
  Entrada: Struct do automato
  Retorno: Inteiro que retorna a posição do estado inicial ou -1 se não tiver inicial
  Pré-condição: Struct do automato ter sido preenchida
  Pós-condição: Estado inicial do automato é conhecido
*/
int busca_estado_inicial(Automato automato){
    int i;
    for(i=0; i < automato.numero_de_estados; i++){
        if(automato.estado[i].inicial == 1) return i;
    }
    return -1;
}

/*Criação da struct do autômato
  Entrada: ponteiro para struct automato, struct de vetor de estados, inteiro que representa o número
  de estados do automato, string com o alfabeto de entrada, inteiro com o tamanho do alfabeto de entrada,
  string com o alfabeto de saída, inteiro com o tamanho do alfabeto de saída
  Retorno: Nenhum
  Pré-condição: O arquivo ter sido lido, sem espaços sobrando e salvo em duas structs de leitura de automato e transição
  Pós-condição: Automato criado
*/
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

/*Libera as partes do automato alocadas dinâmicamente
  Entrada: Ponteiro para struct automato
  Retorno: Nenhum
  Pré-condição: Struct automato ter sido preenchida
  Pós-condição: Memória alocada dinâmicamente é liberada
*/
void deleta_automato(Automato *automato){
    int i;
    free(automato->alfabeto_entrada);
    free(automato->alfabeto_saida);
    for(i=0; i < automato->numero_de_estados;i++){
        deleta_estado(&automato->estado[i]);
    }
    free(automato->estado);
}