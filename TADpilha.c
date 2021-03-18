#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	char elem;
	struct no *prox;	
}no;

typedef struct pilha{
	struct no *topo;
}pilha;

void criarPilha(pilha *p){
	p->topo = NULL;
}

int estaVazia(pilha *p){
	if(p->topo == NULL){
		return 1;
	}else{
		return 0;
	}
}

int push(pilha *p, char elem){
	no *novo;
	
	novo = malloc(sizeof(no));
	
	
	novo->elem = elem;
	novo->prox = NULL;
	
	if(estaVazia(p)){
		p->topo = novo;
	}else{
		novo->prox = p->topo;
		p->topo = novo;
	}
	return 1;
}

char pop(pilha *p){
	no *aux;
	char c;
	
	if(estaVazia(p)){
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
		printf("%c", aux->elem);
		aux = aux->prox;
	}
}
void ondeAMagicaAcontece(pilha *p2){
	no *aux;
	pilha p1;
	char c;
	
	printf ("\n\n");
	
	pop(p2);
	printf("\nPilha normal:\n");
	exibirPilha(p2);
	
	while(!estaVazia(p2)){
		c = pop(p2);
		push(&p1, c);
	}
	
	printf ("\n\n");
	printf("\nPilha invertida:\n");
	exibirPilha(&p1);
	
}
int main(){
	pilha p2;
	criarPilha(&p2);
	char c;

	printf ("Digite a expressao ou espaco para parar\n");
	while(c != ' '){
		c = getche();
		push(&p2, c);
	}
	
	ondeAMagicaAcontece(&p2);
	
	printf ("\n\n");
	return 0;
}



