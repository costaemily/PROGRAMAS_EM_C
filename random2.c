#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()
int main(void)
{
  int i;
  
  printf("Gerando 10 valores aleatorios:\n\n");
  
  srand(time(NULL));
  
  for (i=0; i < 10; i++)
  {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d ", rand() % 100);
  }
  
  getch();
  return 0;
}
