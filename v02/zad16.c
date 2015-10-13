/*
*	Zadatak 16
*	Dat je niz X od maksimalno 25 celobrojnih
*	elemenata. Učitati n elemenata u niz X i
*	formirati nizove A i B, pri čemu su elementi niza
*	A parni elementi niza X, a elementi niza B su
*	negativni elementi niza X. Ispisati nizove X, A i B.
*/

#include <stdio.h>
#include <math.h>

int main() 
{
	int n,i;
	int x[25];
	int a[25];
	int b[25];

	printf("Broj clanova niza:\n");
	scanf("%d", &n);

	printf("Unesite clanove niza:\n");
	for (i = 0; i < n; i++)    			//Ucitavamo niz
		scanf("%d", &x[i]);

	int ai = 0;  //Pamtimo index trenutno poslednjeg clana
	int bi = 0;	 //Pamtimo index trenutno poslednjeg clana

	//Proveravamo za svaki clan niza da li je paran i/ili negativan		
	for (i = 0; i < n; i++)  
	{
		if (x[i] < 0)
		{
			b[bi] = x[i];
			bi++;
		}
		if (x[i] % 2 == 0)
		{
			a[ai] = x[i];
			ai++;
		}
	}	


	printf("X=[");
	for (i = 0; i < n; i++)
	{
		if (i != n-1)
			printf("%d, ", x[i]);		//Ispis rezultata u trazenom formatu
		else 
			printf("%d]\n", x[i]);
	}

	printf("A=[");
	for (i = 0; i < ai; i++)
	{
		if (i != ai-1)
			printf("%d, ", a[i]);		//Ispis rezultata u trazenom formatu
		else 
			printf("%d]\n", a[i]);
	}

	printf("B=[");
	for (i = 0; i < bi; i++)
	{
		if (i != bi-1)
			printf("%d, ", b[i]);		//Ispis rezultata u trazenom formatu
		else 
			printf("%d]\n", b[i]);
	}





	return 0;
}
