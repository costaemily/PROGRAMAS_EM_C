#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubble_sort (int *vetor, int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selecao (int *vetor, int tam){
    int i, j, min, x;
    for (i=1; i<=tam-1; i++){
        min = i;
    for (j=i+1; j<=tam; j++){
            if (vetor[j] < vetor[min])
            min = j;
    }
    x = vetor[min];
    vetor[min] = vetor[i];
    vetor[i] = x;
    }
}

void insercao (int *vet, int tam){
int i, j, x;
for (i=2; i<=tam; i++){
    x = vet[i];
    j=i-1;
    vet[0] = x; 
    while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
}
}

void quick(int *vet, int esq, int dir){
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
}
 
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}
int ParaDezValores(int *vetor1){
	int i;
	clock_t T[10], tf, ti;
	printf("Gerando 10 valores aleatorios:\n\n");
  	srand(time(NULL));
  
  	vetor1 = (int *) malloc(sizeof (int));
  	for (i=0; i < 10; i++)
  	{
  		vetor1[i] = rand() % 100;
    	printf("%d ", vetor1[i]);
  	}
  	
 	ti = clock();
   	bubble_sort(vetor1, 10);
   	tf = clock();
   	printf("\nTempo de ordenacao do Bubble Sort para 10 numeros: %f", (tf - ti) / (double)CLOCKS_PER_SEC);
   	
   	printf("\nVetor Ordenado:\n\n");
  	for (i=0; i < 10; i++)
  	{
    	printf("%d ", vetor1[i]);
  	}
  	
   	T[2] = clock();
  	selecao(vetor1, 10);
  	T[3] = clock();
  	printf("\nTempo de ordenacao do Selection para 10 numeros: %f", (T[3] - T[2]) / (double)CLOCKS_PER_SEC);
  	
  	T[4] = clock();
  	insercao(vetor1, 10);
  	T[5] = clock();
  	printf("\nTempo de ordenacao do Selection para 10 numeros: %f", (T[5] - T[4]) / (double)CLOCKS_PER_SEC);
  	
  	T[6] = clock();
  	quick(vetor1, 0, 10-1);
  	T[7] = clock();
  	printf("\nTempo de ordenacao do Selection para 10 numeros: %f", (T[7] - T[6]) / (double)CLOCKS_PER_SEC);
  	
  	T[8] = clock();
  	mergeSort(vetor1, 0, 10-1);
  	T[9] = clock();
  	printf("\nTempo de ordenacao do Selection para 10 numeros: %f", (T[9] - T[8]) / (double)CLOCKS_PER_SEC);
  	
}
void ParaCemValores(int *vetor2){
	int i;
	printf("Gerando 100 valores aleatorios:\n\n");
  	srand(time(NULL));
  
  	vetor2 = (int *) malloc(sizeof (int));
  	for (i=0; i < 100; i++)
  	{
  		vetor2[i] = rand() % 100;
    	printf("%d ", vetor2[i]);
  	}
  
  	bubble_sort(vetor2, 100);
  	selecao(vetor2, 100);
  	insercao(vetor2, 100);
  	quick(vetor2, 0, 100-1);
  	mergeSort(vetor2, 0, 100-1);
  	
  	printf("\nVetor Ordenado:\n\n");
  	for (i=0; i < 10; i++)
  	{
    	printf("%d ", vetor2[i]);
  	}
}
void ParaMilValores(int *vetor3){
	int i;
	printf("Gerando 1.000 valores aleatorios:\n\n");
  	srand(time(NULL));
  
  	vetor3 = (int *) malloc(sizeof (int));
  	for (i=0; i < 1000; i++)
  	{
  		vetor3[i] = rand() % 100;
    	printf("%d ", vetor3[i]);
  	}
  
  	bubble_sort(vetor3, 1000);
  	selecao(vetor3, 1000);
  	insercao(vetor3, 1000);
  	quick(vetor3, 0, 1000-1);
  	mergeSort(vetor3, 0, 1000-1);
  	
  	printf("\nVetor Ordenado:\n\n");
  	for (i=0; i < 1000; i++)
  	{
    	printf("%d ", vetor3[i]);
  	}
}
void ParaDezMilValores(int *vetor4){
	int i;
	printf("Gerando 10.000 valores aleatorios:\n\n");
  	srand(time(NULL));
  
  	vetor4 = (int *) malloc(sizeof (int));
  	for (i=0; i < 10000; i++)
  	{
  		vetor4[i] = rand() % 100;
    	printf("%d ", vetor4[i]);
  	}
  
  	bubble_sort(vetor4, 10000);
  	selecao(vetor4, 10000);
  	insercao(vetor4, 10000);
  	quick(vetor4, 0, 10000-1);
  	mergeSort(vetor4, 0, 10000-1);
  	
  	printf("\nVetor Ordenado:\n\n");
  	for (i=0; i < 10000; i++)
  	{
    	printf("%d ", vetor4[i]);
  	}
}
void ParaCemMilValores(int *vetor5){
	int i;
	clock_t Ticks[10];
	clock_t c2, c1;
	printf("Gerando 100.000 valores aleatorios:\n\n");
  	srand(time(NULL));
  
  	vetor5 = (int *) malloc(sizeof (int));
  	for (i=0; i < 100000; i++)
  	{
  		vetor5[i] = rand() % 100;
    	printf("%d ", vetor5[i]);
  	}

	bubble_sort(vetor5, 100000);
  	selecao(vetor5, 100000);
  	insercao(vetor5, 100000);
  	quick(vetor5, 0, 100000-1);
  	mergeSort(vetor5, 0, 100000-1);
  	
  	printf("\nVetor Ordenado:\n\n");
  	for (i=0; i < 100000; i++)
  	{
    	printf("%d ", vetor5[i]);
  	}
}
int main(void)
{
  	int* vetor1, vetor2, vetor3, vetor4, vetor5;
  	int i;
  	
  	ParaDezValores(vetor1);
  	//printf("oi");
 	return 0;
}

