#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "arquivo.h"

int main(int argc, char const *argv[]) {
  nodo *sentinela;
  sentinela = iniciaNodo();
  nodo *teste;
  teste = iniciaNodo();
  preencheNodo(teste, "Andre", 3);
  imprimeNodo(teste);
  printf("\n");

  FILE *arqEntrada;
  arqEntrada = AbrirArquivoEntrada();
  FILE *arqSaida = GeraArquivoSaida();

  char palavraTeste[50];
  LerPalavra(arqEntrada,palavraTeste);
  printf("Palavra lida: %s\n", palavraTeste);
  free(teste);
  free(sentinela);
  fclose(arqEntrada);
  fclose(arqSaida);
}
