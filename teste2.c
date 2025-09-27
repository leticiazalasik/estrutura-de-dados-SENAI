#include <stdio.h>
#include "cliente.h"
#include "estrutura.h"
#include "lista.h"
#include "nodo.h"

void imprime(Cliente *cliente) {
    printf("Nome      : %40s\nBairro    : %40s\nQ Pessoas : %40d\nCriancas  : %40s\nRenda     : %40.2f\n\n", get_nome(cliente), get_bairro(cliente), get_pessoas(cliente), get_criancas(cliente) == 0 ? "Nao": "Sim", get_renda(cliente));
}

int main() {
/*-------------------------------------------------------------------------------------------------
Criação de dez clientes para inserir na estrutura
-------------------------------------------------------------------------------------------------*/    
    Cliente *cliente[10];
    cliente[0] = cria_cliente("Alberto", "Centro", 3, 1, 4500.00);
    if(!cliente[0]) perror("Cliente[0] nao foi criado");
    cliente[1] = cria_cliente("Bernardo", "Ingleses", 1, 0, 1800.00);
    if(!cliente[1]) perror("Cliente[1] nao foi criado");
    cliente[2] = cria_cliente("Amarilis", "Trindade", 2, 0, 2980.00);
    if(!cliente[2]) perror("Cliente[2] nao foi criado");
    cliente[3] = cria_cliente("Rodolfo", "Centro", 5, 1, 6500.00);
    if(!cliente[3]) perror("Cliente[3] nao foi criado");
    cliente[4] = cria_cliente("Maria", "Trindade", 2, 1, 15800.00);
    if(!cliente[4]) perror("Cliente[4] nao foi criado");
    cliente[5] = cria_cliente("Marta", "Trindade", 1, 0, 8000.00);
    if(!cliente[5]) perror("Cliente[5] nao foi criado");
    cliente[6] = cria_cliente("Vanessa", "Centro", 3, 1, 8300.00);
    if(!cliente[6]) perror("Cliente[6] nao foi criado");
    cliente[7] = cria_cliente("Gilberto", "Ingleses", 2, 0, 4000.00);
    if(!cliente[7]) perror("Cliente[7] nao foi criado");
    cliente[8] = cria_cliente("Simone", "Centro", 1, 0, 5000.00);
    if(!cliente[8]) perror("Cliente[8] nao foi criado");
    cliente[9] = cria_cliente("Antonio", "Trindade", 4, 1, 3500.00);
    if(!cliente[9]) perror("Cliente[9] nao foi criado");
/*-------------------------------------------------------------------------------------------------
Criação da estrutura vazia
-------------------------------------------------------------------------------------------------*/
    Estrutura *estrutura = cria_estrutura(); 
    if(!estrutura) perror("Estrutura nao foi criada");
    int i;
/*-------------------------------------------------------------------------------------------------
População das hashtables com os clientes criados:
1 - inserção na estrutura que usa o nome como chave
2 - inserção na estrutura que usa o bairro como chave
3 - inserção na estrutura que usa como chave a quantidade de pessoas na residência
4 - inserção na estrutura que usa como chave a presença de crianças menores de 5 anos
5 - inserção na estrutura que usa como chave a renda bruta familiar
-------------------------------------------------------------------------------------------------*/
    for(i = 0; i < 10; i++) {
        insere_cliente(estrutura, 1, cliente[i]);
        insere_cliente(estrutura, 2, cliente[i]);
        insere_cliente(estrutura, 3, cliente[i]);
        insere_cliente(estrutura, 4, cliente[i]);
        insere_cliente(estrutura, 5, cliente[i]);
    }
    printf("Inseridos na estrutura ...\n");
/*-------------------------------------------------------------------------------------------------
Recuperação de clientes usando nome como chave de busca
-------------------------------------------------------------------------------------------------*/
    Lista *lista = recupera_cliente(estrutura, 1, 0, "Vanessa");
    if(get_quantidade(lista) > 0) {
        printf("Clientes com nome Vanessa [1]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Esperado 1 , mas nenhum cliente recuperado com nome Vanessa!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 1, 0, "Arthur");
    if(get_quantidade(lista) > 0) {
        printf("Nao era esperado, mas ha clientes com nome Arthur:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com nome Arthur, conforme esperado!\n");
    }
    printf("-------------------------------------------\n\n");
/*-------------------------------------------------------------------------------------------------
Recuperação de clientes usando bairro como chave de busca
-------------------------------------------------------------------------------------------------*/
    lista = recupera_cliente(estrutura, 2, 0, "Centro");
    if(get_quantidade(lista) > 0) {
        printf("Cliente do Centro [4]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado do bairro Centro, era esperado 4!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 2, 0, "Ingleses");
    if(get_quantidade(lista) > 0) {
        printf("Clientes de Ingleses [2]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado do bairro Ingleses, era esperado 2!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 2, 0, "Trindade");
    if(get_quantidade(lista) > 0) {
        printf("Clientes da Trindade [4]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado do bairro Trindade, era esperado 4!\n");
    }
    printf("-------------------------------------------\n\n");
/*-------------------------------------------------------------------------------------------------
Recuperação de clientes usando quantidade de pessoas como chave de busca
-------------------------------------------------------------------------------------------------*/
    lista = recupera_cliente(estrutura, 3, 1, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes com 1 pessoa na residencia [3]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com 1 pessoa na residencia, eram esperados 3!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 3, 2, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes com 2 pessoas na residencia [3]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com 2 pessoas na residencia, eram esperados 3!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 3, 3, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes com 3 pessoas na residencia [2]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com 3 pessoas na residencia, eram espardos 2!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 3, 4, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes com 4 pessoas na residencia [1]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com 4 pessoas na residencia, era esperado 1!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 3, 5, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes com 5 ou mais pessoas na redidencia [1]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com 5 ou mais pessoas na residencia, era esperado 1!\n");
    }
    printf("-------------------------------------------\n\n");
/*-------------------------------------------------------------------------------------------------
Recuperação de clientes usando a existência de menores de 5 anos como chave de busca
-------------------------------------------------------------------------------------------------*/
    lista = recupera_cliente(estrutura, 4, 0, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes que nao possuem menores de 5 anos na residencia [5]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado sem menores na residencia, eram esperados 5!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 4, 1, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes que possuem menores de 5 anos na residencia [5]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com menores na residencia, eram esperados 5!\n");
    }
    printf("-------------------------------------------\n\n");
/*-------------------------------------------------------------------------------------------------
Recuperação de clientes usando a faixa de renda bruta como chave de busca
-------------------------------------------------------------------------------------------------*/
    lista = recupera_cliente(estrutura, 5, 1, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes que possuerm renda de ate 2000 [1]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com renda de ate 2000, era esperado 1!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 5, 2, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes que possuerm renda de ate 3000 [1]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com renda de ate 3000, era esperado 1!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 5, 3, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes que possuerm renda de ate 5000 [4]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com renda de ate 5000, eram esperados 4!\n");
    }
    printf("-------------------------------------------\n\n");
    lista = recupera_cliente(estrutura, 5, 4, NULL);
    if(get_quantidade(lista) > 0) {
        printf("Clientes que possuem renda maior que 5000 [4]:\n");
        Nodo *cursor = get_inicio(lista);
        while(cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    } else {
        printf("Nenhum cliente recuperado com renda superior a 5000, eram esperados 4!\n");
    }
    libera_estrutura(estrutura);
}