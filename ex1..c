#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	
	char ex;
	struct no *prox;

}no;  

typedef struct pilha{
	struct no *topo;
}pilha;

void criar(pilha *p);
void push(char c, pilha *p);
void pop(pilha *p);
void imprimir(pilha *p);
int vazia(pilha *p);

int vazia(pilha *p){
	if(p->topo == NULL)
	{
		return 1;
	}
	else{
		return 0;
	}
}

void criar(pilha *p){
	p->topo = NULL;
}

int main()
{
	int op,i;
	char c;
	
	pilha p1;
	criar(&p1);


	do{	
	printf("digite:\n 1- para inserir\n 2- para desempilhar\n 3- para imprimir\n 4- sair\n");
	scanf("%d",&op);
	switch(op)
		{
			case 1:
			do{
			c = getche();
			push(c,&p1);
		
			}while(c != ' ');
	
			break;
		
			case 2:
			pop(&p1);
			break;
			
			case 3:
				imprimir(&p1);
				break;	
		}
	}while(op != 4);
}


void push(char c, pilha *p){
	
	no *novo;
	
	novo = malloc(sizeof(no));
	novo->ex = c;
	novo->prox = NULL;
	
	if(vazia(p))
	{
		p->topo = novo;
		printf("nao possui elem");// para verificar se quando ela esta vazia topo eh igual a novo
	}
	else{
	novo->prox = p->topo;
	p->topo = novo;
	printf("possui elem");// para verificar se ja estive elemento ele esta entrando no proximo
	}
}
// problema: quando esta vazia ele esta entrando como se n estivesse vazia
void pop(pilha *p)
{
	no *aux;
	
	aux = p->topo;
	
	p->topo = p->topo->prox;
	
	free(aux);
}

void imprimir(pilha *p){
	
	no *aux;
	aux = p->topo;
	while(aux != NULL){
		printf("%c\n",aux->ex);
		aux = aux->prox;
	}	
}
