#ifndef CLIENTE_H 
#define CLIENTE_H  

typedef struct Cliente_ Cliente;  

Cliente* cria_cliente(const char *nome, const char *bairro, int pessoas, int tem_criancas, double renda); 
void libera_cliente(Cliente *c); 
void imprime(Cliente *cliente);

const char* get_nome(const Cliente* c); 
const char* get_bairro(const Cliente* c); 
int get_pessoas(const Cliente* c); 
int get_criancas(const Cliente* c); 
double get_renda(const Cliente* c);  

#endif
