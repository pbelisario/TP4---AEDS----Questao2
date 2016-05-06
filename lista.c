#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "arquivo.h"

#define MAXLINHAS 10
#define TAMPALAVRA 50
#define MAXPALAVRAS 100

struct Nodo{
	char palavra[TAMPALAVRA];
	int linha[MAXLINHAS];
	int numeroDeLinhas;//se houver mais de uma linha
	nodo *prox;
};

nodo *iniciaNodo(){
	nodo *n;
	n = (nodo*) malloc (sizeof(nodo));
	n->numeroDeLinhas = 0;
	printf("Nodo iniciado.\n");
	return n;
}

void preencheNodo(nodo *n, char palavra[], int linha){
	int i;
	for(i=0; palavra[i]!='\0'; i++)
		n->palavra[i] = palavra[i];
	n->linha[n->numeroDeLinhas] = linha;
	n->numeroDeLinhas++;
	printf("Nodo preenchido.\n");
}

void inserirElemento(nodo *primeiro, nodo* n){
	printf("Entrou em inserir elemento\n");
	nodo *aux;
	aux = primeiro;
	int comparacao = strcmp(n->palavra, aux->palavra);
	//se for o primeiro
	if( comparacao < 0){
		n->prox = aux;
		primeiro = n;
		return;
	}

	if(comparacao == 0){
		aux->linha[aux->numeroDeLinhas] = n->linha[0];
		aux->numeroDeLinhas++;
		free(n);
		return;
	}

	while(aux->prox != NULL){
		comparacao = strcmp(n->palavra, aux->prox->palavra);
		if(comparacao < 0){
			n->prox = aux->prox;
			aux->prox = n;
			return;
		}
		if(comparacao == 0){
			aux->prox->linha[aux->prox->numeroDeLinhas] = n->linha[0];
			aux->prox->numeroDeLinhas++;
			free(n);
			return;
		}
		aux = aux->prox;
	}
	printf("Saiu do While\n");
	aux->prox = n;
	n->prox = NULL;
}

void imprimeNodo(nodo *n){
	printf("Palavra: %s\t", n->palavra);
	printf("Linha: %d\n", n->linha[0]);
}

void imprimeLista(nodo *primeiro){
	nodo *aux;
	aux = primeiro;
	while(aux != NULL){
		imprimeNodo(aux);
		aux = aux->prox;
	}
}
