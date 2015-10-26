/*
*	Program predstavlja implementaciju algoritma Quick Sort
*	u programskom jeziku C, za potrebe predmeta PJISP
*	
*	OVAJ ALGORITAM ZA SORTIRANJE JE DOVOVOLJAN ZA VEĆU OCENU
*/

#include <stdio.h>
#define MAX 50

void QuickSort(int *niz, int levi, int desni);

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

	//QuickSort(A, 0, n-1);

	QuickSort(A, 0, n-1);
	printf("Sortiran niz:\n[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[n - 1]);
}

void QuickSort(int niz[], int levi, int desni)
{
	if (desni <= levi)
		return;

	int pivot = niz[(levi + desni) / 2];
	int i = levi;
	int j = desni;

	while (i <= j)
	{
		if (niz[i] < pivot)
		{
			i++;
			continue;
		}

		if (niz[j] > pivot)
		{
			j--;
			continue;
		}

		int t = niz[i];
		niz[i] = niz[j];
		i++;
		niz[j] = t;
		j--;
	}

	QuickSort(niz, levi, i - 1);
	QuickSort(niz, i, desni);
}
