#include"pilhaDinamica.h"

//percebam que apenas uso as fun��es push e pop da pilha para ler a expressao
//isto por que, a pilha � uma ED que resolve este problema de forma natural,
//pois cada abre parenteses encontrado � empilhado, e cada fecha parenteses encontrado
//um abre � desempilhado procurando assim um casamento (1 fecha precisa de abre correspondente)
//se ao final da leituraa pilha estiver fazia, significa que para cada fecha, um abre estava armazenado na pilha


int main(void)
{
	pilha p1,p2;
	char c,ce;
	
	
	criar(&p1);
	criar(&p2);
	printf("digite a expressao aritmetica ou espa�o para encerrar\n");
	c=getche();
	
	
	while(c!=' ')
	{
		push(c,&p2);//p2 armazena a expressao inteira
		if(c=='(')
		{
			push(c,&p1);//armazena apenas o abre parenteses
			//p1 � usada para empilhar cada abre
			
		}
		if(c==')')
		{
			pop(&p1,&ce);
			//a cada fecha encontrado, um abre � desempilhado.
			//se no fim da inser��o p1 estiver vazia, significa que os parenteses est�o balanceados
		}
		
		c=getche();
		
	}
	
	if(vazia(&p1))
		printf("\nexpressao balanceada\n");
	else
		printf("\nexpressao nao balanceada\n");
	
}

