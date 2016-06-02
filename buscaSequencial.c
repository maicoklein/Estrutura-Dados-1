#include <stdio.h>
 
int main()
{
   int c, first, last, middle, n, search, array[100];
 
   // informar o numero de elementos
   printf("Enter number of elements\n");
   scanf("%d",&n);
 
   // informar os numeros inteiros
   printf("Enter %d integers\n", n);
 
   for (c = 0; c < n; c++){
      scanf("%d",&array[c]);
   }
 
  // informar o numero a ser procurado
   printf("Enter value to find\n");
   scanf("%d", &search);
 
   first = 0;
   last = n - 1;
   middle = first; // middle eh o resultado da divisao por 2 do primeiro elemento mais o ultimo (0 + (n-1))
 
   while (middle <= last) { // enquanto que o primeiro elemento for menor que o ultimo, eh executado o while
      // se entra nesse if, a procura eh feita do meio para o fim do array
      if (array[middle] < search) 
         middle = middle + 1;     
      else if (array[middle] == search) 
      {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
   }
   // se middle e last se cruzarem, o numero procurado nao foi encontrado
   if (middle > last)
      printf("Not found! %d is not present in the list.\n", search);
 
   return 0;   
}
