#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int elem;
	struct no *prox;
}no;

typedef struct{
	no *topo;
}pilha;

void criarPilha(pilha *p){
	p->topo = NULL;
}
int pilhaVazia(pilha *p){
	if(p->topo == NULL){
		return 1;
	}else{
		return 0;
	}
}
int pushPilha(pilha *p, int num){
	//Cria um novo nó e um nó auxiliar
	no *novo;
	//Aloca um espaço na memória do tamanho do nó
	novo = malloc(sizeof(no));
	if(!novo)
		return 0;
		
	novo->prox = NULL;
	novo->elem = num;
	
	if(pilhaVazia(p)){
		p->topo = novo;
	}
	
	novo->prox = p->topo;
	novo = p->topo;
	
	return 1;
}
int popPilha(pilha *p){
	no *aux;
	
	if(pilhaVazia(p)){
		return 0;
	}else{
		aux = p->topo;
		p->topo = aux->prox;
		printf("O elemento retirado foi %d\n", aux->elem);
		free(aux); 
	}
	return 1;
}
void exibirPilha(pilha *p){
	no *aux;
	aux = p->topo;
		
	while(aux != NULL)
	{
		printf("%d\n", aux->elem);
		aux = aux->prox;
	}
}
int main(){
	pilha p1;
	int opc, num;
	criarPilha(&p1);
	do{
		printf("Digite \n1 - Push\n2 - Pop\n3 - Exibir a Pilha\n4 - Sair\n");
		scanf("%d",&opc);
	switch(opc)
	{
		case 1:
			printf("Digite o elemento\n");
			scanf("%d", &num);
			if(pushPilha(&p1, num))
				printf("Sucesso\n")	;
			else
				printf("Overflow de memória\n");
			break;
		case 2:
			if(popPilha(&p1))
				printf("Sucesso\n");
			else
				printf("Pilha Vazia\n");
			break;
		case 3:
			exibirPilha(&p1);
			break;
		}
	}
	while(opc!=4);
}
