#include <stdio.h> 
#include <stdlib.h>
#include "lista.h"
#include "cliente.h"

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
    
    novo_nodo->proximo = l->inicio;
    l->inicio = novo_nodo;
}

int get_quantidade(Lista* l) {
    if (l == NULL) return 0;
    
    int count = 0;
    Nodo* atual = l->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

Nodo* get_inicio(Lista* l) {
    if (l == NULL) return NULL;
    return l->inicio;
}

void libera_lista(Lista *l){
    if (l == NULL) return;
    
    Nodo *atual = l->inicio;
    while (atual != NULL) {
        Nodo *proximo = atual->proximo;
        libera_nodo(atual);
        atual = proximo; 
    }
    free(l);
}

void imprime_lista(const Lista *l) {
    if (l == NULL) return;
    
    Nodo *atual = l->inicio;
    while (atual != NULL) {
        imprime(get_data(atual));
        atual = atual->proximo; 
    } 
}