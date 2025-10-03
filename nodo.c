#include <stdio.h> 
#include <stdlib.h>
#include "nodo.h"
#include "cliente.h"

typedef struct Nodo_ {
    Cliente *cliente;
    struct Nodo_ *proximo;
} Nodo;

Nodo* cria_nodo(Cliente *c){
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) return NULL;
    
    novo->cliente = c;
    novo->proximo = NULL; 
    return novo;
}

void libera_nodo(Nodo *n){
    if (n == NULL) return;
    free(n);
}

void imprime_nodo(const Nodo *n) {
    if (n != NULL && n->cliente != NULL){
        imprime(n->cliente);
    }
}

void* get_data(Nodo* n) {
    if (n == NULL) return NULL;
    return n->cliente;
}

Nodo* get_next(Nodo* n) {
    if (n == NULL) return NULL;
    return n->proximo;
}

void set_next(Nodo* n,Nodo* next){
    n->proximo = next;
}