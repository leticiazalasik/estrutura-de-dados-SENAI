#include <stdio.h> 
#include <stdlib.h>
#include "lista.h"
#include "cliente.h"
#include "nodo.h"

typedef struct Lista_ {
    Nodo *inicio;
} Lista;

Lista* cria_lista(){
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    if (nova == NULL) return NULL;
    nova->inicio = NULL;
    return nova;
}

void insere_lista(Lista* l, void* data) {
    if (l == NULL || data == NULL) return;
    
    Nodo* novo_nodo = cria_nodo(data);
    if (novo_nodo == NULL) return;
    
    set_next(novo_nodo,get_inicio(l));
    l->inicio = novo_nodo;
}

int get_quantidade(Lista* l) {
    if (l == NULL) return 0;
    
    int count = 0;
    Nodo* atual = get_inicio(l);
    while (atual != NULL) {
        count++;
        atual = get_next(atual);
    }
    return count;
}

Nodo* get_inicio(const Lista* l) {
    if (l == NULL) return NULL;
    return l->inicio;
}


void libera_lista(Lista *l){
    if (l == NULL) return;
    
    Nodo *atual = get_inicio(l);
    while (atual != NULL) {
        Nodo *proximo = get_next(atual);
        libera_nodo(atual);
        atual = proximo; 
    }
    free(l);
}

void imprime_lista(const Lista *l) {
    if (l == NULL) return;
    
    Nodo *atual = get_inicio(l);
    while (atual != NULL) {
        imprime(get_data(atual));
        atual = get_next(atual); 
    } 
}