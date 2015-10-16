/*
*	Zadatak 18
*	Napisati program koji pronalazi prvi element
*	niza koji je najbliži srednjoj vrednosti niza celih
*	brojeva. Niz može da ima najviše 20 elemenata.
*/

#include <stdio.h>
#include <math.h>
#define MAX 20

int main() {
	int A[MAX]; //Niz
	int n;
	int i;
	double sr, s = 0; //Suma niza i srednja vrednost
	double minR; //Minimalna razlika
	int min = -1; //Indeks minimalnog elementa u nizu

	printf("n=");
	scanf("%d", &n);

	//Učitavanje niza
	printf("Unesite niz:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	//Računanje sume niza
	for (i = 0; i < n; i++) {
		s += A[i];
	}
	//Računanje srednje vrednosti
	sr = s / n;

	//Postavljanje prvog člana za minimalni
	min = 0; 
	minR = fabs(sr - A[0]); //abs() je samo za cele brojeve. upravo sam izgubio pola sata svog zivota da bih skontao to
	//Traženje minimalnog u ostalim članovima
	for (i = 1; i < n; i++) {
		if (fabs(sr - A[i]) < minR) {
			minR = fabs(sr - A[i]);
			min = i;
		}
	}

	//Ispis traženog elementa
	printf("Najblizi element je: %d\n", A[min]);

	return 0;
}