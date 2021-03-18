#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, j, N, M;
	/*
	int matriz[10][10];
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			matriz[i][j] = i;
		}
	}
	
	for(i = 0; i < 10; i++){
		printf("\n");
		for(j = 0; j < 10; j++){
			printf("%d ", matriz[i][j]);
		}
	}
	*/
	
	scanf("%d %d", &N, &M);
	
	int matriz[N][M];
	
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			scanf("%d", &matriz[i][j]);
			//printf("%d ", matriz[i][j]);
		}
	}
	
	printf("\n");
	for(i = 1; i <= N; i++){
		printf("\n");
		for(j = 1; j <= M; j++){
			printf("%d ", matriz[i][j]);
		}
	}
	int lZero = 0, linhaZero = 0;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			if(matriz[i][j] == 0){
					lZero++;
			}
			if(j == M){
				if(lZero == M){
					lZero = 0;
					printf("\nLinha %d so possui 0.\n", i);
					linhaZero = 1;
				}else{ 
					lZero = 0;
				}
			}	
		}
	}
}
