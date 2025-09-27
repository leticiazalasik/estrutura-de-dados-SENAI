#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    char nome[40];
    char bairro[40];
    int pessoas;
    int tem_criancas;
    double renda;
} Cliente;

Cliente* cria_cliente(const char *nome, const char *bairro, int pessoas, int tem_criancas, double renda);
void libera_cliente(Cliente *c);
void imprime_cliente(const Cliente *c);

#endif
