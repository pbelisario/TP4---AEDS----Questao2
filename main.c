#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "arquivo.h"

int main(int argc, char const *argv[]) {
  //iniciando a lista encadeada
  nodo *sentinela;
  sentinela = iniciaNodo();

  //sentinela da lista que conterá as palavras do dicionario negativo
  nodo *sentinelaNegativo;
  sentinelaNegativo = iniciaNodo();

  nodo *aux;
  aux = iniciaNodo();

  FILE *arqEntrada;
  //o texto a ser lido é passado neste momento
  arqEntrada = AbrirArquivoEntrada("Texto2.txt");
  FILE *dicioNegativo;
  dicioNegativo = AbrirArquivoEntrada("DicionarioNegativo.txt");
  FILE *arqSaida = GeraArquivoSaida();

  //Preenhendo uma lista com as palavras do dicionario
  char palavra[50];
  while(!feof(dicioNegativo)){
    aux = LerPalavra(dicioNegativo,palavra);
    if(aux != NULL){
      inserirElemento(sentinelaNegativo, aux);
    }
  }

  //Preenchendo outra lista com o indice remissivo
  //utiliza a lista encadeada aqui
  //verifica se a palavra existe no dicionario negativo
  while(!feof(arqEntrada)){
    aux = LerPalavra(arqEntrada,palavra);
    if(aux != NULL && !(verificaDicionario(sentinelaNegativo, aux)) ){
        inserirElemento(sentinela, aux);
    }
  }
  imprimeLista(sentinela);
  aux = sentinela;
  while(aux != NULL){
    EscreveNoArquivo(arqSaida, aux);
    aux = (nodo *) getProx(aux);
  }

  //liberação de memorias alocadas
  free(aux);
  deletaLista(sentinela);
  deletaLista(sentinelaNegativo );
  fclose(arqEntrada);
  fclose(arqSaida);
  fclose(dicioNegativo);
}
