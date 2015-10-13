/*
*	Zadatak 05
*	Napisati program za uređivanje kolona
*	pravougaone matrice sa realnim elementima po
*	neopadajućem redosledu zbirova elemenata po
*	kolonama. (Zadatak 3.13 iz zbirke L. K.)
*/

#include <stdio.h>
#define MAX_N 10
#define MAX_M 10

int main() {
	double A[MAX_N][MAX_M];
	double S[MAX_N]; //i-ti član niza sadrži sumu i-te kolone
	int n, m; //Veličine matrice
	int i, j, k;

	printf("n= ");
	scanf("%d", &n);
	printf("m= ");
	scanf("%d", &m);

	//Učitavanje matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%lf", &A[i][j]);
		}
	}

	//Računanje suma kolona
	for (i = 0; i < n; i++) {
		S[i] = 0; //Nuliranje sume
		for (j = 0; j < m; j++) {
			S[i] += A[i][j]; //Dodavanje članova kolone u sumu
		}
	}

	//Proces sortiranja
	for (i = 0; i < n; i++) {
		for (j = i; j < m; j++) {
			//Promene mesta kolonama
			if (S[i] > S[j]) {
				for (k = 0; k < n; k++) {
					double t = A[i][k];
					A[i][k] = A[j][k];
					A[j][k] = t;
				}
				//Promena vrednosti niza
				double p = S[i];
				S[i] = S[j];
				S[j] = p;
			}
		}
	}
	
	//Ispisivanje matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%.2lf ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}