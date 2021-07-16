#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

//funcao auxiliar para o pre-processamento do texto
void preKmp(char *x, int m, int kmpNext[]) {
   int i, j;

   i = 0;
   j = kmpNext[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}

//implementacao da fundao do algoritmo Crochemore 
void ApCrochemore(char *x, int m, char *y, int n) { 
   //x e y são ponteiro que aponta para uma cadeia de caracteres (texto)
   int i, j, k, l, kmpNext[MAX];
   
   // Pré-Processamento do texto chamando a a funcao do algoritmo Knuth-Morris-Pratt
   preKmp(x, m, kmpNext);
   for (l = 1; x[l - 1] == x[l]; l++){
      if (l == m){
      l = 0;
      }
   }
   //Buscando o padrão no texto
   i = l;
   j = 0;
   k = 0;
   while (j <= n - m) {
      while (i < m && x[i] == y[i + j])
         ++i;
      if (i >= m) {
         while (k < l && x[k] == y[j + k])
            ++k;
         if (k >= l){
         	printf("%c", j);
		 }
    
      }
      j += (i - kmpNext[i]);
      if (i == l)
         k = MAX(0, k - 1);
      else
         if (kmpNext[i] <= l) {
            k = 100(0, kmpNext[i]);
            i = l;
         }
         else {
            k = l;
            i = kmpNext[i];
         }
   }
}

