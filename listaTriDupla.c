#include <stdio.h>
#include <stdlib.h>

typedef struct triangulo{
	int lado1, lado2, lado3;
	struct triangulo *prox;
	struct triangulo *ant;
}triangulo;

typedef struct lista{
	struct triangulo *prim;
}lista;

void criarLista(lista *l){
	l->prim == NULL;
}
int estaVazia(lista *l){
	if(l->prim == NULL){
		return 1;
	}else{
		return 0;
	}
}
int InserirTri(lista *l, int lad1, int lad2, int lad3){
	triangulo *NovoTri;
	
	NovoTri = malloc(sizeof(triangulo));
	
	NovoTri->lado1 = lad1;
	NovoTri->lado2 = lad2;
	NovoTri->lado3 = lad3;
	
	if(estaVazia(l)){
		l->prim = NovoTri;
		NovoTri->prox = NULL;
		NovoTri->ant = NULL;
	}else{
		NovoTri->ant = NULL;
		NovoTri->prox = l->prim;
		l->prim->ant = NovoTri;
		l->prim = NovoTri;
	}
	return 1;
}
int removerTri(lista *l){
	triangulo  *aux, *aux2;
	
	if(estaVazia(l)){
		printf("\nLista Vazia\n");
		return 0;
	}else{
		aux = l->prim;
		if(aux->prox == NULL){
			l->prim = NULL;
			free(aux);
		}else{
			aux2 = l->prim->prox;
			l->prim = aux->prox;
			aux2->ant = NULL;
			free(aux);
		}	
	}
	return 1;
}
int busca(lista *l, int l1, int l2, int l3){
	triangulo *aux;

	if(estaVazia(l)){
		printf("\nLista Vazia\n");
	}else{
		aux = l->prim;
		for(aux = l->prim; aux != NULL; aux = aux->prox){
			if(aux->lado1 == l1 && aux->lado2 == l2 && aux->lado3 == l3){
				return 1;
			}	
		}	
	}
	return 0;
}
void listarTriangulos(lista *l){
	triangulo *aux;
	int n = 1;
	
	if(estaVazia(l)){
		printf("Lista vazia\n");
	}else{
		for(aux = l->prim; aux != NULL; aux = aux->prox){
			printf("%d° - Triangulo\n", n);
			printf(" Lado 1:%d\n", aux->lado1);
			printf(" Lado 2:%d\n", aux->lado2);
			printf(" Lado 3:%d\n", aux->lado3);
			printf("\n\n");
			n++;
		}
	}
}
int main(){
	int opc = 0, c, ladu1, ladu2, ladu3;
	lista l1;
	criarLista(&l1);
	
	while(opc != 5){
		
		printf("Escolha as opcoes abaixo:\n\n|1| Inserir triangulo\n|2| Remover triangulo\n|3| Buscar triangulo\n|4| Listar triangulos\n|5| Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf ("Digite os lados do triangulo:\n");
				scanf ("%d %d %d", &ladu1, &ladu2, &ladu3);
				if (InserirTri(&l1,  ladu1, ladu2, ladu3)){
					printf ("Triangulo inserido com sucesso\n");
				} else {
					printf ("Triangulo não inserido\n");
				}
				break;
			case 2: 
				printf ("Sera removido o primeiro triangulo da lista\n");
				system("pause");
				if (removerTri(&l1)){
					printf ("Triangulo removido com sucesso\n");
				}else {
					printf ("Triangulo não removido\n");
				}
				break;
			case 3:
				printf ("Digite os lados do triangulo:\n");
				scanf ("%d %d %d", &ladu1, &ladu2, &ladu3);
				if (busca(&l1,  ladu1, ladu2, ladu3)){
					printf ("Triangulo encontrado com sucesso\n");
				} else {
					printf ("Triangulo não encontrado\n");
				}
				break;
			case 4:
				listarTriangulos(&l1);
			break;
		}
	}
	printf ("\n\n");
	return 0;
}
