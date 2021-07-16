/* Jeniffer Macena & Raquel Lais
AED2 - 2020/2
Algoritmo de Boyer-Moore - encontrar padrao em seguencia genetica*/

#include <iostream>
using namespace std;
#define CARACTERES 256 //caracteres ASCII

void badCharacters(string str, int tam, int badchar[CARACTERES]) //funcao pra inicializar e preencher
{
  int i;

  for (i = 0; i < CARACTERES; i++) //inicializa o vetor
    badchar[i] = -1;

  for (i = 0; i < tam; i++) // preenche o vetor
    badchar[(int)str[i]] = i;
}

void busca(string texto, string padrao) //funcao de busca
{
  int m = padrao.size();
  int n = texto.size();
  int badchar[CARACTERES];

  badCharacters(padrao, m, badchar);

  int s = 0; //marca mudanca do padrao com o texto

  while (s <= (n - m))
  {
    int j = m - 1;

    while (j >= 0 && padrao[j] == texto[s + j])
      j--;

    if (j < 0)
    {
      cout << " Total de mudancas = " << s << endl;

      //faz o alinhamento caso o caracter do texto com o padrao.
      s += (s + m < n) ? m - badchar[texto[s + m]] : 1;
    }

    else
      //faz o alinhamento caso o caracter do padrao com o texto.
      s += max(1, j - badchar[texto[s + j]]);
  }
}

int main()
{
  string texto = "GCTTCTGCTACCTTTTGCGCGCGCGCGGAA";
  string padrao = "CCTTTTGC";
  busca(texto, padrao);
  return 0;
}
