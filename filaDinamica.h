#include<stdio.h>
#include<stdlib.h>

typedef struct noF{
	int elemento;
	struct noF *prox;
}noF;

typedef struct{
	noF *prim;
	noF *ult;
}fila;

void criarFila(fila *f){
	f->prim = NULL;
	f->ult = NULL;
}
int estaVaziaFila(fila *f){
	if(f->prim == NULL){
		return 1;
	}else{
		return 0;
	}
}
int inserirFila(fila *f, int elem){
	noF *novo;
	
	novo = malloc(sizeof(noF));
	novo->prox = NULL;
	novo->elemento = elem;
	
	if(estaVaziaFila(f)){
		f->prim = novo;
		f->ult = novo;
	}else{
		f->ult->prox = novo;
		f->ult = novo;
	}
	return 1;
}
char retirarFila(fila *f){
	noF *aux;
	int c;
	
	if(estaVaziaFila(f)){
		return 0;
	}else{
		aux = f->prim;
		f->prim = f->prim->prox;
		c = aux->elemento;
		free(aux);
	}
	return c;
}
void imprimirFila(fila *f){
	noF *aux;
	
	if(estaVaziaFila(f)){
		printf("\nFila Vazia");
	}else{
		aux = f->prim;
		while(aux != NULL){
			printf("%d", aux->elemento);
			aux = aux->prox;
		}
	}
}
void BuscaFila(fila *f, char elem){
	noF *aux;
	
	aux = f->prim;
	while((aux != NULL) && (aux->elemento != elem)){
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("\nElemento nao encontrado.");
	}else{
		printf("\nElemento encontrado.");
	}
}
