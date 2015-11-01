/*
*	Zadatak 03
*	Napisati program koji učitava niz od n
*	elemenata niza strukture auto, koja sadrži
*	sledeća polja:
*		-Marka automobila (jedna reč, do 20 karaktera)
*		-Kubikaža (prirodan broj)
*		-Godište (prirodan broj)
*	Na osnovu zadate kubikaže pronaći najnoviji
*	auto sa kubikažom ne većom od zadate i
*	ispisati njegove podatke na standardni izlaz.
*/
#include <stdio.h>
#define MAX 20

struct automobil {
	char marka[MAX];
	int kub;
	int god;
};

int main() {
	struct automobil A[MAX]; //niz automobila
	int n; //dužina niza
	int maxKub; //maksimalna dozvoljena kubikaža
	int max, maxI;
	int i;

	printf("Unesite broj automobila [n<=%d]: ", MAX);
	do {
		scanf("%d", &n);
	} while (n <= 0 || n > MAX);

	//Učitavanje niza
	for (i = 0; i < n; i++) {
		printf("Unesite marku automobila br. %d: ", i + 1);
		__fpurge(stdin);
		gets(A[i].marka);
		do {
			printf("Unesite kubikazu automobila br. %d: ", i + 1);
			scanf("%d", &A[i].kub);
		} while (A[i].kub <= 0);
		do {
			printf("Unesite godiste automobila br. %d: ", i + 1);
			scanf("%d", &A[i].god);
		} while (A[i].god < 1886); //'86 je napravljen prvi automobil, pa ne može biti mlađi od toga
	}

	printf("Unesite maksimalnu kubikazu: ");
	scanf("%d", &maxKub);

	//Traženje najnovijeg automobila
	max = 0; //sve kubikaže moraju biti veće od nule
	for (i = 0; i < n; i++) {
		if (A[i].kub < maxKub) {
			if (A[i].god > max) {
				max = A[i].god;
				maxI = i;
			}
		}
	}

	//Ispis traženog automobila
	printf("Najnoviji automobil koji zadovoljava uslove je:\n");
	printf("Marka: %s\nKubikaza:%d\nGodiste:%d\n", A[maxI].marka, A[maxI].kub, A[maxI].god);

	return 0;
}