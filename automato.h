#ifndef AUTOMATO_H
#define AUTOMATO_H
#include <stdio.h>
#include <stdlib.h>
#include "estado.h"

typedef struct{
    Estado *estado; 
    int numero_de_estados;
    char *alfabeto_entrada;
    int tamanho_alfabeto_entrada;
    char *alfabeto_saida;
    int tamanho_alfabeto_saida;
} Automato;

/*Busca estado de acordo com seu nome
  Entrada: Struct automato, string com o nome do estado
  Retorno: Inteiro que possui a posição do estado ou -1 se não for encontrado
  Pré-condição: Automato preenchido e nome do estado conhecido
  Pós-condição: Estado procurado é encontrado pela posição
*/
int busca_estado(Automato automato, char *nome_do_estado);

/*Busca o estado inicial do automato
  Entrada: Struct do automato
  Retorno: Inteiro que retorna a posição do estado inicial ou -1 se não tiver inicial
  Pré-condição: Struct do automato ter sido preenchida
  Pós-condição: Estado inicial do automato é conhecido
*/
int busca_estado_inicial(Automato automato);

/*Criação da struct do autômato
  Entrada: ponteiro para struct automato, struct de vetor de estados, inteiro que representa o número
  de estados do automato, string com o alfabeto de entrada, inteiro com o tamanho do alfabeto de entrada,
  string com o alfabeto de saída, inteiro com o tamanho do alfabeto de saída
  Retorno: Nenhum
  Pré-condição: O arquivo ter sido lido, sem espaços sobrando e salvo em duas structs de leitura de automato e transição
  Pós-condição: Automato criado
*/
void cria_automato(Automato *automato, Estado estados[], int numero_de_estados, char alfabeto_entrada[][200], int tamanho_alfabeto_entrada,
     char alfabeto_saida[][200], int tamanho_alfabeto_saida);

/*Libera as partes do automato alocadas dinâmicamente
  Entrada: Ponteiro para struct automato
  Retorno: Nenhum
  Pré-condição: Struct automato ter sido preenchida
  Pós-condição: Memória alocada dinâmicamente é liberada
*/
void deleta_automato(Automato *automato);


#endif