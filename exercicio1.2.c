#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int elem;
	struct no *prox;	
}no;

typedef struct pilha{
	struct no *topo;
}pilha;

typedef struct lista{
	struct no *prim;
}lista;

void criarPilha(pilha *p){
	p->topo = NULL;
}

void criarLista(lista *l){
	l->prim = NULL;
}

int estaVaziaPilha(pilha *p){
	if(p->topo == NULL){
		return 1;
	}else{
		return 0;
	}
}

int estaVaziaLista(lista *l){
	if(l->prim == NULL){
		return 1;
	}else{
		return 0;
	}
}

void push(pilha *p, int elem){
	no *novo;
	
	novo = malloc(sizeof(no));
	
	
	novo->elem = elem;
	novo->prox = NULL;
	
	if(estaVaziaPilha(p)){
		p->topo = novo;
	}else{
		novo->prox = p->topo;
		p->topo = novo;
	}
}

void inserirListaOrdenada(lista *l, int c){
	no *novo, *aux;
	
	novo = malloc(sizeof(no));
	
	novo->elem = c;
	novo->prox = NULL;
	
	if(estaVaziaLista(l)){
		l->prim = novo;
	}else{
		aux = l->prim;
		while(aux->prox != NULL && aux->prox->elem < c){
			aux = aux->prox;
		}
		if(aux == l->prim && aux->elem > c){
			novo->prox = aux;
			l->prim = novo;
		}else if(aux->prox == NULL){
			aux->prox = novo;
		}else{
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
}

void passarListaParaPilha(lista *l, pilha *p){
	no *aux;
	
	aux = l->prim;
	while(aux != NULL){
		push(p, aux->elem);
		aux = aux->prox;
	}
}
int pop(pilha *p){
	no *aux;
	int c;
	
	if(estaVaziaPilha(p)){
		printf("Lista vazia\n");
	}else{
		aux = p->topo;
		p->topo = p->topo->prox;
		c = aux->elem;
		free(aux);
	}
	return c;
}

void exibirPilha(pilha *p){
	no *aux;
	 
	aux = p->topo;
	while(aux != NULL){
		printf("%d\n", aux->elem);
		aux = aux->prox;
	}
}

void verificandoOsPrimos(pilha *p1){
	pilha p3;
	int c, i, prim;
	
	while(!estaVaziaPilha(p1)){
	    prim = 0;
		c = pop(p1);
		for(i = 1; i <= c; i++){
			if(c % i == 0){
				prim++;
			}
		}
		if(prim == 2){
			push(&p3, c);
		}
	}
	printf("\nPrimos das duas pilhas Ordenados: \n");
	exibirPilha(&p3);
}

int main(){
	int c, i = 0, j = 0, num;
	pilha p1;
	lista l1;
	criarLista(&l1);
	criarPilha(&p1);
	
	printf ("Digite a quantidade de elementos que deseja armazenar na primeira pilha\n");
	scanf("%d", &c);
	
	printf ("Digite os elementos da primeira pilha\n");
	while(i < c){
		scanf("%d", &num);
		inserirListaOrdenada(&l1, num);
		i++;
	}
	
	printf ("Digite a quantidade de elementos que deseja armazenar na segunda pilha\n");
	scanf("%d", &c);
	
	printf ("Digite os elementos da segunda pilha\n");
	while(j < c){
		scanf("%d", &num);
		inserirListaOrdenada(&l1, num);
		j++;
	}
	passarListaParaPilha(&l1, &p1);
	verificandoOsPrimos(&p1);
}
