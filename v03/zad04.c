/*
*	Zadatak 04
*	Napisati program za transponovanje kvadratne
*	matrice sa realnim elementima. Na početku
*	programa potrebno je učitati dimenziju i
*	elemente matrice. (Zadatak 3.12 iz zbirke L. K.)
*/

#include <stdio.h>
#define MAX 10

int main() {
	int n; //Dimenzija kv. matrice
	double A[MAX][MAX]; //Kvadratna matrica maksimalnih dimenzija MAX x MAX
	int i, j;

	printf("n=");
	scanf("%d", &n);

	//Učitavanje matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}

	//Transponovanje
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) { //Ne idemo do kraja da ne bismo 2x transponovali i poništili efekat
			double t = A[i][j]; //Pomoćna promenljiva
			A[i][j] = A[j][i];
			A[j][i] = t; 
		}
	}

	//Ispis matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}