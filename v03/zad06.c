/* 
*	Zadatak 06
*	Dat je niz od maksimalno 20 realnih elemenata.
*	Učitati n elemenata, a zatim sortirati niz u
*	rastućem redosledu.
*	• koristiti algoritam po izboru
*
*	Zbog razumevanja koristićemo Bubble Sort algoritam
*/

#include <stdio.h>
#define MAX 20

int main() {
	double A[MAX];
	int n;
	int i, j;

	printf("n=");
	scanf("%d", &n);

	//Učitavanje niza
	for (i = 0; i < n; i++) {
		scanf("%lf", &A[i]);
	}

	//Sortiranje niza
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (A[i] < A[j]) { //Ukoliko je levi element manji treba im zameniti mesta
				int t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}

	//Ispis niza
	for (i = 0; i < n; i++) {
		printf("%.2lf ", A[i]);
	}
	printf("\n");

	return 0;
}