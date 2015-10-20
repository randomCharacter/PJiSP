/*
*	Zadatak 06
*	Napisati program koji učitava paran prirodan broj n veći
*	od 2 a zatim koristeći funkciju prost proverava hipotezu
*	Goldbaha za dati broj n. Prema hipotezi, svaki paran
*	broj veći od dva može se predstaviti zbirom dva prosta
*	broja.
*/

#include <stdio.h>
#include <math.h>

//Vraća 1 ako je prost, 0 ako nije
//Videti v04/zad05.c za detaljnije objašnjenje
int prost(int n) {
	int p;
	int i;

	p = 1; 
	for (i = 2; i <= sqrt(n); i++) { 
		if (n % i == 0) {
			p = 0; 
		}
	}

	return p;
}

int main() {
	int n;
	int i;

	do {
		printf("Unesite paran broj [n>2]: \n");
		scanf("%d", &n);
	} while (n <= 2 || n % 2 != 0);

	for (i = 2; i <= n / 2; i++) {
		if (prost(i) && prost(n - i)) { //Ako su i i n+i prosti našli smo tražene brojeve
			printf("%d = %d + %d\n", n, i, n - i);
		}
	}

	return 0;
}