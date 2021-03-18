#include<stdio.h>
#include<string.h>
#include"filaDinamica.h"
#include"pilhaDinamica.h"
#include"lista.h"

void inverter(pilha *p1, pilha *p2);
void verificarIgual(pilha *p1, pilha *p2);

int main(){
	char c;
	pilha p, p2;
	
	criarPilha(&p);
	criarPilha(&p2);
	
	while(c != ' '){
		c = getche();
		push(&p, c);
	}

	inverter(&p, &p2);
	verificarIgual(&p, &p2);
}
void inverter(pilha *p1, pilha *p2){
	noP *aux;
	aux = p1->topo;
	while(aux != NULL){
		push(p2, aux->elemento);
		aux = aux->ant;
	}
	imprimirPilha(p1);
	imprimirPilha(p2);
}
void verificarIgual(pilha *p1, pilha *p2){
	noP *aux2, *aux3;
	aux2 = p1->topo;
	aux3 = p2->topo;
	while(aux2 != NULL && aux3 != NULL){
		if(aux2->elemento == aux3->elemento){
			aux2 = aux2->ant;
			aux3 = aux3->ant;
		}else{
			prinf("\nNao sao iguais\n");
			break;
		}
	}
	if(aux2 == NULL && aux3 == NULL){
		prinf("\nSao iguais\n");
	}
}
