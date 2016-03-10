#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   int **p;
   int i, j, n;
   printf("Defina o numero de linhas: ");
   scanf("%d", &n);

   p = (int**) malloc (n * sizeof(int *)); //Cria um array de ponteiros
   for (i = 0; i < n; i++){
     p[i] = (int *) malloc (n * sizeof(int *)); //Cria um array de int
     for (j = 0; j < n; j++)
       scanf("%d", &p[i][j]); //Le a matriz de inteiros
   }

    for (i = 0; i <  n; i++){
      for (j = 0; j < n; j++){
         printf("%d ", p[i][j]); //Imprime a matriz de inteiros
      }
    printf("\n");
    }

   for (i = 0; i < n; i++)
       free (p[i]);
   free(p);
 
   return 0;
}
