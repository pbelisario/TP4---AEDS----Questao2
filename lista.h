#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo nodo;

nodo *iniciaNodo();

void preencheNodo(nodo *, char[], int);
//dado uma palavra e uma linha, preenche o nodo com esses valores
//caso a palavra ja esteja no indice, so altera o vetor de linhas

void inserirElemento(nodo *, nodo *);
//insere ordenadamente e checa se ele já existe,
//caso exista adicona-se mais uma página/linha

int verificaDicionario(nodo *, nodo *);
//percorre a lista que contém as palavras do dicionario negativo
//retorna 1 se já existir a palavra no dicionario

void deletaLista(nodo *);
//percorre a lista liberando a memoria de cada nodo

#endif
