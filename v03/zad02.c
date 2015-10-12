/*
*	Zadatak 02
*	Napisati program koji učitava matricu A i ispisuje
*	sumu elemenata koji se nalaze ispod glavne
*	dijagonale matrice.
*/

#include <stdio.h>
#define MAX_N 10
#define MAX_M 10

int main() {
	int n, m; //Dimenzije matrice
	int A[MAX_N][MAX_M]; //Matrica maksimalnih dimenzija MAX_N x MAX_M
	int i, j;
	int s = 0; //Suma elemenata

	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", &m);

	//Učitavanje matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
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