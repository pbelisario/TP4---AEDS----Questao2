#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "arquivo.h"

#define MAXLINHAS 100
#define TAMPALAVRA 50
#define MAXPALAVRAS 100

//Erro causado por uso de inteiro static
#define ERROLINHA 185

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
	return n;
}

void preencheNodo(nodo *n, char palavra[], int linha){
	int i;
	for(i=0; palavra[i]!='\0'; i++)
		n->palavra[i] = palavra[i];
	n->linha[n->numeroDeLinhas] = linha - ERROLINHA;
	n->numeroDeLinhas++;
}

void inserirElemento(nodo *primeiro, nodo *n){
	nodo *aux;
	aux = primeiro;
	int comparacao = strcasecmp(n->palavra, aux->palavra);
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
	//caso nao seja o primeiro, percorre a lista para encontrar posicao de inserção
	while(aux->prox != NULL){
		comparacao = strcasecmp(n->palavra, aux->prox->palavra);
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
	aux->prox = n;
	n->prox = NULL;
}

int verificaDicionario(nodo *sentinelaNegativo, nodo *n){
	nodo *aux;
	aux = sentinelaNegativo;
	//percorre lista verificando
	while(aux != NULL){
		if(strcmp(aux->palavra, n->palavra) == 0){
			return 1;
		}
		aux = aux->prox;
	}
	return 0;
}

void imprimeNodo(nodo *n){
	//função de auxilio
	int i=0;
	printf("%13s%10d", n->palavra, n->linha[i]);
  i++;
  while (i < n->numeroDeLinhas){
    printf(",%d", n->linha[i]);
    i++;
  }
	printf("\n");
}

void imprimeLista(nodo *primeiro){
	//função de auxilio
	nodo *aux;
	aux = primeiro;
	while(aux != NULL){
		imprimeNodo(aux);
		aux = aux->prox;
	}
}

void deletaLista(nodo *primeiro){
	//libera memoria
	nodo *aux;
	while(primeiro != NULL){
		aux = primeiro;
		primeiro = primeiro->prox;
		free(aux);
	}
}

//funções necessárias devido à modularização do codigo
char *getPalavra(nodo *n){
	return n->palavra;
}

int getNumeroDeLinhas(nodo *n){
	return n->numeroDeLinhas;
}

int *getLinhas(nodo *n){
	return n->linha;
}

nodo *getProx(nodo *n){
	return n->prox;
}
