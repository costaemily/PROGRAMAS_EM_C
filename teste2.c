#include<stdio.h>
#include"listaDupla.h"

int main(){
	listaD l1, l2;
	int n, c, i = 0, j = 0;
	
	criar(&l1);
	criar(&l2);
	
	printf("Digite os elementos da primeira lista ou aperte 0 para parar\n");
	while(i < 6){
		scanf("%d", &n);
		inserir(n, &l1);
		i++;
	}
	
	printf("Digite os elementos da sugunda lista ou aperte 0 para parar\n");
	while(i < 6){
		scanf("%d", &c);
		inserir(c, &l2);
		j++;
	}
}
void uniao(listaD *l1, listaD *l2){
	listaD l3, l4;
	int c, s;
	criar(&l4);
	criar(&l3);
	no *aux, *aux2, *aux3;
	int c, s;
	
	aux = l1->prim;
	aux2 = l2->prim;
	aux3 = l3->prim;
	
	while(aux != NULL){
		inserir(aux->elem, &l3);
	}
	
	while(aux2 != NULL){
		c = aux2->elem;
		while(aux3 != NULL){
			s = aux3->elem;
			if(c != s){
				aux3 = aux3->prox;	
			}else{
				inserir(s, &l4);
			}
		}
	}
}
