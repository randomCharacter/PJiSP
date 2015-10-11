/*  
*	Zadatak 04
*	Napisati program koji učitava vrednosti promenljivih a i b, a 
* 	zatim rešava jednačinu ax+b=0.
* 		– pokriti sve slučajeve za različite kombinacije vrednosti a i b 
*/

#include <stdio.h>
#include <math.h>

int main() {
	double a, b;
	double x;

	printf("a=");
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);

	//Ukoliko su i a i b nule svako x je rešenje
	if (a == 0 && b == 0) {
		printf("Svako x je resenje jednacine\n");
	//Ukoliko je samo a nula jednacina nema resenja
	} else if (a == 0 && b != 0) {
		printf("Jednacina nema resenja\n");		
	//U ostalim slucajevima
	} else {
		x = -b / a;
		printf("x=%.2lf\n", x);
	}

	return 0;
}