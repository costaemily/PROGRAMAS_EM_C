#include<stdio.h>
#include<stdlib.h>

typedef struct noP{
	char elemento;
	struct noP *prox;
	struct noP *ant;
}noP;

typedef struct{
	noP *topo;
}pilha;

void criarPilha(pilha *p){
	p->topo = NULL;
}
int estaVaziaPilha(pilha *p){
	if(p->topo == NULL){
		return 1;
	}else{
		return 0;
	}
}
void push(pilha *p, char elem){
	noP *novo;
	
	novo = malloc(sizeof(noP));
	
	novo->prox = NULL;
	novo->ant = NULL;
	novo->elemento = elem;
	
	if(estaVaziaPilha(p)){
		p->topo = novo;
	}else{
		p->topo->prox = novo;
		novo->ant = p->topo;
		p->topo = novo;
	}
}
char pop(pilha *p){
	noP *aux1;
	char c;
	
	if(estaVaziaPilha(p)){
		return 0;
	}else{
		aux1 = p->topo;
		p->topo = p->topo->ant;
		c = aux1->elemento;
		free(aux1);
	}
	return c;
}
void imprimirPilha(pilha *p){
	noP *aux;
	
	if(estaVaziaPilha(p)){
		printf("\nPilha vazia.");
	}else{
		aux = p->topo;
		while(aux != NULL){
			printf("%c", aux->elemento);
			aux = aux->ant;
			printf("\n");
		}
	}
}
void BuscaPilha(pilha *p, char elem){
	noP *aux;
	
	aux = p->topo;
	while((aux != NULL) && (aux->elemento != elem)){
		aux = aux->ant;
	}
	if(aux == NULL){
		printf("\nElemento nao encontrado.");
	}else{
		printf("\nElemento encontrado.");
	}
}
