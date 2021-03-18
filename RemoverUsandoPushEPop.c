#include<stdio.h>
#include"pilhaDinamica.h"

void RemoverElemento(pilha *p1, pilha *p2, int c); 

int main(){
	pilha p1, p2;
	int c, s, i = 0;
	
	criarPilha(&p1);
	criarPilha(&p2);
	
	while(i != 5){
		printf("Digite um numero\n");
		scanf("%d", &c);
		push(&p1, c); 
		i++;
	}
	imprimirPilha(&p1);
	printf("Digite o elemento que deseja remover\n");
	scanf("%d", &s);
	RemoverElemento(&p1, &p2, s);
	
}
void RemoverElemento(pilha *p1, pilha *p2, int c){
	int s;
	noP *aux;
	aux = p1->topo;
	while(aux->elemento != c){
		push(p2, aux->elemento);
		aux = aux->ant;
		pop(p1);
	}
	if(aux->elemento == c){
		pop(p1);
	}
	noP *aux2;
	aux2 = p2->topo;
	while(estaVaziaPilha(p2) != 1){
		push(p1, aux2->elemento);
		aux2 = aux2->ant;
		pop(p2);
	}
	printf("\nPilha com o elemento removido\n");
	imprimirPilha(p1);
}
