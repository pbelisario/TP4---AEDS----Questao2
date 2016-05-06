#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "lista.h"

//MODIFICAR A PARTE DE LER PALAVRA TEM QUE FAZER CHECAGEM NO DICIONARIO NEGATIVO


//Abre o arquivo que contem o texto a ser lido
//Também abrirá o dicionario negativo
FILE *AbrirArquivoEntrada ();

// Cria o arquivo em que estará o indice remissivo
FILE *GeraArquivoSaida ();

//Escreve uma string no arquivo passado
void EscreveNoArquivo (FILE *, nodo *);

// Dado um arquivo, retorna o vetor palavra (passado como argumento)
// preenchido com a primeira palavra encontrada e sua linha correspondente
nodo *LerPalavra(FILE *, char palavra[]);

//Dado um numero retorna em uma string esse numero na base desejada
//o termo i corresponde a partir de qual posição da string que se escreverá o numero desejado
char* itoa(int num, char numeroEmString[], int base, int i);

//Dado um a string a espelha a partir de uma posição inicial desejada
void espelhar(char numero[], int TamanhoDoNumero, int Posicaoinicial);


#endif
