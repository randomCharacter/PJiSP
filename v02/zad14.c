/*
*	Zadatak 14
*	Dat je niz A od maksimalno 30 celobrojnih elemenata.
*	Ucitati n elemenata, zatim ucitati ceo broj br.
*	Na izlazu ispisati ceo niz i broj pojavljivanja broja br u
*	nizu.
*/

#include <stdio.h>
#include <math.h>

int main() 
{
	int n,i;
	int p[30];

	printf("Broj clanova niza:\n");
	scanf("%d", &n);

	printf("Unesite clanove niza:\n");
	for (i = 0; i < n; i++)    			//Ucitavamo niz
		scanf("%d", &p[i]);

	printf("Broj koji trazimo:\n");
	int br;
	scanf("%d", &br);
	
	int rez = 0;		//Pamtimo broj pojavljivanja br u nizu

	for (i = 0; i < n; i++)
		if (p[i] == br)
			rez++;

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
