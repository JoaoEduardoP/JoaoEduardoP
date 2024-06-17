#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
void EmpresaSort(char *ArrDes[],int QtdArr) // Ordenar Pelo Nome da Empresa
{
   int i, j, linha, coluna;
   char next;
   for (i=1; i<QtdArr; i++) 
   {
      next = &ArrDes[i][2];
      printf("next: %s\n", next);
      for (j=i-1; j>=0 && (strcmp(next,&ArrDes[j][2])==-1);j--)
      {
         ArrDes[j+1] = &ArrDes[j];
      }
      ArrDes[j+1][2] = next;
   }
   
   for(linha = 0 ; linha < QtdArr ; linha++)
      for(coluna = 0 ; coluna < QtdArr ; coluna++)
      {
         printf("Elemento [%d][%d]: ", linha+1, coluna+1);
         scanf("%d", &ArrDes[linha][coluna]);
      }
   for(linha = 0 ; linha < QtdArr ; linha++)
   {
      for(coluna = 0 ; coluna < QtdArr ; coluna++)
          printf("%3d", ArrDes[linha][coluna]);
      printf("\n"); //após cada linha ser impressa, um salto de linha
   }
}

int main()
{
   char ArrDes[3][3];
   
   EmpresaSort(*ArrDes,3);
}