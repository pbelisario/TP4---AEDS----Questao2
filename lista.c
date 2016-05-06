#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "arquivo.h"

#define MAXLINHAS 10
#define TAMPALAVRA 50
#define MAXPALAVRAS 100

struct Nodo{
	char palavra[TAMPALAVRA];
	int linha[MAXLINHAS];
	int tam;//se houver mais de uma linha
	nodo *prox;
};

nodo *iniciaNodo(){
	nodo *n;
	n = (nodo*) malloc (sizeof(nodo));
	printf("Nodo iniciado.\n");
	return n;
}

void preencheNodo(nodo *n, char palavra[], int linha){
	int i;
	for(i=0; palavra[i]!='\0'; i++)
		n->palavra[i] = palavra[i];
	n->linha[0] = linha;
	printf("Nodo preenchido.\n");
}

void imprimeNodo(nodo *n){
	printf("Palavra: %s\t", n->palavra);
	printf("Linha: %d\n", n->linha[0]);
}
