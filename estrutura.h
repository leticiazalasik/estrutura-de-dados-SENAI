#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "cliente.h"
#include "lista.h"

#define HASH_SIZE 100

typedef struct Estrutura {
    Lista *hash_nome[HASH_SIZE];        
    Lista *hash_bairro[HASH_SIZE];      
    Lista *lista_pessoas[6];            
    Lista *lista_criancas[2];           
    Lista *lista_renda[4];              
} Estrutura;

Estrutura* cria_estrutura();
void insere_cliente(Estrutura* e, int criterio, Cliente* cliente);
Lista* recupera_cliente(Estrutura* e, int criterio, int complemento, const char* busca);
void libera_estrutura(Estrutura *e);
void imprime_estrutura(const Estrutura *e);

unsigned int hash_string(const char* str);
int obter_faixa_renda(double renda);

#endif