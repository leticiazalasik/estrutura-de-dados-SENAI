#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cria_cliente(const char *nome, const char *bairro, int pessoas, int tem_criancas, double renda) {
Cliente *novo = (Cliente*) malloc(sizeof(Cliente));

if (novo == NULL){
    return NULL;
}

strcpy(novo ->nome, nome);
strcpy(novo->bairro, bairro);
novo->pessoas = pessoas; 
novo->tem_criancas = tem_criancas;
novo->renda = renda;

    return novo;
}

void libera_cliente(Cliente *c) {
    free(c);
}

void imprime_cliente(const Cliente *c) {
    printf("Nome: %s\n", c->nome);
    printf("Bairro: %s\n", c->bairro);
    printf("Pessoas na residência: %d\n", c->pessoas);
    printf("Tem crianças menores de cinco anos: %d\n", c->tem_criancas);
    printf("Renda familiar: R$ %.2lf\n", c->renda);

}
