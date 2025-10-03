#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

typedef struct Cliente_{     
    char nome[40];     
    char bairro[40];     
    int pessoas;     
    int tem_criancas;     
    double renda; 
    int ref_count;
} Cliente; 


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
    novo->ref_count = 0;
    
    return novo;
}

void libera_cliente(Cliente *c) {
    free(c);
}

const char* get_nome(const Cliente* c) {
    return c->nome;
}

const char* get_bairro(const Cliente* c) {
    return c->bairro;
}

int get_pessoas(const Cliente* c) {
    return c->pessoas;
}

int get_criancas(const Cliente* c) {
    return c->tem_criancas;
}

double get_renda(const Cliente* c) {
    return c->renda;
}

void incrementa_ref(Cliente *c) {
    if (c != NULL) c->ref_count++;
}

void decrementa_ref(Cliente *c) {
    if (c != NULL) {
        c->ref_count--;
        if (c->ref_count <= 0) {
            libera_cliente(c);
        }
    }
}