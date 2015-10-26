/*
*	Program predstavlja implementaciju algoritma Shell Sort
*	u programskom jeziku C, za potrebe predmeta PJISP
*	
*	OVAJ ALGORITAM ZA SORTIRANJE JE DOVOVOLJAN ZA VEĆU OCENU
*/

#include <stdio.h>
#define MAX 50


void ShellSort(int *niz, int duzina);

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

	ShellSort(A, n);

	printf("Sortiran niz:\n[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[n - 1]);
}

void ShellSort(int *niz, int duzina) {
	int h, t;
	int i, j;
	for (h = duzina; h /= 2;) {
        for (i = h; i < duzina; i++) {
            t = niz[i];
            for (j = i; j >= h && t < niz[j - h]; j -= h) {
                niz[j] = niz[j - h];
            }
            niz[j] = t;
        }
    }
}