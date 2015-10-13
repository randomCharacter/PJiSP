/*
*	Zadatak 12
*	a svaku od navedenih formula napisati program koji
*	računa broj π (preciznost zavisi od dužine niza):
*/

#include <stdio.h>
#include <math.h>
int main()
{
	int n,i;
	float x,pi;

	printf("Unesite n: ");
	scanf("%d", &n);

	//Računanje pi po prvoj formuli
	x = 0;
	for (i=1; i < n + 1; i++) {
		x += (1.0 / (i * i));
	}
	pi = sqrt(x * 6);
	printf("Po prvoj formuli Pi je: %f \n", pi);

	//Računanje pi po drugoj formuli
	x = 0;
	for (i = 0; i < n; i++) {
		x += pow(-1, i) * (1.0 / ( i + i + 1));
	}
	pi = 4 * x;
	printf("Po drugoj formuli Pi je: %f \n", pi);

	//Računanje pi po trćoj formuli
	x = 1;
	int pom1 = 2;
	int pom2 = 1;
	for (i = 0; i < n; i++) {
		x = x * ((float) pom1 / pom2);
		if( i % 2 == 0) {
			pom2 += 2;
		} else { 
			pom1 += 2;
		}
	}
	pi = 2 * x;
	printf("Po trecoj formuli Pi je: %f \n", pi);

	//Računanje pi po četvrtoj formuli
	x = 3;
	for(i = 0; i < n - 1; i++) {
		int j = 2 * (i + 1); //Pomoćna promenljiva  
		x += pow(-1.0, i) * 4 / ((j + 2) * j * (j+1));
	}
	pi = x;
	printf("Po cetvrtoj formuli Pi je: %f \n", pi);

	return 0;
}