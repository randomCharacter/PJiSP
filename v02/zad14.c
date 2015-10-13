/*
*	Zadatak 14
*	Dat je niz A od maksimalno 30 celobrojnih elemenata.
*	Ucitati n elemenata, zatim ucitati ceo broj br.
*	Na izlazu ispisati ceo niz i broj pojavljivanja broja br u
*	nizu.
*/

#include <stdio.h>
#include <math.h>
#define MAX 30

int main() 
{
	int p[MAX];
	int n;
	int i;
	int br, rez; //Broj i broj pojavljivanja tog broja u nizu
	
	printf("Broj clanova niza: ");
	scanf("%d", &n);

	//Učitavanje niza
	printf("Unesite clanove niza:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);

	printf("Broj koji trazimo:\n");
	scanf("%d", &br);
	
	rez = 0; //Postavljamo broj pojavljivanja na 0

	for (i = 0; i < n; i++) {
		if (p[i] == br) {
			rez++;
		}
	}
	printf("Broj %d se pojavljuje %d puta u nizu A=[", br,rez);
	
	for (i = 0; i < n; i++)
	{
		if (i != n-1)
			printf("%d, ", p[i]);		//Ispis rezultata u trazenom formatu
		else 
			printf("%d]\n", p[i]);
	}

	return 0;
}
