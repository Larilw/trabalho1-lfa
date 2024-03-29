#include "processamento.h"

/*Lê a palavra digitada pelo usuário
  Entrada: String da palavra
  Retorno: Nenhum
  Pré-condição: Usuário escolher no processamento testar palavra
  Pós-condição: A palavra é lida
*/
void recebe_palavra(char *palavra){
    printf("Digite a palavra a ser testada:\n");
    fgets(palavra, 200, stdin);
}

/*Imprime a palavra
  Entrada: String com a palavra, inteiro que representa a posição do caractere na palavra, inteiro
  que representa o tamanho da palavra de saída
  Retorno: Nenhum
  Pré-condição: Palavra ter sido lida
  Pós-condição: Palavra é impressa na tela
*/
void print_da_palavra(char *palavra, int posicao, int tamanho_saida){
    int i;
    strtok(palavra, "\n");
    for(i = posicao; i < (strlen(palavra)); i++){
        printf("%c", palavra[i]);
    }
    for(i=0; i < tamanho_saida+posicao; i++){
        printf(" ");
    }
}

/*Processa o automato e as palavras e checa as regras de aceitação e rejeição
  Entrada: Struct do automato
  Retorno: Nenhum
  Pré-condição: Arquivo lido, sem espaços sobrando, dividido e salvo na struct do automato
  Pós-condição: Automato processado de acordo com a vontade do usuário e é impresso na tela o resultado
  das operações
*/
void processa(Automato automato){
    int i = 0, posicao_do_inicial, posicao_da_transicao, posicao_do_estado, rejeitada = 0, tamanho_saida;
    char palavra[200], palavra_saida[200], caractere_lido, saida_anterior[200], palavra_saida_aux[200];
    recebe_palavra(palavra);
    tamanho_saida = strlen(palavra)-5;
    posicao_do_inicial = busca_estado_inicial(automato);
    strcpy(palavra_saida, "");
    if(posicao_do_inicial >= 0){ 
        posicao_da_transicao = busca_transicao(automato.estado[posicao_do_inicial], palavra[0]);
        printf("[%s]", automato.estado[posicao_do_inicial].nome_do_estado);
        print_da_palavra(palavra, i, tamanho_saida);
        posicao_do_estado = posicao_do_inicial;
        strcpy(saida_anterior, automato.estado[posicao_do_inicial].transicoes[posicao_da_transicao].retorno);
        printf("\n");
        if(posicao_da_transicao != -1){
            for(i=1; i <= (strlen(palavra)); i++){
                posicao_do_estado = busca_estado(automato, 
                     automato.estado[posicao_do_estado].transicoes[posicao_da_transicao].estado_posterior);
                if(posicao_da_transicao != -1){
                    printf("[%s]", automato.estado[posicao_do_estado].nome_do_estado);
                    print_da_palavra(palavra, i, tamanho_saida);
                    posicao_da_transicao = busca_transicao(automato.estado[posicao_do_estado], palavra[i]);
                    printf("saida:%s\n", saida_anterior);
                    strcat(palavra_saida, saida_anterior);
                    strcpy(saida_anterior, automato.estado[posicao_do_estado].transicoes[posicao_da_transicao].retorno);
                }
                else{
                    rejeitada = 1;
                    break;
                }
                
            }
            if(automato.estado[posicao_do_estado].final != 0) printf("ACEITA\n");
            else rejeitada = 1;

        }
        else if(rejeitada == 1) printf("REJEITA\n");
    }
    if(rejeitada == 1) printf("REJEITA\n");
    printf("palavra de saida: ");
    for(i=0; i < strlen(palavra_saida); i++){
        if(palavra_saida[i] != '@') printf("%c", palavra_saida[i]);
    }
    printf("\n");
    strcpy(palavra, "");
    strcpy(palavra_saida, "");
}