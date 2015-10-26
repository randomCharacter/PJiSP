/*
*	Zadatak 02
*	Napisati program koji učitava matricu A i ispisuje
*	sumu elemenata koji se nalaze ispod glavne
*	dijagonale matrice.
*/

#include <stdio.h>
#define MAX 10

int main() {
	int n; //Dimenzija matrice
	int A[MAX][MAX]; //Matrica maksimalnih dimenzija MAX x MAX
	int i, j;
	int s = 0; //Suma elemenata

	do {
		printf("Unesite dimenziju kvadratne matrice [n<%d]: ", MAX);
		scanf("%d", &n);
	} while (n <= 0 || n > MAX);
	
	//Učitavanje matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	//Računanje sume ispod glavne dijagonale
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			s += A[i][j];
		}
	}

	printf("Suma elemenata ispod glavne dijagonale: %d\n", s);

	return 0;
}
