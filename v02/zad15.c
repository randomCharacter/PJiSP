/*
*	Zadatak 15
*	Dat je niz od maksimalno 20 realnih elemenata.
*	Učitati n elemenata, a zatim naći maksimalnu
*	vrednost.
*/

#include <stdio.h>
#include <math.h>

int main() 
{
	int n,i;
	float p[20];

	printf("Broj clanova niza:\n");
	scanf("%d", &n);

	printf("Unesite clanove niza:\n");
	for (i = 0; i < n; i++)    			//Ucitavamo niz
		scanf("%f", &p[i]);

	
	float max = p[0];		//Pamtimo maximalnu vrednost niza

	for (i = 1; i < n; i++)  //Proveravamo za svaki clan niza 
		if (p[i] > max)		 //da li je veci od trenutnog maximuma
			max = p[i];
	

	printf("Maximalan element niza je: %.3f\n", max);


	return 0;
}
