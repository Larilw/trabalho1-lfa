#include "ler_arquivo_txt.h"

/*Remove espaços sobrando no automato, menos nas transições
  Entrada: string com a linha lida, string com a linha sem espaços
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido por linhas
  Pós-condição: Linhas sem espaços sobrando
*/
void remove_espacos(char *linha_lida, char *linha_sem_espacos){
    int i, j = 0;
    for(i=0; i < strlen(linha_lida); i++){
        if(linha_lida[i] != ' '){
            linha_sem_espacos[j] = linha_lida[i];
            j++;
        }
    }
    linha_sem_espacos[j] = 0;
}

/*Remove espaços sobrando nas transições
  Entrada: string com a linha lida, string com a linha sem espaços
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido por linhas
  Pós-condição: Linhas sem espaços sobrando
*/
void remove_espacos_transicao(char *linha_lida, char *linha_sem_espacos){
    int i, j = 0;
    for(i=0; i < strlen(linha_lida); i++){
        if(linha_lida[i] != ' '){
            linha_sem_espacos[j] = linha_lida[i];
            j++;
        }
        else if(i > 0){
            if(linha_lida[i-1] == ')'){
                linha_sem_espacos[j] = linha_lida[i];
                j++;
            }
            else if(linha_lida[i-1] == '='){
                linha_sem_espacos[j] = linha_lida[i];
                j++;
            }
        }
    }
    linha_sem_espacos[j] = 0;
}

/*Calcula a quantidade de transições que cada estado possui
  Entrada: struct de transição, string com o nome do estado, inteiro que representa o número de transições
  Retorno: Inteiro com a quantidade de transições de cada estado
  Pré-condição: Automato lido e separado em partes
  Pós-condição: Quantidde de transições por estado é conhecida
*/
int quantidade_transicoes_por_estado(Transicao *transicao, char *nome_do_estado, int numero_de_transicoes){
    int i, quantidade = 0;
    for(i=0; i < numero_de_transicoes; i++){
        if(strcmp(transicao[i].estado_anterior, nome_do_estado) == 0) quantidade++;
    }
    return quantidade;
}

/*Transfere os dados das duas structs de automato e transição para outras structs de forma a separar
os dados para uso futuro
  Entrada: struct do automato de leitura, struct transição de leitura, struct do automato final,
  inteiro que representa o número de estados que o automato possui, inteiro que representa o número de
  estados finais que o automato possui, inteiro que representa o numero de transições que o automato
  possui
  Retorno: Nenhum
  Pré-condição: Structs de leitura preenchidas previamente
  Pós-condição: Divide-se os dados de forma hierárquica dentro do automato novo criado
*/
void carrega_automato(Leitura_do_arquivo automato_lido, Transicao *transicao_lida, 
     Automato *automato, int numero_de_estados, int tamanho_alfabeto_entrada,
      int tamanho_alfabeto_saida, int numero_de_estados_finais, int numero_de_transicoes){
    int i, j, k = 0, numero_de_transicoes_por_estado;
    char estado_atual[300];
    Estado estados[numero_de_estados];
    for(i=0; i < numero_de_estados; i++){
        strcpy(estados[i].nome_do_estado, automato_lido.estados[i]);
    }
    cria_automato(automato, estados , numero_de_estados, automato_lido.alfabeto_entrada,
     tamanho_alfabeto_entrada, automato_lido.alfabeto_saida, tamanho_alfabeto_saida);
    for(i=0; i < numero_de_estados; i++, k = 0){
        strcpy(estado_atual, automato->estado[i].nome_do_estado);
        if(strcmp(automato_lido.estado_inicial, estado_atual)== 0) automato->estado[i].inicial = 1;
        for(j=0; j < numero_de_estados_finais; j++){
            if(strcmp(estado_atual, automato_lido.estados_finais[j]) == 0) automato->estado[i].final = 1;
        }
        numero_de_transicoes_por_estado = quantidade_transicoes_por_estado(transicao_lida, estado_atual, numero_de_transicoes);
        Transicao_unitaria transicoes[numero_de_transicoes_por_estado];
        for(j=0; j < numero_de_transicoes; j++){
            if(strcmp(estado_atual, transicao_lida[j].estado_anterior) == 0){
                cria_transicao(&transicoes[k], estado_atual, transicao_lida[j].entrada,
                 transicao_lida[j].estado_posterior, transicao_lida[j].saida);
                 k++;
            }
        }
        carrega_transicao(&automato->estado[i], numero_de_transicoes_por_estado, transicoes);
    }
    
}

/*Guarda os elementos de transição na struct de transição
  Entrada: string com o nome do estado atual na transição, string com a entrada recebida na transição,
  string com o estado posterior à transição, string com a saída da transição, struct de transição,
  inteiro que define onde guradar os elementos
  Retorno: Nenhum
  Pré-condição: Arquivo lido, dividido por linhas e processado de forma a possuir apenas os conteúdos
  que devem ser utilizados
  Pós-condição: Struct de transição preenchida
*/
void preenche_vetor(char *estado1, char *entrada, char *estado2, char *saida, Transicao transicao[], int i){
    int t;
    strcpy(transicao[i].estado_anterior, estado1);
    strcpy(transicao[i].estado_posterior, estado2);
    strcpy(transicao[i].entrada, entrada);
    strcpy(transicao[i].saida, saida);
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
void separa_valores(char *linha_lida, int numero_da_linha, Leitura_do_arquivo *automato,
        int *tamanho_alfabeto_entrada, int *tamanho_alfabeto_saida, int *numero_de_estados, int *numero_de_estados_finais){
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
        *tamanho_alfabeto_entrada = i;
    }else if(numero_da_linha == 1){
        *tamanho_alfabeto_saida = i;
    }else if(numero_da_linha == 2){
        *numero_de_estados = i;
    }else{
        *numero_de_estados_finais = i;
    }
    
}

/*Separa o texto recebido dos valores necessários das transições
  Entrada: String com a linha lida, struct de transição,
  inteiro que representa o numero em que se inicia o preenchimento da struct
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido de acordo com a linha
  Pós-condição: Separação das partes que serão utilizadas posteriormente
*/
void separa_transicoes(char *linha_lida, Transicao transicao[], int i){
    char *aux = strtok(linha_lida, "=");
    char *aux2, *aux3, *aux4;
    aux2 = aux;
    aux = strtok(NULL, "=");
    aux = strtok(aux, "=");
    aux2 = strtok(aux2, ")");
    aux2 = strtok(aux2, "(");
    aux = strtok(aux, "(");
    aux = strtok(NULL, "(");
    aux = strtok(aux, ")");
    aux3 = strtok(aux, ",");
    aux4 = strtok(NULL, ",");
    aux = strtok(aux2, ",");
    aux2 = strtok(NULL, ",");
    /*aux representa o estado atual de uma transição, aux2 representa a entrada, aux3 representa
    o estado posterior à transição e aux4 representa a saída dessa transição*/
    preenche_vetor(aux, aux2, aux3, aux4, transicao, i);
}


/*Guarda o estado inicial do automato
  Entrada: String com a linha lida, ponteiro que aponta para a struct automato
  Retorno: Nenhum
  Pré-condição: Arquivo lido e dividido de acordo com o número da linha 
  Pós-condição: Preenchimento do campo de estado inicial na struct de leitura do automato
*/
void grava_inicial(char *linha_lida, Leitura_do_arquivo *automato){
    char *aux = strtok(linha_lida, "=");
    aux = strtok(NULL, "=");
    strtok(aux, "\n");
    strcpy(automato->estado_inicial, aux);
}


/*Classifica as linhas lidas conforme o número da linha, 
chama as funções de gravação para cada caso diferente
  Entrada: String com a linha lida, inteiro representando o número da linha, 
  ponteiro que aponta para a struct de leitura do automato
  Retorno: Nenhum
  Pré-condição: Arquivo ter sido lido com sucesso
  Pós-condição: São retirados os espaços sobrando e o arquivo é dividido para gravação
*/
void gravacao_do_txt(char *linha_lida, int numero_da_linha, Leitura_do_arquivo *automato,
        Transicao transicao[],int *tamanho_alfabeto_entrada, int *tamanho_alfabeto_saida,
        int *numero_de_estados, int *numero_de_estados_finais, int *numero_de_transicoes){
    char linha_formatada[strlen(linha_lida)];
    if(numero_da_linha == 3){
        remove_espacos(linha_lida, linha_formatada);
        grava_inicial(linha_formatada, automato);
    }
    else if(numero_da_linha >= 5){
        remove_espacos_transicao(linha_lida, linha_formatada);
        separa_transicoes(linha_formatada, transicao, numero_da_linha-5);
        (*numero_de_transicoes)++;
    }else{
        remove_espacos(linha_lida, linha_formatada);
        separa_valores(linha_formatada, numero_da_linha, automato, tamanho_alfabeto_entrada, tamanho_alfabeto_saida, numero_de_estados, numero_de_estados_finais);
    }
}

/*Lê o arquivo fornecido pelo usuário linha por linha e exibe 
uma mensagem de erro caso não consiga ler corretamente o arquivo
  Entrada: String com o nome do arquivo
  Retorno: Inteiro que representa sucesso ou não na leitura do arquivo
  Pré-condição: Receber um arquivo
  Pós-condição: O arquivo é lido e processado 
*/
int leitura_do_txt(char *nome_do_arquivo, Automato *automato_preenchido){
    int numero_da_linha, tamanho_alfabeto_entrada = 0, tamanho_alfabeto_saida = 0,
        numero_de_estados = 0, numero_de_estados_finais = 0, numero_de_transicoes = 0;
    Leitura_do_arquivo automato;
    Transicao transicao[TAMANHO_MAX];
    FILE *arquivo_lido;
    char linha_lida[TAMANHO_MAX];
    arquivo_lido = fopen(nome_do_arquivo, "r");
    if(arquivo_lido == NULL){
        printf("Arquivo invalido\n");
        return 1;
    }
    for(numero_da_linha = 0;fgets(linha_lida, TAMANHO_MAX, arquivo_lido) != NULL;numero_da_linha++){
        gravacao_do_txt(linha_lida, numero_da_linha, &automato, transicao, &tamanho_alfabeto_entrada,
        &tamanho_alfabeto_saida, &numero_de_estados, &numero_de_estados_finais, &numero_de_transicoes);
    }
    printf("Arquivo carregado com sucesso\n");
    carrega_automato( automato, transicao, automato_preenchido, numero_de_estados,
     tamanho_alfabeto_entrada, tamanho_alfabeto_saida, numero_de_estados_finais, numero_de_transicoes);

}
