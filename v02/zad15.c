/*
*	Zadatak 15
*	Dat je niz od maksimalno 20 realnih elemenata.
*	Učitati n elemenata, a zatim naći maksimalnu
*	vrednost.
*/

#include <stdio.h>
#include <math.h>
#define MAX 20

int main() 
{	
	float p[MAX];
	int n,i;
	float max; //Maksimalni element niza

	printf("Broj clanova niza: ");
	scanf("%d", &n);

	//Učitavanje niza
	printf("Unesite clanove niza:\n");
	for (i = 0; i < n; i++)
		scanf("%f", &p[i]);

	
	max = p[0];		//Proglasimo prvi element za maksimum

	//Tražimo novi maksimum u nizu
	for (i = 1; i < n; i++)
		if (p[i] > max)
			max = p[i];
	
	//Ispis rezultata
	printf("Maximalan element niza je: %.3f\n", max);

	return 0;
}
