#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "lista.h"


FILE *AbrirArquivoEntrada (){
  FILE *arqEntrada = fopen ("nome.txt", "r");
  if (arqEntrada == NULL){
    printf("%s\n", "Falha ao abrir o arquivo");
    //Termina o programa se não houver arquivo
    exit(1);
  }
  else {
    printf("%s\n", "Arquivo aberto com sucesso");
    return arqEntrada;
  }
}

FILE *GeraArquivoSaida (){
  FILE *arqSaida = fopen ("SAIDA.txt", "w");
  return arqSaida;
}
//Recebe um nodo da lista imprime segundo esse padrao já escrito
void EscreveNoArquivo (FILE *arq, char palavra[], int linha[], int tam){
  int i = 0;
  fprintf(arq, "%s\t%d", palavra, linha[i]);
  i++;
  while (i < tam){
    fprintf(arq, ",%d", linha[i]);
    i++;
  }
  fprintf(arq, "\n" );
}


char LerPalavra(FILE *arq, char palavra[]){
  //VARIAVEIS DE CONTROLE
  // Determina a Linha atual
  static int linha = 1;
  char linhaS[10]; //Caso o numero de linhas seja maior do que 10 essa string conterá o numero se ele possuir menos do que 10 posições
  // Diz se já se pode terminar a palavra
  int EFimDePalavra = 0;
  // Indice do vetor palavra recebido como argumente
  int index = 0;
  // Caracter a ser analizado para formar uma palavra
  int letra = fgetc (arq);
  // FUNÇÃO EM SI
  // Percorre o arquivo analisando-o de letra em letra concatenando-as ou não,
  // seguindo o parametro em que demarcador de palvra é tudo aquilo que
  // for diferente das 26 letras do alfabeto(de A ate Z) e dos numeros de 0 a 9
  while (letra != EOF){
    // Nessa primeira Condição tem-se como objetivo concatenar as letras para formar uma palavra
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || (letra >= '0' && letra <= '9')){
        palavra[index] = letra;
        index++;
        EFimDePalavra = 1;
    }else{
      // Caso ja tenha colocado ao menos uma letra no vetor palavra,
      // o finaliza, adicionando a linha em que está a tal palavra
      if (EFimDePalavra){
        palavra[index] = ' ';
        itoa(linha, palavra, 10, (index+1));
      }
      //Caso o caracter encontrado seja um <ENTER> passará de linha
      if (letra == '\n'){
        linha++;
      }
      // Retorna o vetor preenchido e com a linha atual atualizada
      // Optou-se por fazer duas comparações indenticas uma vez que,
      // dessa forma palavras que terminassem a linhas, não mais seriam
      // consideradas como da linha seguinte
      if(EFimDePalavra){
        return palavra;
      }
    }
    letra = fgetc (arq);
  }
}
