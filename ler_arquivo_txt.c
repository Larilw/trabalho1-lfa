#include "ler_arquivo_txt.h"

/*Descrição
  Entrada: 
  Retorno:
  Pré-condição:
  Pós-condição:
*/
void print_matriz(char matriz[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX], int l){
    int i, j;
    for(i=0; i<l; i++){
        for(j=0; j< TAMANHO_MATRIZ_MAX; j++){
            printf("%c", matriz[i][j]);
        }
        printf(",");
    }
    printf("\n");
}

/*Guarda os elementos obtidos em seus tipos na struct automato 
  Entrada: Vetor com os algarismos de entrada, ponteiro para a struct automato, 
  inteiro que representa a posição em linhas, inteiro que representa o número da linha lida
  Retorno: Nenhum
  Pré-condição: Arquivo lido, dividido e processado de forma a sobrar 
  apenas o conteúdo necessário das linhas recebidas
  Pós-condição: Todos as matrizes da struct automato preenchidas com seus respectivos dados
*/
void preenche_matriz(char *algarismo_do_alfabeto, Leitura_do_arquivo *automato, int i, int numero_da_linha){
    int j;
    for(j = 0;j < strlen(algarismo_do_alfabeto); j++){
        if(numero_da_linha == 0){
            automato->alfabeto_entrada[i][j] = algarismo_do_alfabeto[j];
        }else if(numero_da_linha == 1){
            automato->alfabeto_saida[i][j] = algarismo_do_alfabeto[j]; 
        }else if(numero_da_linha == 2){
            automato->estados[i][j] = algarismo_do_alfabeto[j];
        }else automato->estados_finais[i][j] = algarismo_do_alfabeto[j];
    }
    if(numero_da_linha == 0){
        automato->alfabeto_entrada[i][j] = '\0';
    }else if(numero_da_linha == 1){
        automato->alfabeto_saida[i][j] = '\0';
    }else if(numero_da_linha == 2){
        automato->estados[i][j] = '\0';
    }else automato->estados_finais[i][j] = '\0';
}

/*Separa o texto recebido dos valores necessários para as operações futuras
  Entrada: String com a linha lida, inteiro representando o numero da linha, 
  ponteiro que aponta para a struct automato
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido
  Pós-condição: Apenas os valores necessários são mantidos
*/
void separa_valores(char *linha_lida, int numero_da_linha, Leitura_do_arquivo *automato){
    char *aux = strtok(linha_lida, "{");
    int i = 0;
    aux = strtok(NULL, "{");
    aux = strtok(aux, "}");
    aux = strtok(aux, ",");
    while (aux != NULL){
        preenche_matriz(aux, automato, i, numero_da_linha);
        i++;
        aux = strtok(NULL, ",");
    }
    if(numero_da_linha == 0){
        print_matriz(automato->alfabeto_entrada, i);
    }else if(numero_da_linha == 1){
        print_matriz(automato->alfabeto_saida, i);
    }else if(numero_da_linha == 2){
        print_matriz(automato->estados, i);
    }else print_matriz(automato->estados_finais, i);
    
}

/*Descrição
  Entrada: 
  Retorno:
  Pré-condição:
  Pós-condição:
*/
void grava_conjuntos(char *linha_lida,int numero_da_linha, Leitura_do_arquivo *automato){
    separa_valores(linha_lida, numero_da_linha, automato);

}

/*Guarda o estado inicial do automato
  Entrada: String com a linha lida, ponteiro que aponta para a struct automato
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido de acordo com o número da linha 
  Pós-condição: Preenchimento do campo de estado inicial na struct automato
*/
void grava_inicial(char *linha_lida, Leitura_do_arquivo *automato){
    char *aux = strtok(linha_lida, "=");
    aux = strtok(NULL, "=");
    strcpy(automato->estado_inicial, aux);
    printf("%s", automato->estado_inicial);
}

/*Descrição
  Entrada: 
  Retorno:
  Pré-condição:
  Pós-condição:
*/
void grava_transicoes(char *linha_lida){}


/*Classifica as linhas lidas conforme o número da linha, 
chama as funções de gravação para cada caso diferente
  Entrada: String com a linha lida, inteiro representando o número da linha, 
  ponteiro que aponta para a struct automato
  Retorno: Nenhum
  Pré-condição: Arquivo ter sido lido com sucesso
  Pós-condição: O arquivo é dividido para gravação 
*/
void gravacao_do_txt(char *linha_lida, int numero_da_linha, Leitura_do_arquivo *automato){
    if(numero_da_linha == 3) grava_inicial(linha_lida, automato);
    else if(numero_da_linha >= 5) grava_transicoes(linha_lida);
    else grava_conjuntos(linha_lida, numero_da_linha, automato);
    
}

/*Lê o arquivo fornecido pelo usuário linha por linha e exibe 
uma mensagem de erro caso não consiga ler corretamente o arquivo
  Entrada: String com o nome do arquivo
  Retorno: Inteiro que representa sucesso ou não na leitura do arquivo
  Pré-condição: Receber um arquivo
  Pós-condição: O arquivo é lido e processado 
*/
int leitura_do_txt(char *nome_do_arquivo){
    int numero_da_linha;
    Leitura_do_arquivo automato;
    FILE *arquivo_lido;
    char linha_lida[TAMANHO_MAX];
    arquivo_lido = fopen(nome_do_arquivo, "r");
    if(arquivo_lido == NULL){
        printf("Arquivo invalido\n");
        return 1;
    }
    for(numero_da_linha = 0;fgets(linha_lida, TAMANHO_MAX, arquivo_lido) != NULL;numero_da_linha++){
        gravacao_do_txt(linha_lida, numero_da_linha, &automato);
    }

}
