#include<stdio.h>
#include"pilhaDinamica.h"

void inverterValores(pilha *p1, pilha *p2);

int main(){
	pilha p1, p2;
	int i = 0, c;
	criarPilha(&p1);
	criarPilha(&p2);
	
	while(i < 5){
		printf("Digite o elemento\n");
		scanf("%d", &c);
		push(&p1, c);
		i++;
	}
	inverterValores(&p1, &p2);
}
void inverterValores(pilha *p1, pilha *p2){
	noP *aux;
	aux = p1->topo;
	while(estaVaziaPilha(p1) != 1){
		push(p2, aux->elemento);
		aux = aux->ant;
		pop(p1);
	}
	imprimirPilha(p2);
}
