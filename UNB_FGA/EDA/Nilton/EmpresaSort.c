
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int EmpresaSort(char ArrDes[], int QtdArr) // Ordenar Pelo Nome da Empresa
{
   int i, j, linha, coluna;
   char next;
   for (i=1;i<QtdArr; i++)
   {
        char next = ArrDes[i][2];
        for (j=i-1; j>= 0 && (strcmp(next, ArrDes[j][2])==-1);j--)
        {
            ArrDes[j+1] = ArrDes[j];
            ArrDes[j+1][2] = next;
        }
   }
}