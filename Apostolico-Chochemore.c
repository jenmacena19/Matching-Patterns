#include<stdio.h>
#Define MAX 100
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
         if (k >= l)
            OUTPUT(j);
      }
      j += (i - kmpNext[i]);
      if (i == l)
         k = MAX(0, k - 1);
      else
         if (kmpNext[i] <= l) {
            k = MAX(0, kmpNext[i]);
            i = l;
         }
         else {
            k = l;
            i = kmpNext[i];
         }
   }
}
