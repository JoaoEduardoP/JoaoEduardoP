#include <stddef.h>
#include <stdio.h>

int word2vec(FILE *vArqEnt)
{
   int nValFor = 0;
   if (fscanf(vArqEnt,"rb"))
   {
      /* code */
   }
   else
   {
      
   }
}

int main()
{
   char vTxtRec;
   FILE *fp = fopen("Poem.txt","rb");
   if (fp != NULL)
   {
      if (!word2vec(fp))
      {
         printf("Erro na geração do vocábulo!");
         exit(0);
      } 
   }
   else
   {
      printf("Erro de leitura do arquivo");
      exit(0);
   }
}