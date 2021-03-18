#include<stdio.h>
#include<string.h>
#include"filaDinamica.h"
#include"pilhaDinamica.h"
#include"lista.h"

void juntarLetrasENumeros(pilha *p, lista *l, fila *f);

int main(){
	lista l;
	fila f;
	pilha p;
	char i = 0, c[1000];

	criarLista(&l);
	criarFila(&f);
	criarPilha(&p);
	
  	gets(c);
  	
  	while(c[i] != '\0'){
  		if(c[i] == '1' || c[i] == '2' || c[i] == '3' || c[i] == '4' || c[i] == '5' || c[i] == '6' || c[i] == '7' || c[i] == '8' || c[i] == '9' || c[i] == '0'){
  			push(&p, c[i]);
		}else{
  			inserirFila(&f, c[i]);
		}
  		i++;
	}
	//imprimirPilha(&p);
  	//imprimirFila(&f);
  	juntarLetrasENumeros(&p, &l, &f);
}
void juntarLetrasENumeros(pilha *p, lista *l, fila *f){
	char c;
	noF *aux;
	aux = f->prim;
	while(estaVaziaFila(f) != 1){
		inserirLista(aux->elemento, l);
		aux = aux->prox;
		retirarFila(f);
	}
	noP *aux2;
	aux2 = p->topo;
	while(estaVaziaPilha(p) != 1){
		inserirLista(aux2->elemento, l);
		aux2 = aux2->ant;
		pop(p);
	}
	imprimirLista(l);
}

