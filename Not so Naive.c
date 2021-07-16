//Função para o algoritmo Not So Naive
void NotSoNaive(char *x, int m, char *y, int n) {
   int j, k, l;
  
   //Pré=Processamento
   if (x[0] == x[1]) {
      k = 2;
      l = 1;
   }
   else {
      k = 1;
      l = 2;
   }
  
   //Buscando padrão em textos
   j = 0;
   while (j <= n - m)
      if (x[1] != y[j + 1])
         j += k;
      else {
         if (memcmp(x + 2, y + j + 2, m - 2) == 0 &&
             x[0] == y[j])
            OUTPUT(j);
         j += l;
      }
}

