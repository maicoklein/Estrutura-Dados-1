#include <stdio.h>
 
int main()
{
   int c, first, last, middle, n, search, array[100];
 
   // informar o numero de elementos
   printf("Enter number of elements\n");
   scanf("%d",&n);
 
   // informar os numeros inteiros
   printf("Enter %d integers\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
 
   // informar o numero a ser procurado
   printf("Enter value to find\n");
   scanf("%d", &search);
 
   first = 0;
   last = n - 1;
   middle = (first+last)/2; // middle eh o resultado da divisao por 2 do primeiro elemento mais o ultimo (0 + (n-1))
 
   while (first <= last) { // enquanto que o primeiro elemento for menor que o ultimo, eh executado o while
      // se entra nesse if, a procura eh feita do meio para o fim do array
      if (array[middle] < search) 
         first = middle + 1;     
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
		 // se nao entra no if e entra no else, a procura eh feita do meio para o inicio
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   // se first e last se cruzarem, o numero procurado nao foi encontrado
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
 
   return 0;   
}
