#include <stdio.h>
#include "ler_arquivo_txt.h"
#include "transicao.h"
#include "automato.h"
#include "processamento.h"

/*Recebe as entradas do usuário e chama as funções de acordo com cada entrada
  Entrada: Nenhuma
  Retorno: Inteiro que representa se houve erros de execução ou não
  Pré-condição: Nenhuma
  Pós-condição: Arquivo é lido e processado
*/
int main(){
    int i = 0, automato_carregado = 0;
    char caminho_arquivo[1000];
    Automato automato;
    printf("Digite 1 para carregar o automato, 2 para testar palavra e 3 para finalizar\n");
    scanf("%d%*c", &i);
    while(i != 3){
        if(i == 1){
            printf("Digite o caminho completo do arquivo\n");
            fgets(caminho_arquivo, 1000, stdin);
            strtok(caminho_arquivo, "\n");
            automato_carregado = leitura_do_txt(caminho_arquivo, &automato);
            
            
        }
        else if(i == 2){
            if(automato_carregado != 1) processa(automato);
            else printf("Nao ha automato carregado\n");
        }
        printf("Digite 1 para carregar o automato, 2 para testar palavra e 3 para finalizar\n");
        scanf("%d%*c", &i);
    }
    if(automato_carregado != 1) deleta_automato(&automato);
    return 0;
}