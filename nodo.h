#ifndef NODO_H
#define NODO_H

#include "cliente.h"

typedef struct NODO {
    Cliente *cliente;
    struct NODO *proximo;
} NODO;

Nodo* cria_nodo(Cliente *C);
void libera_nodo(Nodo *n);
void imprime_nodo(const Nodo *n); 

#endif