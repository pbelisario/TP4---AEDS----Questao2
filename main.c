#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "arquivo.h"

int main(int argc, char const *argv[]) {
  //iniciando a lista encadeada
  nodo *sentinela;
  sentinela = iniciaNodo();

  //sentinela da lista que contera as palavras do dicionario negativo
  nodo *sentinelaNegativo;
  sentinelaNegativo = iniciaNodo();

  nodo *aux;
  aux = iniciaNodo();

  FILE *arqEntrada;
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


  free(aux);
  deletaLista(sentinela);
  deletaLista(sentinelaNegativo );
  fclose(arqEntrada);
  fclose(arqSaida);
  fclose(dicioNegativo);
}
