#include <math.h>
#include <stdio.h>
#include <time.h>

int primofast(int numero) {
	int i;
	if (numero == 2)
		return 1;
	if (numero % 2) {
		for (i = 3; i < numero / i + 1; i += 2) {
			if (numero % i == 0)
				return 0;
		}
		return 1;
	}
}

int ehprimo(int numero) {
	int i;
  int limite = (int)sqrt(numero);
	for (i = 2; limite ; i++) {
		if (numero % i == 0)
			return 0;
	}
	return 1;
}

int coisa() {
	int w = 1, g, div ;
	while (w < 10000 ) {
		div = 0;
		g = 1;
		while (g <= w) {
			if (w % g == 0) {
				div = div + 1;
			}
			g = g + 1;
		}
		if (div == 2 && w > 1) {
		}
		w = w + 1;
	}
}


int main(void) {
	int i, j;
	clock_t tempo_inicial, tempo_final;
	int x;
	printf("Começou\n");
	tempo_inicial = clock();
	for (i = 1; i < 10000; i++) {
		for (j = 2; j < 1000; j++)
			x = primofast(j);
	}
	tempo_final = clock();
	printf("%f\n", (tempo_final - tempo_inicial) / (double)CLOCKS_PER_SEC);

	printf("Começou\n");
	tempo_inicial = clock();
	for (i = 1; i < 10000; i++) {
		for (j = 2; j < 1000; j++)
			x = ehprimo(j);
	}
	tempo_final = clock();
	printf("%f\n", (tempo_final - tempo_inicial) / (double)CLOCKS_PER_SEC);

	return 0;
}
