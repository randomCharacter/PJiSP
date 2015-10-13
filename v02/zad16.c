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
#define MAX 25

int main() 
{
	int n,i;
	int x[MAX], a[MAX], b[MAX];
	int ai, bi; //Trenutno poslednji članovi niza a i b

	printf("Broj clanova niza:\n");
	scanf("%d", &n);

	//Učitavanje niza
	printf("Unesite clanove niza:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	int ai = 0;  //Postavljamo prvi član kao trenutno poslednji
	int bi = 0;	 //Postavljamo prvi član kao trenutno poslednji

	//Proveravamo za svaki clan niza da li je paran i/ili negativan		
	for (i = 0; i < n; i++)  
	{
		if (x[i] < 0) //Ukoliko je negativan dodamo ga u b
		{
			b[bi] = x[i];
			bi++;
		}
		if (x[i] % 2 == 0) //Ukoliko je paran dodamo ga u a
		{
			a[ai] = x[i];
			ai++;
		}
	}	

	//Ispis niza A
	printf("A=[");
	for (i = 0; i < ai; i++)
	{
		if (i != ai-1)
			printf("%d, ", a[i]);
		else 
			printf("%d]\n", a[i]);
	}

	//Ispis niza B
	printf("B=[");
	for (i = 0; i < bi; i++)
	{
		if (i != bi-1)
			printf("%d, ", b[i]);
		else 
			printf("%d]\n", b[i]);
	}

	return 0;
}
