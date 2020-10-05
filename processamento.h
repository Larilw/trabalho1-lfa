#ifndef PROCESSAMENTO_H
#define PROCESAMENTO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "automato.h"
#include "estado.h"
#include "transicao.h"

void recebe_palavra();

void processa(Automato automato);

#endif 