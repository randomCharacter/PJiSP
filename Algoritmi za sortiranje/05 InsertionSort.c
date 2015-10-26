/*
*	Program predstavlja implementaciju algoritma Insertion Sort
*	u programskom jeziku C, za potrebe predmeta PJISP
*	
*	OVAJ ALGORITAM ZA SORTIRANJE (NI)JE DOVOVOLJAN ZA VEĆU OCENU
*/

#include <stdio.h>
#define MAX 50

void InsertionSort(int niz[], int n);

int main() {
	int A[MAX];
	int n;
	int i, j;

	do {
		printf("Duzina niz [0<n<%d]: ", MAX);
		scanf("%d", &n);
	} while (n<=0 || n > MAX);

	printf("Unesite niz:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	InsertionSort(A, n);

	printf("Sortiran niz:\n[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[n - 1]);
}

void InsertionSort(int niz[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i - 1;

		if (niz[i] >= niz[j]) 
			continue;
			
		int t = niz[i];
			
		do {
			niz[j + 1] = niz[j];
			if (--j < 0)
				break;
		} while (t < niz[j]);

			niz[j + 1] = t;

	}
}
