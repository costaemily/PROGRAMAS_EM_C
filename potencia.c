#include<stdio.h>

int potencia(int base, int expoente);

int main(){
	int base, expoente, pot;
	
	printf("Digite a base\n");
	scanf("%d", &base);
	
	printf("Digite o expoente\n");
	scanf("%d", &expoente);
	
	printf("\n%d pot %d = ", base, expoente);
	printf("%d", potencia(base, expoente));
	
}
int potencia(int base, int expoente){
	if(expoente == 0){
		return 1;
	}else{
		return (base * potencia(base, expoente - 1));
	}
}
