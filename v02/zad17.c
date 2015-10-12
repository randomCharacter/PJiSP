/*
*	Zadatak 17
*	Dat je niz C od maksimalno 80 karaktera. Učitati
*	n karaktera u niz C i formirati niz A, pri čemu su
*	elementi niza A samo slova iz niza C.
*/

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 80

int main()
{
	char C[MAX_SIZE];
	char A[MAX_SIZE];
	int n, m;
	int i, j;

	printf("n= ");
	scanf("%d", &n);

	scanf("%c", &C[0]); //Handluje enter; Zanemariti
	//Učitavanje niza
	printf("Unesite niz:\n");
	for (i = 0; i < n; i++) {
		scanf("%c", &C[i]);
	}

	//Formiranje niza A
	m = 0;
	for (i = 0; i < n; i++) {
		if ((C[i] >= 'a' && C[i] <= 'z') || (C[i] >= 'A' && C[i] <= 'Z')) {
			A[j] = C[i];
			++m;	
		}
	}

	//Ispis rezultata
	for (j = 0; j < m; j++) {
		printf("%c", C[j]);
	}

	printf("\n");
	return 0;
}