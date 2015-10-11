/*  Zadatak 02
*	Izračunati površinu trougla upotrebom
*	Heronovog obrasca, vrednosti stranica uneti sa
*	tastature. Na izlazu štampati vrednost površine
* 	trougla na dve decimale.
*/

#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c; //stranice
	double s; //poluobim
	double P; //površina

	printf("Unesite stranice trougla:\n");
	//Učitavanje prve stranice trougla
	printf("a=");
	scanf("%lf",&a);
	//Učitavanje druge stranice trougla
	printf("b=");
	scanf("%lf",&b);
	//Učitavanje treće stranice trougla
	printf("c=");
	scanf("%lf",&c);
	//Računanje poluobima
	s = (a + b + c) / 2;
	//Računanje i ispis površine na dve decimale
	P = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("P=%.2lf\n", P);
	//Uspešan završetak programa
	return 0;
}