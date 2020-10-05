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

int busca_estado(Automato automato, char *nome_do_estado);

int busca_estado_inicial(Automato automato);

void cria_automato(Automato *automato, Estado estados[], int numero_de_estados, char *alfabeto_entrada, int tamanho_alfabeto_entrada,
     char *alfabeto_saida, int tamanho_alfabeto_saida);

void deleta_automato(Automato *automato);


#endif