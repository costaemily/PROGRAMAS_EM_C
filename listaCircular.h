#include<stdio.h>
#include<stdlib.h>

//vamos assumir que o ponteiro ult aponta para o ultimo elemento da lista
//a inser��o sempre acontecer� no fim da lista, logo, uma posi��o posterior a ult, o que facilita
//a inser��o j� que temos uma lista circular simplesmente encadeada
typedef struct no
{
	int elem;
	struct no *prox;
}no;

typedef struct 
{
	no *ult;
}listaC;


void criar(listaC *l);//recebe uma lista circular e cria uma lista vazia
int inserir(int c, listaC *l);//insere o elemento c na lista circular l
int remover(listaC *l,int *e);//remove o elemento e da lista circular l, retornando o elemento a ser
//eliminado em e, ou null caso n�o o encontre
int vazia(listaC *l);//retorna 1 se a lista estiver vazia, 0 caso contr�rio
void imprimir(listaC *l);//imprime todos os elementos da lista l

void criar(listaC *l)
{
	l->ult = NULL;
}

int inserir(int c, listaC *l)
{//inser��o ordenada
	
	no *novo,*aux;
	
	novo = malloc(sizeof (no));//aloca��o de mem�ria para novo n�
	
	if(!novo)
		return 0;
	
	novo->prox=NULL;//inicializa��o do novo n�
	novo->elem = c;
	
	
	if(vazia(l))
	{
		l->ult = novo;//o no novo � o primeiro da lista
		l->ult->prox = l->ult;//o campo prox de prim aponta para ele mesmo, o que caracteriza uma lista encadeada circular
		
	}
	else
	{
		//inser��o ap�s o n� apontado pelo ponteiro ult, e atualiza��o do ponteiro ult, o qual passa a apontar para o novo n� inserido

		//inser��o na frente do ponteiro ult
		novo->prox = l->ult->prox;//o campo prox de novo aponta para o primeiro no da lista, o qual
		//est� na frente de ult
		l->ult->prox = novo;//o campo prox do ult aponta para o novo no inserido
		l->ult = novo;//o novo no inserido ser� agora o ultimo no da lista
		
	}
	
	return 1;
}

int vazia(listaC *l)
{
	if(l->ult == NULL)//se o ponteiro para inicia da lista estiver nulo
		return 1;
	else
		return 0;
}
 int remover(listaC *l,int *e)
 {
 	no *aux1,*aux2;
 	
 	if(vazia(l))
 		return 0;
 	else
 	{
 		aux1=l->ult->prox;//aux aponta para primeiro da lista
 		aux2 = l->ult;//aux2 aponta para o ultimo
 		while((aux1!=l->ult) && (aux1->elem!=*e))
 		{	
 			
 			aux2 = aux1;
 			aux1 = aux1->prox;	
		}
		
		if(aux1->elem == *e)//o elemento foi encontrado em algum no da lista
		{
			if(aux1!=l->ult)//posso deletar o no aux1 sem me preocupar em atualizar o ponteiro ult
			{
				aux2->prox = aux1->prox;
				free(aux1);
			}
			else//o no a ser removido � o ponteiro ult, logo ele precisa ser atualizado
			{//antes de ser deletar para n�o perdermos o acesso a lista
				if(aux2==aux1)
				{//antes, verificamos se existe apenas um no na lista, o qual ser� removido
					free(aux1);
					l->ult = NULL;//a lista ficou vazia
				}
				else
				{ //existe mais de um no na lista
					aux2->prox = aux1->prox;
					l->ult = aux2;//o ponteiro ult volta um n� na lista
					free(aux1);
				}
				
			}
			return 1;	
		}
		else
		{
			printf("No n�o encontrado\n");
				
			return 0;
				
		}
		
		
	}
 	
 	
}

void imprimir(listaC *l)
{
	no *aux;
	
	if(vazia(l))
		printf("Lista vazia\n");
	
	else
	{
		aux=l->ult->prox;
		while(aux!=l->ult)
		{
			printf("%d\n",aux->elem);
			aux = aux->prox;
		}
		printf("%d\n",aux->elem);
		
	}
}
