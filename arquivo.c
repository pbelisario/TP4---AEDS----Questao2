#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "lista.h"

FILE *AbrirArquivoEntrada (char *nome){
  FILE *arqEntrada = fopen (nome, "r");
  if (arqEntrada == NULL){
    printf("Falha ao abrir o arquivo\n");
    //Termina o programa se não houver arquivo
    exit(1);
  }
  else {
    printf("Arquivo aberto com sucesso\n");
    return arqEntrada;
  }
}

FILE *GeraArquivoSaida (){
  FILE *arqSaida = fopen ("SAIDA2.txt", "w");
  printf("Arquivo de saida aberto com sucesso.\n");
  return arqSaida;
}


//Recebe um nodo da lista imprime segundo esse padrao já escrito
void EscreveNoArquivo (FILE *arq,nodo *n){
  int i = 0;
  int *linhas;
  //ponteiro necessario para acessar o vetor de linhas dos nodos
  linhas = (int *)  getLinhas(n);
  fprintf(arq, "%13s%10d", (char *)getPalavra(n), linhas[0]);
  i++;
  while (i < getNumeroDeLinhas(n)){
	  //caso haja mais de uma linha, esse while garante que todas serao impressas
    fprintf(arq, ",%d", linhas[i]);
    i++;
  }
  fprintf(arq, "\n" );
}


nodo *LerPalavra(FILE *arq, char palavra[]){
  //VARIAVEIS DE CONTROLE
  // Determina a Linha atual
  static int linha = 1;
  // Diz se já se pode terminar a palavra
  int EFimDePalavra = 0;
  // Indice do vetor palavra recebido como argumento
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
      if (EFimDePalavra){
        palavra[index] = '\0';
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
        nodo *n;
        n = iniciaNodo();
        preencheNodo(n, palavra, linha);
        return n;
      }
    }
    letra = fgetc (arq);
  }
  return NULL;
}
