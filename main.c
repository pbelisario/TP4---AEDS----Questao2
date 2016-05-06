#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "arquivo.h"

int main(int argc, char const *argv[]) {
  //iniciando a lista encadeada
  nodo *sentinela;
  sentinela = iniciaNodo();


  nodo *teste;
  teste = iniciaNodo();

  FILE *arqEntrada;
  arqEntrada = AbrirArquivoEntrada();
  FILE *arqSaida = GeraArquivoSaida();

  char palavraTeste[50];
  while(!feof(arqEntrada)){
    teste = LerPalavra(arqEntrada,palavraTeste);
    if(teste != NULL){
      inserirElemento(sentinela, teste);
      //TO DO verifica dicionario negativo
      imprimeLista(sentinela);
    }
  }
  //TO DO escreve no arquivo de saida
  //imprimeLista(sentinela);
  free(teste);
  free(sentinela);
  fclose(arqEntrada);
  fclose(arqSaida);
}
