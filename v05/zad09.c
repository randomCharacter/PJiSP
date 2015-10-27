/*
*	Zadatak 09
*	Napisati program koji od korisnika učitava niz
*	stringova i ispisuje ih na ekran. Program treba od
*	korisnika najpre da učita dužinu niza (odnosno
*	broj stringova), a zatim svaki string.
*/
#include <stdio.h>
#include <string.h>
#define MAX 50
#define MAX_STR 10

int main() {
	char nizStr[MAX_STR][MAX];
	int n, i;

	printf("Unesite broj stringova [n<%d]: ", MAX_STR);
	scanf("%d", &n);
	printf("Unesite %d stringova:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%s", nizStr[i]);
	}
	printf("\nIspis stringova:\n");
	for (i = 0; i < n; i++) {
		printf("%s\n", nizStr[i]);
	}
}