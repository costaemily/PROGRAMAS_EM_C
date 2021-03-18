#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pessoa{
	char Nome[50];
	int idade;
	int prioridade;
	struct pessoa *prio;
	struct pessoa *prox;
	struct pessoa *ant;
}pessoa;

typedef struct lista{
	struct pessoa *prim;
	struct pessoa *ult;
	struct pessoa *prior;
}lista;

void criarLista(lista *l){
	l->prim = NULL;
	l->ult = NULL;
	l->prior = NULL;
}
int estaVaziaLista(lista *l){
	if(l->prim == NULL){
		return 1;
	}else{
		return 0;
	}
}

int estaVazia(lista *l){
	if(l->prior == NULL){
		return 1;
	}else{
		return 0;
	}
}
void inserirComPrio(lista *l, char *nome, int idade){
	pessoa *NovaPes;
	pessoa *aux;
	
	NovaPes = malloc(sizeof(pessoa));
	
	strcpy(NovaPes->Nome, nome);
	NovaPes->idade = idade;
	NovaPes->prox = NULL;
	NovaPes->ant = NULL;
	NovaPes->prio = NULL;
	
	if(NovaPes->idade >= 60){
		if(estaVaziaLista(l)){
			l->prim = NovaPes;
			l->ult = NovaPes;
			l->prior = NovaPes;
			NovaPes->prioridade = 1;
		}else{
			if(l->prior == NULL){
				l->prior = NovaPes;
				l->ult->prox = NovaPes;
				NovaPes->ant = l->ult;
				l->ult = NovaPes;
				NovaPes->prioridade = 1;
			}else{
				aux = l->prior;
				while(aux->prio != NULL){
					aux = aux->prio;
				}
				if(aux->prio == NULL){
					aux->prio = NovaPes;
				}
				l->ult->prox = NovaPes;
				NovaPes->ant = l->ult;
				l->ult = NovaPes;
				NovaPes->prioridade = 1;
			}
		}
	}else{
		if(estaVaziaLista(l)){
			l->prim = NovaPes;
			l->ult = NovaPes;
			NovaPes->prioridade = 0;
		}else{
			l->ult->prox = NovaPes;
			NovaPes->ant = l->ult;
			l->ult = NovaPes;
			NovaPes->prioridade = 0;
		}
	}
}

void retirarListaPrio(lista *l){
	pessoa *aux1, *aux2, *aux3, *aux4;
	
	if(estaVazia(l)){
		printf("\nFila Vazia\n");
	}else{
		aux1 = l->prior;
		if(aux1 == l->prim){
			l->prim = l->prim->prox;
			l->prior = l->prior->prio;
			free(aux1);
		}else if(aux1 == l->ult){
			 aux2 = l->ult->ant;
			 aux2->prox = NULL;
			 l->ult = aux2;
			 l->prior = NULL;
			 free(aux1);
		}else{
			aux2 = aux1->ant;
			aux3 = aux1->prox;
			aux2->prox = aux3;
			aux3->ant = aux2;
			l->prior = l->prior->prio;
			free(aux1);
		}
	}
}
void retirarListaNormal(lista *l){
	pessoa *aux1, *aux2, *aux3;
	
	aux1 = l->prim;
	while(aux1->prioridade == 1){
		aux1 = aux1->prox;
	}
	if(aux1 == l->prim){
		l->prim = l->prim->prox;
		free(aux1);
	}else if(aux1 ==  l->ult){
		aux2 = l->ult->ant;
		aux2->prox = NULL;
		l->ult = aux2;
		free(aux1);
	}else{
		aux2 = aux1->ant;
		aux3 = aux1->prox;
		aux2->prox = aux3;
		aux3->ant = aux2;
		free(aux1);
	}
}
void exibirFila(lista *l){
    printf("\nFila normal:\n");
	pessoa *aux;
	
	if(estaVaziaLista(l)){
		printf("\nFila Vazia\n");
	}else{
		aux = l->prim;
		while(aux != NULL){
			printf("%s\n", aux->Nome);
			printf("%d\n", aux->idade);
			aux = aux->prox;
			printf("\n");
		}
	}
}

void exibirPrio(lista *l){
	printf("\nFila preferencial:\n");
	pessoa *aux;
	
	if(estaVazia(l)){
		printf("\nFila Vazia\n");
	}else{
		aux = l->prior;
		while(aux != NULL){
			printf("%s\n", aux->Nome);
			printf("%d\n", aux->idade);
			aux = aux->prio;
			printf("\n");
		}
	}
}
int main(){
	char nome[50];
	int opc = 0, idade, filaPre = 0;
	lista l1;
	criarLista(&l1);
	
	while(opc != 4){
		
		printf("Escolha as opcoes abaixo:\n\n|1| Inserir fila\n|2| Exibir Fila\n|3| Atender a fila\n|4| Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf ("Digite o nome do cliente:\n");
				scanf ("%s", &nome);
				printf ("Digite a idade do cliente:\n");
				scanf ("%d", &idade);
				inserirComPrio(&l1, nome, idade);
			break;
			case 2: 
				exibirFila(&l1);
				exibirPrio(&l1);
			break;
			case 3:
				if(filaPre < 2){
					if(!estaVazia(&l1)){
						printf("\nVoce atendeu uma pessoa da fila preferencial\n");
						retirarListaPrio(&l1);
						filaPre++;
					}else{
						if(!estaVaziaLista(&l1)){
							printf("\nVoce atendeu uma pessoa da fila\n");
							retirarListaNormal(&l1);
						}else{
							printf("\nFila vazia\n");
						}
					}
				}else{
					if(!estaVaziaLista(&l1)){
						printf("\nVoce atendeu uma pessoa da fila\n");
						retirarListaNormal(&l1);
						filaPre = 0;
					}else{
						printf("\nFila vazia\n");
						filaPre = 0;
					}
				}
			break;
		}
	}
	return 0;
}
