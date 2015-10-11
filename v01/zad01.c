/*  Zadatak 01
*	Izračunati površinu trougla upotrebom 
*	Heronovog obrasca
*/

#include <stdio.h>
#include <math.h>

int main() {
	//Stranice trougla
	double a = 2.0;
	double b = 4.0;
	double c = 5.0;

	//Računanje poluobima
	s = (a + b + c) / 2;

	//Računanje i ispis površine na dve decimale
	P = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("P=%.2lf\n", P);
	
	//Uspešan završetak programa
	return 0;
}