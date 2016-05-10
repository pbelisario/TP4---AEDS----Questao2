#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo nodo;

nodo *iniciaNodo();

void preencheNodo(nodo *, char[], int);

void inserirElemento(nodo *, nodo *);
//insere ordenadamente e checa se ele já existe,
//caso exista adicona-se mais uma página/linha

int verificaDicionario(nodo *, nodo *);
//percorre a lista que contém as palavras do dicionario negativo
//retorna 1 se já existir a palavra no dicionario

#endif
