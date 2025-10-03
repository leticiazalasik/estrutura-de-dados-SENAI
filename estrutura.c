#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

typedef struct Estrutura_ {
    Lista *hash_nome[HASH_SIZE];        
    Lista *hash_bairro[HASH_SIZE];      
    Lista *lista_pessoas[6];            
    Lista *lista_criancas[2];           
    Lista *lista_renda[4];              
} Estrutura;

Estrutura* cria_estrutura() {
    Estrutura *nova = (Estrutura*) malloc(sizeof(Estrutura));
    if (nova == NULL) return NULL;
    
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        nova->hash_nome[i] = NULL;
        nova->hash_bairro[i] = NULL;
    }
    
    for (i = 0; i < 6; i++) {
        nova->lista_pessoas[i] = NULL;
    }
    for (i = 0; i < 2; i++) {
        nova->lista_criancas[i] = NULL;
    }
    for (i = 0; i < 4; i++) {
        nova->lista_renda[i] = NULL;
    }
    
    return nova;
}

unsigned int hash_string(const char* str) {
    if (str == NULL) return 0;
    
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31 + *str) % HASH_SIZE;
        str++;
    }
    return hash;
}

int obter_faixa_renda(double renda) {
    if (renda <= 2000.0) return 0;
    if (renda <= 3000.0) return 1;
    if (renda <= 5000.0) return 2;
    return 3;
}

void insere_cliente(Estrutura* e, int criterio, Cliente* cliente) {
    if (e == NULL || cliente == NULL) return;
    
    switch (criterio) {
        case 1: {
            unsigned int indice = hash_string(get_nome(cliente));
            if (e->hash_nome[indice] == NULL) {
                e->hash_nome[indice] = cria_lista();
            }
            insere_lista(e->hash_nome[indice], cliente);
            incrementa_ref(cliente);
            break;
        }
        case 2: {
            unsigned int indice = hash_string(get_bairro(cliente));
            if (e->hash_bairro[indice] == NULL) {
                e->hash_bairro[indice] = cria_lista();
            }
            insere_lista(e->hash_bairro[indice], cliente);
            incrementa_ref(cliente);
            break;
        }
        case 3: {
            int pessoas = get_pessoas(cliente);
            if (pessoas >= 5) pessoas = 5;
            if (pessoas >= 1 && pessoas <= 5) {
                if (e->lista_pessoas[pessoas] == NULL) {
                    e->lista_pessoas[pessoas] = cria_lista();
                }
                insere_lista(e->lista_pessoas[pessoas], cliente);
                incrementa_ref(cliente);
            }
            break;
        }
        case 4: {
            int tem_criancas = get_criancas(cliente);
            int indice = tem_criancas ? 1 : 0;
            if (e->lista_criancas[indice] == NULL) {
                e->lista_criancas[indice] = cria_lista();
            }
            insere_lista(e->lista_criancas[indice], cliente);
            incrementa_ref(cliente);
            break;
        }
        case 5: {
            int faixa = obter_faixa_renda(get_renda(cliente));
            if (e->lista_renda[faixa] == NULL) {
                e->lista_renda[faixa] = cria_lista();
            }
            insere_lista(e->lista_renda[faixa], cliente);
            incrementa_ref(cliente);
            break;
        }
    }
}

Lista* recupera_cliente(Estrutura* e, int criterio, int complemento, const char* busca) {
    if (e == NULL) return NULL;
    
    Lista* resultado = cria_lista();
    if (resultado == NULL) return NULL;
    
    switch (criterio) {
        case 1: {
            if (busca == NULL) break;
            unsigned int indice = hash_string(busca);
            if (e->hash_nome[indice] != NULL) {
                Nodo* cursor = get_inicio(e->hash_nome[indice]);
                while (cursor != NULL) {
                    Cliente* cliente = (Cliente*)get_data(cursor);
                    if (cliente != NULL && strcmp(get_nome(cliente), busca) == 0) {
                        insere_lista(resultado, cliente);
                    }
                    cursor = get_next(cursor);
                }
            }
            break;
        }
        case 2: {
            if (busca == NULL) break;
            unsigned int indice = hash_string(busca);
            if (e->hash_bairro[indice] != NULL) {
                Nodo* cursor = get_inicio(e->hash_bairro[indice]);
                while (cursor != NULL) {
                    Cliente* cliente = (Cliente*)get_data(cursor);
                    if (cliente != NULL && strcmp(get_bairro(cliente), busca) == 0) {
                        insere_lista(resultado, cliente);
                    }
                    cursor = get_next(cursor);
                }
            }
            break;
        }
        case 3: {
            if (complemento >= 1 && complemento <= 5) {
                if (e->lista_pessoas[complemento] != NULL) {
                    Nodo* cursor = get_inicio(e->lista_pessoas[complemento]);
                    while (cursor != NULL) {
                        Cliente* cliente = (Cliente*)get_data(cursor);
                        if (cliente != NULL) {
                            insere_lista(resultado, cliente);
                        }
                        cursor = get_next(cursor);
                    }
                }
            }
            break;
        }
        case 4: {
            if (complemento == 0 || complemento == 1) {
                if (e->lista_criancas[complemento] != NULL) {
                    Nodo* cursor = get_inicio(e->lista_criancas[complemento]);
                    while (cursor != NULL) {
                        Cliente* cliente = (Cliente*)get_data(cursor);
                        if (cliente != NULL) {
                            insere_lista(resultado, cliente);
                        }
                        cursor = get_next(cursor);
                    }
                }
            }
            break;
        }
        case 5: {
            if (complemento >= 1 && complemento <= 4) {
                int faixa = complemento - 1;
                if (e->lista_renda[faixa] != NULL) {
                    Nodo* cursor = get_inicio(e->lista_renda[faixa]);
                    while (cursor != NULL) {
                        Cliente* cliente = (Cliente*)get_data(cursor);
                        if (cliente != NULL) {
                            insere_lista(resultado, cliente);
                        }
                        cursor = get_next(cursor);
                    }
                }
            }
            break;
        }
    }
    
    return resultado;
}

void libera_estrutura(Estrutura *e) {
    if (e == NULL) return;
    
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        if (e->hash_nome[i] != NULL) {
            libera_lista(e->hash_nome[i]);
        }
        if (e->hash_bairro[i] != NULL) {
            libera_lista(e->hash_bairro[i]);
        }
    }
    
    for (i = 0; i < 6; i++) {
        if (e->lista_pessoas[i] != NULL) {
            libera_lista(e->lista_pessoas[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        if (e->lista_criancas[i] != NULL) {
            libera_lista(e->lista_criancas[i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (e->lista_renda[i] != NULL) {
            libera_lista(e->lista_renda[i]);
        }
    }
    
    free(e);
}

void imprime_estrutura(const Estrutura *e) {
    if (e == NULL) return;
    printf("Estrutura implementada com hash tables.\n");
}