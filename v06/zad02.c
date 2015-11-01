/*
*	Zadatak 02
*	Napiši program koji učitava niz od n elemenata 
*	niza strukture ličnost, koja sadrži sledeća polja: 
*	ime, adresa, dan rođenja, mesec rođenja i 
*	godina rođenja. Prikazati osobe koje su u 
*	horoskopu bik.
*/
#include <stdio.h>
#define MAX 256

struct licnost {
	char ime[MAX];
	char adresa[MAX];
	int danR;
	int mesR;
	int godR;
};

int main() {
	struct licnost l[MAX]; //niz ličnosti
	int n; //dužina niza ličnosti
	int i;

	printf("Unesite broj ličnosti [n<=%d]: ", MAX);
	scanf("%d", &n);

	//Učitavanje ličnosti
	for (i = 0; i < n; i++) {
		printf("Unesite ime licnosti br. %d: ", i + 1);
		__fpurge(stdin);
		gets(l[i].ime);
		printf("Unesite adresu licnost br. %d: ", i + 1);
		__fpurge(stdin);
		gets(l[i].adresa);
		do {
			printf("Unesite dan rodjenja licnost br. %d: ", i + 1);
			scanf("%d", &l[i].danR);
		} while (l[i].danR < 0 || l[i].danR > 31);
		do {
			printf("Unesite mesec rodjenja licnost br. %d: ", i + 1);
			scanf("%d", &l[i].mesR);
		} while (l[i].mesR < 0 || l[i].mesR > 12);
		printf("Unesite godinu rodjenja licnost br. %d: ", i + 1);
		scanf("%d", &l[i].godR);	
	}

	printf("BIKOVI SU:\n");
	//Nalaženje bikova
	for (i = 0; i < n; i++) {
		if ((l[i].mesR == 4 && l[i].danR >= 21) || (l[i].mesR == 5 && l[i].danR < 21)) {
			printf("Ime: %s\nAdresa: %s\nDatum rodjenja:%d.%d.%d.\n", l[i].ime, l[i].adresa, l[i].danR, l[i].mesR, l[i].godR);
		}
	}

	return 0;
}