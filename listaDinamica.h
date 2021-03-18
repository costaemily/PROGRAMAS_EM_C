#include<stdio.h>
#include<stdlib.h>

typedef struct noL
{
	int elem;
	struct noL *prox;
}noL;

typedef struct 
{
	noL *prim;
}lista;

void criarLista(lista *l)
{
	l->prim = NULL;
}

int inserirListaInicio(int c, lista *l)
{
	noL *novo;
	
	novo = malloc(sizeof (noL));
	
	if(!novo){
		return 0;
	}
	
	novo->prox=NULL;
	novo->elem = c;
		
	if(estaVaziaLista(l))
	{
		l->prim = novo;
		
	}
	else
	{
		novo->prox = l->prim;
		l->prim = novo;
	}
	return 1;
}
int inserirListaFim(int c, lista *l)
{
	noL *novo;
	
	novo = malloc(sizeof (noL));
	
	if(!novo){
		return 0;
	}
	
	novo->prox=NULL;
	novo->elem = c;
		
	if(estaVaziaLista(l))
	{
		l->prim = novo;
		
	}
	else
	{
		noL *aux;
		aux = l->prim;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		if(aux->prox == NULL){
			aux->prox = novo;
		}
	}
	return 1;
}

int estaVaziaLista(lista *l)
{
	if(l->prim == NULL)
		return 1;
	else
		return 0;
}
int removerListaInicio(lista *l)
 {
 	int c;
 	noL *aux;
 	
 	if(estaVaziaLista(l))
 		return 0;
 	else
 	{
 		aux = l->prim;
		c = aux->elem;
		l->prim = l->prim->prox;	
		free(aux);
	}
 	
 	return c;
}
int removerListaFim(lista *l)
 {
 	int c;
 	noL *aux, *aux2;
 	
 	if(estaVaziaLista(l))
 		return 0;
 	else
 	{
		aux = l->prim;
		aux2 = l->prim->prox;
		while(aux2->prox != NULL){
			aux = aux->prox;
			aux2 = aux2->prox;
		}
		if(aux2->prox == NULL){
			aux->prox = NULL;
			c = aux2->elem;
		}	
		free(aux);
	}
 	
 	return c;
}
void imprimirLista(lista *l)
{
	noL *aux;
	
	if(estaVaziaLista(l))
		printf("Lista vazia\n");
	
	else
	{
		aux=l->prim;
		while(aux!=NULL)
		{
			printf("%d ",aux->elem);
			aux = aux->prox;
		}
	}
}
int BuscaLista(lista *l, int elem){
	noL *aux;
	
	aux = l->prim;
	while((aux != NULL) && (aux->elem != elem)){
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("\nElemento nao encontrado.");
	}
	return aux->elem;
}
