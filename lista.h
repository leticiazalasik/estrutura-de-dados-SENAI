#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include "cliente.h"

typedef struct Lista_ Lista;

Lista* cria_lista();
void insere_lista(Lista* l, void* data);
int get_quantidade(Lista* l);                    
Nodo* get_inicio(Lista* l);                       
void libera_lista(Lista *l);
void imprime_lista(const Lista *l); 

#endif