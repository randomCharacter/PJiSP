/*
*	Program predstavlja implementaciju algoritma Selection Sort
*	u programskom jeziku C, za potrebe predmeta PJISP
*	
*	OVAJ ALGORITAM ZA SORTIRANJE NIJE DOVOVOLJAN ZA VEĆU OCENU
*/

#include <stdio.h>
#define MAX 50


int SelectionSort(int niz[], int duzina);

int main() {
	int A[MAX];
	int n;
	int i, j;

	//Učitavanje niza
	do {
		printf("Duzina niz [0<n<%d]: ", MAX);
		scanf("%d", &n);
	} while (n<=0 || n > MAX);

	printf("Unesite niz:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	//Sortiranje niza
	SelectionSort(A, n);

	//Ispis sortiranog niza
	printf("Sortiran niz:\n[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[n - 1]);
}

int SelectionSort(int niz[], int duzina) {
	int i, j;

	for (i = 0; i < duzina - 1; i++) {
		for (j = i + 1; j < duzina; j++) {
			if (niz[i] > niz[j]) {
				int t = niz[j];
				niz[j] = niz[i];
				niz[i] = t;
			}
		}
	}
}