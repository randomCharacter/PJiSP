/*  
*	Zadatak 03
*	Napisati program kojim se za zadato x izračunava f(x) po 
*	zadatoj formuli
*/

#include <stdio.h>
#include <math.h>

int main() {
	double x;
	double f; //Vrednost f-je

	printf("x=");
	scanf("%lf", &x);

	if (x < 0) {
		f = -7.0;
	} else if (0 <= x && x < 1) {
		f = pow(x, 1.0 / 4) + 4.0;
	} else if (1 <= x && x < 13) {
		f = 2 * sqrt(x) - 5.1;
	} else { //Nema potrebe proveravati da li je veće od 13, prethodni uslovi su se pobrinuli za to
		f = x * x / 9;
	}

	printf("f(x)=%.2lf\n", f);

	return 0;
}