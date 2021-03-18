#include<stdio.h>
#include"filaDinamica.h"
#include"pilhaDinamica.h"
#include"lista.h"

void ConverterBinario(pilha *p, lista *l);

int main(){
	pilha p;
	lista l, l2;
	int num;
	
	criarLista(&l);
	criarPilha(&p);
	
	scanf("%d", &num);
	push(&p, num);
	ConverterBinario(&p, &l);

}
void ConverterBinario(pilha *p, lista *l){
	int c, s;
	noP *aux1;
	noL *aux;
	aux = l->prim;
	s = p->topo->elemento;
	while(s != 0){
		c = s % 2;
		//printf("\n%d", c);
		inserirLista(c , l);
		s = s / 2;
	}
	imprimirLista(l);
}
