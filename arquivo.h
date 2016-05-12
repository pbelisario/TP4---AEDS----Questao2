#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "lista.h"

//Abre o arquivo que contem o texto a ser lido
//Também abrirá o dicionario negativo
FILE *AbrirArquivoEntrada (char *);

// Cria o arquivo em que estará o indice remissivo
FILE *GeraArquivoSaida ();

//Escreve o conteúdo do nodo no arquivo 
void EscreveNoArquivo (FILE *, nodo *);

// Dado um arquivo, retorna um nodo contendo a palavra e a linha
nodo *LerPalavra(FILE *, char palavra[]);
#endif
