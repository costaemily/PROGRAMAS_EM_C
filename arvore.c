#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	char elem;
	struct no *filho;
	struct no *prox;
}no;

typedef struct arvore{
	struct no *raiz;
	int altura;
}arvore;

void criarArvore(arvore *a){
	a->raiz = NULL;
	a->altura = 0;
}
int estaVazia(arvore *a){
	if(a->raiz == NULL){
		return 1;
	}else{
		return 0;
	}
}
no* busca(arvore *a, char pai){
	no *aux;
	aux = a->raiz;
	if (estaVazia(a)){
		printf ("\nNão encontrado. Lista Vazia\n");
	}else{
		if(aux->elem == pai){
			return aux;
		}else{
			aux = aux->filho;
			while(aux != NULL && aux->elem != pai){
				aux = aux->prox;
			}
		}
	}
}
void inserir(arvore *a, char pai){
	no *novo, *aux;
	
	novo = malloc(sizeof(no));
	
	novo->filho = NULL;
	novo->prox = NULL;
	
	if(estaVazia(a)){
		a->raiz = novo;
	}else{
		aux = busca(a, pai);
		if(a->raiz->elem == pai){
			a->raiz->filho = novo;
		}else{
			if(aux == NULL){
				printf("\nElemento nao encontrado\n");
			}else{
				aux->filho = novo;
			}
		}
	}
}

void imprimir(arvore *a){
	no *aux;
	aux = a->raiz;
	
	
}
int main(){
	int opc;
	arvore a;
	
	criarArvore(&a);
	
	while(opc != 2){
		
	}
}
