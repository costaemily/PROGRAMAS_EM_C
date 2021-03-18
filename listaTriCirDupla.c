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
	l->prim = NULL;
}
int estaVazia(lista *l){
	if(l->prim == NULL){
		return 1;
	}else{
		return 0;
	}
}
int InserirTri(lista *l, int lad1, int lad2, int lad3){
	triangulo *NovoTri, *aux;
	
	NovoTri = malloc(sizeof(triangulo));
	
	NovoTri->lado1 = lad1;
	NovoTri->lado2 = lad2;
	NovoTri->lado3 = lad3;
	
	if(estaVazia(l)){
		l->prim = NovoTri;
		l->prim->prox = NovoTri;
		l->prim->ant = NovoTri;
	}else{
		aux = l->prim;
		aux = aux->ant;
		aux->prox = NovoTri;
		NovoTri->ant = aux;
		NovoTri->prox = l->prim;
		l->prim->ant = NovoTri;
		l->prim = NovoTri;
	}
	return 1;
}
triangulo* busca(lista *l, int l1, int l2, int l3){
	triangulo *aux;
    
    if(estaVazia(l)){
		printf("Lista vazia\n");
	}else{
	    aux = l->prim;
	    for(aux = l->prim; aux->prox != l->prim; aux = aux->prox){
		    if(aux->lado1 == l1 && aux->lado2 == l2 && aux->lado3 == l3){
			    return aux;
		    }	
	    }
	    if(aux->lado1 == l1 && aux->lado2 == l2 && aux->lado3 == l3){
		    return aux;
	    }
	}
	return aux = NULL;
}
int removerTri(lista *l, int l1, int l2, int l3){
	triangulo  *aux, *aux2, *aux3;
	triangulo *triBusca;
	
	triBusca = busca(l, l1, l2, l3);
	if(triBusca == NULL){
	    return 0;
	}else{
	    if(triBusca == l->prim){
		    aux = l->prim;
		    if(aux->prox == l->prim){
			    l->prim = NULL;
			    free(aux);
		    }else{
			    aux2 = l->prim->prox;
			    aux3 = l->prim->ant;
			    aux2->ant = aux3;
			    aux3->prox = aux2;
			    l->prim = aux2;
			    free(aux);
		    }
	    }else if(triBusca->ant == l->prim){
		    aux = l->prim;
		    aux2 = triBusca->prox;
		    aux3 = triBusca;
		    aux->prox = aux2;
		    aux2->ant = aux;
		    free(aux3);
		
	    }else if(triBusca->prox == l->prim){
		    aux = l->prim;
		    aux2 = triBusca->ant;
		    aux3 = triBusca;
		    aux2->prox = aux;
		    aux->ant = aux2;
		    free(aux3);
	    }else{
		    aux = triBusca;
		    aux2 = triBusca->prox;
		    aux3 = triBusca->ant;
		    aux3->prox = aux2;
		    aux2->ant = aux3;
		    free(aux);
	    }
	}
	return 1;	
}

void listarTriangulos(lista *l){
	triangulo *aux;
	int n = 1;
	
	if(estaVazia(l)){
		printf("Lista vazia\n");
	}else{
		for(aux = l->prim; aux->prox != l->prim; aux = aux->prox){
			printf("%d° - Triangulo\n", n);
			printf(" Lado 1:%d\n", aux->lado1);
			printf(" Lado 2:%d\n", aux->lado2);
			printf(" Lado 3:%d\n", aux->lado3);
			printf("\n\n");
			n++;
		}
			printf("%d° - Triangulo\n", n);
			printf(" Lado 1:%d\n", aux->lado1);
			printf(" Lado 2:%d\n", aux->lado2);
			printf(" Lado 3:%d\n", aux->lado3);
			printf("\n\n");
	}
}
int main(){
	int opc = 0, c, ladu1, ladu2, ladu3;
	lista l1;
	triangulo *noBusca;
	
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
				printf ("Digite os lados do triangulo que deseja remover:\n");
				scanf ("%d %d %d", &ladu1, &ladu2, &ladu3);
				if (removerTri(&l1, ladu1, ladu2, ladu3)){
					printf ("Triangulo removido com sucesso\n");
				}else {
					printf ("Triangulo não encontrado\n");
				}
				break;
			case 3:
				printf ("Digite os lados do triangulo:\n");
				scanf ("%d %d %d", &ladu1, &ladu2, &ladu3);
				noBusca = busca(&l1, ladu1, ladu2, ladu3);
				if (noBusca == NULL){
				    printf ("Triangulo não encontrado\n");
				}else{
				    printf ("Triangulo encontrado com sucesso\n");
					printf(" Lado 1:%d\n", noBusca->lado1);
					printf(" Lado 2:%d\n", noBusca->lado2);
					printf(" Lado 3:%d\n", noBusca->lado3);
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

