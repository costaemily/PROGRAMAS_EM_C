#include<stdio.h>
#include<string.h>
#include"filaDinamica.h"
#include"pilhaDinamica.h"
#include"lista.h"

void converterBinario(int num, lista *l);

int main(){
	int num;
	lista l;
	
	criarLista(&l);
	
	scanf("%d", &num);
	converterBinario(num, &l);
	imprimirLista(&l);
}
void converterBinario(int num, lista *l){
	if(num == 0){
		return;
	}else{
		int c;
		c = num % 2;
		inserirLista(c, l);
		return converterBinario(num/2, l);	
	}
}
