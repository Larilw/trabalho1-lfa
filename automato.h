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

void cria_automato(Automato *automato, int numero_de_estados, char *alfabeto_entrada, int tamanho_alfabeto_entrada,
     char *alfabeto_saida, int tamanho_alfabeto_saida);

void deleta_automato(Automato *automato);

#endif