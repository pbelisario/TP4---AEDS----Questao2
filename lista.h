#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo nodo;
typedef struct Lista lista;

lista *inciaLista();

nodo *iniciaNodo();

void preencheNodo(nodo *, char[], int);

void inserirElemento(nodo n, lista l);
//insere ordenadamente e checa se ele já existe,
//caso exista adicona-se mais uma página/linha

void OqueEscrever(lista *l);
//Envia  o nodo que será escrito no arquivo

lista deletar (lista *l);
//Da free na lista inteira

#endif
