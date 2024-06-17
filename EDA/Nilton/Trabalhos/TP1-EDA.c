#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct airline{
  int  id;
  char airlineCode[3];
  int  delay;
  int  contada;
}airline;

typedef struct sub_airline{
  char   airlineCode[3];
  int    quant_delay;
  int    total;
  float  media;
}sub_airline;

int ValArq(FILE *fp){
  if (fp == NULL){
      printf("Nao foi possivel abrir o arquivo.");
      return 0;
    }
  return 1;
}

void VerMedVet(airline *Vetor,sub_airline *VetAir,int QtdLinhas){
  clock_t t = clock();
  int e = 0,f = 0,g = 0,ValTot=0,ValDel=0;
  for (e = 0; e < QtdLinhas; e++){
    if (Vetor[e].contada==1){
      ValTot=0;
      ValDel=0;
      for(f=0;f < QtdLinhas;f++){
        if(strcmp(Vetor[e].airlineCode,Vetor[f].airlineCode) == 0)
        {
          if (Vetor[f].delay==1)
          {
            ValDel++;
          }
          ValTot++;
        }
      }
      sprintf(VetAir[g].airlineCode,"%s",Vetor[e].airlineCode);
      VetAir[g].quant_delay=ValDel;
      VetAir[g].total=ValTot;
      VetAir[g].media=(float)ValDel/ValTot;
      g++;
    }
  }
  t = clock() - t;
  printf("Tempo de calculo da media: %lf",((double)t)/((CLOCKS_PER_SEC/1000)));
}

void PreVetArq(FILE *vArqEnt,airline *vetor){
  int s=0,c=0;
  vArqEnt = fopen("Airlines.csv", "r");
  if (ValArq(vArqEnt)){
    //Percorre o Arquivo
    while (!feof(vArqEnt)){
      //Pular o Cabeçalho
      if (s==0){
        for (c = getc(vArqEnt); c != EOF; c = getc(vArqEnt))
          if (c == '\n') 
            break;
      }
      //Preencher o vetor com os dados da DataBase.
      if (!fscanf(vArqEnt,"%d,%[^,],%d",&vetor[s].id,vetor[s].airlineCode, &vetor[s].delay)){
        printf("Erro ao Scanear o arquivo."); 
        break;
      }   
      s++;
    }
    fclose(vArqEnt);
  }
}

void InsertSort(sub_airline *VetAir,int QtdAir)
{
  clock_t t = clock();
  int e=0,f=0;
  sub_airline VetSub;
  for (e=1; e < QtdAir; e++) {
    VetSub = VetAir[e];
    for (f=e; (f>0) && (VetSub.media < VetAir[f-1].media);f--)
      {
        VetAir[f] = VetAir[f-1];
      }
    VetAir[f]= VetSub;
  }
  t = clock() - t;
  printf("\nTempo da ordenação (Insert Sort): %lf",((double)t)/((CLOCKS_PER_SEC/1000)));
}

void CriArqCsv(sub_airline *VetAir,int QtdAir){
  int e=0,f=0;
  FILE *arquivosaida;  
  arquivosaida = fopen("AirlinesSaida.csv","w+");
  if (arquivosaida == NULL){
      printf("Erro na criação do arquivo de saida!");
        exit(1);
    }
    else{
      fprintf(arquivosaida,"Airline,Media\n");
      for(e=0; e<QtdAir; e++){
        fprintf(arquivosaida, "%s,%f\n", VetAir[e].airlineCode, VetAir[e].media);
      }
      fclose(arquivosaida);
    }
}

int AloVet(FILE *vArqEnt,airline *vetor,int QtdVet,int *QtdAir){
  int e=0,f=0,g=0,s=0;
  char c,ProVet[3];
  vArqEnt = fopen("Airlines.csv", "r");
  if (ValArq(vArqEnt))
  {
    //Preenche o Struct 'AirLine' com o conteudo do arquivo .csv
    PreVetArq(vArqEnt,vetor);
    //Definir os vetores para contar como 0 para trabalho no For abaixo. 
    for(e=0;e <= QtdVet;e++){
      vetor[e].contada = 0;
    }
    //Contar quantas linhas aereas sao unicas e definir 1 para unica no airline[].contada e 0 para repetida
    for (e = 0; e < QtdVet; e++){
      if (vetor[e].contada == 1){
        vetor[e].contada = 0;
        continue;    
      }
      else{
        for(f=0;f < QtdVet;f++){  
          if(strcmp(vetor[e].airlineCode,vetor[f].airlineCode) == 0){
            if(vetor[f].contada == 0){
              vetor[f].contada = 1;
            }
          }
        }
        *QtdAir = *QtdAir + 1;       
      }
    }  
  }
  else{
    return 0;
  }     
return 1;
}


int main(){
  //variaveis globais
  clock_t t = clock();
  FILE *fp;
  int e = 0,f = 0,g = 0,QtdLinhas=0,QtdAir=0,ValTot=0,ValDel=0;
  char c;  
  airline *VetorDinamico;
  sub_airline *VetAir;

  //abre o arquivo e conta as linhas para alocar um vetor na memoria
  fp = fopen("Airlines.csv", "r");
  if (ValArq(fp)){
    for (c = getc(fp); c != EOF; c = getc(fp))
      if (c == '\n')
        QtdLinhas++;
      fclose(fp);

    //Alocaçao do struct principal.
    VetorDinamico = (airline*)malloc(QtdLinhas*sizeof(airline));
    if (VetorDinamico == NULL){
		  printf("Alocacao mal sucedida!");
		  exit(1);
      return 0;
	  }
	  else{
      //Preenche e trabalha com o struct principal.
      AloVet(fp,VetorDinamico,QtdLinhas,&QtdAir);
      //Alocação da struct com os dados finais.
      VetAir = (sub_airline*)malloc(QtdAir*sizeof(sub_airline));
      if (VetAir == NULL){
		    printf("Alocacao mal sucedida!");
		    exit(1);
        return 0;
	    }
      else
      {
        //achar a média e preencher no struct secundário.
        VerMedVet(VetorDinamico,VetAir,QtdLinhas);
        //Insert Sort para Ordenar struct secundário por média.
        InsertSort(VetAir,QtdAir);
        //Cria e preenche arquivo de saida.
        CriArqCsv(VetAir,QtdAir);
        free(VetAir);
      }
      free(VetorDinamico);
    }
    t = clock() - t;
    printf("\nTempo de Execução Total: %lf",((double)t)/((CLOCKS_PER_SEC/1000)));
  }
  else
  {
    return 0;
  }
  return 1;
}