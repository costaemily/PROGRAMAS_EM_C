#include<stdio.h>
#include"pilhaDinamica.h"

int inverterEVerificar(pilha *p1, pilha *p2);

int main(){
	pilha p1, p2;
	char c;
	
	criarPilha(&p1);
	criarPilha(&p2);
	
	printf("Digite os caracteres ou espaco para parar\n");
	c = getche();
	while(c != ' '){
		push(&p1, c);
		c = getche();
	}
	if(inverterEVerificar(&p1, &p2)){
		printf("\nEh do tipo xCy\n");
	}else{
		printf("\nNao eh do tipo xCy\n");
	}
}
int inverterEVerificar(pilha *p1, pilha *p2){
	noP *aux;
	char s;
	aux = p1->topo;
	while(aux != NULL){
		push(p2, aux->elemento);
		aux = aux->ant;
	}
	char c, l;
	noP *aux1;
	aux1 = p1->topo;
	while(aux1 != NULL){
		l = pop(p1);
		c = pop(p2);
		if(l != c){
			return 0;
		}
		aux1 = aux1->ant;
	}
	return 1;
}
