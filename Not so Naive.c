//Funcao para o algoritmo Not So Naive
void NotSoNaive(char *x, int m, char *y, int n) {
   int j, k, l;
  
   //Pre Processamento
   if (x[0] == x[1]) {
      k = 2;
      l = 1;
   }
   else {
      k = 1;
      l = 2;
   }
  
   //Buscando padrao em textos
   j = 0;
   while (j <= n - m)z
      if (x[1] != y[j + 1])
         j += k;
      else {
         //utilizando a funcao memcpm... Referencia: https://www.cplusplus.com/reference/cstring/memcmp/
         if (memcmp(x + 2, y + j + 2, m - 2) == 0 &&
             x[0] == y[j])
            OUTPUT(j);
         j += l;
      }
}

