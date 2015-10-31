/*
*	Program predstavlja implementaciju algoritma Bubble Sort
*	u programskom jeziku C, za potrebe predmeta PJISP
*	
*	OVAJ ALGORITAM ZA SORTIRANJE NIJE DOVOVOLJAN ZA VEĆU OCENU
*/

#include <stdio.h>
#define MAX 50


int BubbleSort(int niz[], int duzina);

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
	BubbleSort(A, n);

	//Ispis sortiranog niza
	printf("Sortiran niz:\n[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[n - 1]);
}

int BubbleSort(int niz[], int duzina) {
	int i, j;

	for (i = 0; i < duzina; i++) {
		for (j = 0; j < duzina; j++) {
			if (niz[j] > niz[j + 1]) {
				int t = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = t;
			}
		}
	}
}