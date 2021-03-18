#include<stdio.h>
#include"listaDinamica.h"

void andarUmaCasa(lista *l);
void deTrazPraFrente(lista *l);
void somarElementos(lista *l);

int main(){
	lista l1, l2;
	int n, i = 0;
	
	criarLista(&l1);
	criarLista(&l2);
	
	printf("Digite os elementos da primeira lista ou aperte 0 para parar\n");
	while(i < 6){
		scanf("%d", &n);
		inserirListaFim(n, &l1);
		i++;
	}
	andarUmaCasa(&l1);
	deTrazPraFrente(&l1);
	somarElementos(&l1);
}
void andarUmaCasa(lista *l){
	lista l2;
	criarLista(&l2);
	
	noL *aux, *aux1;
	aux1 = l->prim;
	aux = l->prim->prox;
	
	while(aux != NULL){
		inserirListaFim(aux->elem, &l2);
		aux = aux->prox;
	}
	inserirListaFim(aux1->elem, &l2);
	
	imprimirLista(&l2);
}
void deTrazPraFrente(lista *l){
	lista l3;
	criarLista(&l3);
	
	noL *aux;
	aux = l->prim;
	
	while(aux != NULL){
		inserirListaInicio(aux->elem, &l3);
		aux = aux->prox;
	}
	printf("\n");
	imprimirLista(&l3);
}
void somarElementos(lista *l){
	lista l4;
	criarLista(&l4);
	
	int c, h, s;
	
	noL *aux;
	aux = l->prim;
	
	while(!estaVaziaLista(l)){
		c = removerListaInicio(l);
		h = removerListaFim(l);
		s = c + h;
		inserirListaFim(s, &l4);
	}
	imprimirLista(l);
	printf("\n");
	imprimirLista(&l4);
}
