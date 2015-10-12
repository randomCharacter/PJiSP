/*
*	Zadatak 09
*	Sa standardnog ulaza učitati prirodne brojeve N i
*	q. Koristeći while ispisati sve brojeve od 2 do N
*	koji su deljivi sa q.
*/

#include <stdio.h>

int main() {
	int N, q;
	int i;

	printf("N=");
	scanf("%d", &N);
	printf("q=");
	scanf("%d", &q);

	//Traženje i ispis brojeva
	i = 2;
	while (i <= N) {
		if (i % q == 0) {
			printf("%d\n", i);
		}
		++i;
	}

	return 0;
}