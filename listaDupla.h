#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int elem;
	struct no *prox;
	struct no *ant;
}noD;//estrutura de um nó de uma lista duplamente encadeada

typedef struct 
{
	noD *prim;
}listaD;


//declaração de duas variáveis do tipo lista

void criar(listaD *l);//recebe uma lista
int inserir(int c, listaD *l);
int remover(listaD *l,int *e);
int vazia(listaD *l);
void imprimir(listaD *l);
noD* busca(listaD *l, int elem);

void criar(listaD *l)
{
	l->prim = NULL;
	
}

int inserir(int c, listaD *l)
{//insere numeros em uma lista duplamente encadeada ordenada
	
	noD *novo,*aux;
	
	novo = malloc(sizeof (noD));
	
	if(!novo)
		return 0;
	
	novo->prox=NULL;
	novo->ant = NULL;
	novo->elem = c;
	
	
	if(vazia(l))
	{
		l->prim = novo;//o no novo é o primeiro da lista
		
	}
	else
	{
		aux = l->prim;
		while(aux->prox != NULL && aux->prox->elem<c )
		{
			aux = aux->prox;
		}
		
		if(aux == l->prim && aux->elem > c)//para o caso de inserção no início da lista
		{
			novo->prox = aux;
			l->prim = novo;
				
		}
		else
		{
			if(aux->prox == NULL)//inserção no fim da lista
			{
				novo->ant = aux;
				aux->prox = novo;
			}
			else
			{//para inserção entre dois nós
				novo->prox = aux->prox;
				novo->ant = aux;
				aux->prox->ant = novo;
				aux->prox = novo;		
			}
		
		}
		
				
	}
	
	return 1;
}

int vazia(listaD *l)
{
	if(l->prim == NULL)//se o ponteiro para inicia da lista estiver nulo
		return 1;
	else
		return 0;
}
 int remover(listaD *l,int *e)
 {
 	noD *aux;
 	
 	
 	aux = busca(l,*e);//a função busca retorna um ponteiro para o no que contém o elemento encontrado
 	
 	
 	
 	if(vazia(l) || !aux)//não acontece a remoção se a lista estiver vazia ou o nó não for encontrado
 		return 0;
 	else
 	{
 		if(aux!=l->prim && aux->prox !=NULL)
 		{//remoção no meio de uma lista com mais de um nó
 			
			*e= aux->elem;//o valor da variavel apontada por e recebe o conteudo do elemento que será removido
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
			free(aux);
		
		}
		else
		{
			if(aux == l->prim && aux->prox != NULL)//remoção no ínicio de uma lista
			{//com mais de um nó
				*e= aux->elem;//o valor da variavel apontada por e recebe o conteudo do elemento que será removido
				aux->prox->ant = NULL;
				l->prim = aux->prox;
				free(aux);
			}
			else
			{
				if(aux == l->prim && aux->prox == NULL)
				{//remoção no início de uma lista com apenas um nó
					l->prim = NULL;
					free(aux);
				}
				
				else
				{//remoção no fim da lista
					*e= aux->elem;
					aux->ant->prox = NULL;
					free(aux);
				}
			}
			
		}
 		
	
	}
 	
 	return 1;
}

void imprimir(listaD *l)
{
	noD *aux;
	
	if(vazia(l))
		printf("Lista vazia\n");
	
	else
	{
		aux=l->prim;
		while(aux!=NULL)
		{
			printf("%d\n",aux->elem);
			aux = aux->prox;
		}
	}
}

noD* busca(listaD *l, int elem)
{
	
	noD *aux;
	
	aux = l->prim;
	
	while(( aux!=NULL) && (aux->elem != elem ))
	{
		aux = aux->prox;
	}
	
	if(aux == NULL)
	{
		printf("Elemento não enccontrado\n");
		
	}
	return aux;
		
	
}

