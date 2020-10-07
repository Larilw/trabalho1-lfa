#ifndef PROCESSAMENTO_H
#define PROCESAMENTO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "automato.h"
#include "estado.h"
#include "transicao.h"


/*Lê a palavra digitada pelo usuário
  Entrada: String da palavra
  Retorno: Nenhum
  Pré-condição: Usuário escolher no processamento testar palavra
  Pós-condição: A palavra é lida
*/
void recebe_palavra();

/*Processa o automato e as palavras e checa as regras de aceitação e rejeição
  Entrada: Struct do automato
  Retorno: Nenhum
  Pré-condição: Arquivo lido, sem espaços sobrando, dividido e salvo na struct do automato
  Pós-condição: Automato processado de acordo com a vontade do usuário e é impresso na tela o resultado
  das operações
*/
void processa(Automato automato);

#endif 