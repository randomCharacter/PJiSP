/*
*	Zadatak 01
*	Napisati C program koji učitava dužine kateta i
*	računa dužinu hipotenuze. Za računanje
*	hipotenuze napisati funkciju hipotenuza.
*/

#include <stdio.h>
#include <math.h>

//Metoda koja za date katete računa hipotenuzu trougla
double hipotenuza (double x, double y) {
	return(sqrt(pow(x, 2) + pow(y, 2)));
}

int main() {
	
	double a, b;
	printf("Unesite katete: ");
	scanf("%lf %lf", &a, &b);
	printf("Hipotenuza: %.2lf\n", hipotenuza(a,b));

	return 0;
}