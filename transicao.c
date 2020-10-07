#include "transicao.h"

/*Cria a transição
  Entrada: Ponteiro para struct de transição, string com o estado atual da transição, string com
  o caractere lido, string com o estado posterior à transição, string com o retorno da transição
  Retorno: Nenhum
  Pré-condição: Arquivo ter sido lido e dividido
  Pós-condição: Transição é criada
*/
void cria_transicao( Transicao_unitaria *transicao, char *estado_atual,
    char *caractere_lido, char *estado_posterior, char *retorno){
        strcpy(transicao->estado_atual, estado_atual);
        transicao->caractere_lido = caractere_lido[0];
        strcpy(transicao->estado_posterior, estado_posterior);
        strcpy(transicao->retorno, retorno);
    }