/*
*	Zadatak 11
*	Napisati program kojim se štampaju svi
*	trocifreni Armstrongovi brojevi. Broj je
*	Armstrongov ako je jednak zbiru kubova svojih
*	cifara.
*/

#include <stdio.h>
#include <math.h>

int main() {
	int j, d, s; //Jedinice, desetice i stotine
	int n;

	for (s = 1; s < 10; s++) {
		for (d = 1; d < 10; d++) {
			for (j = 1; j < 10; j++) {
				n = 100 * s + 10 * d + j;
				if (pow(s, 3) + pow(d, 3) + pow(j, 3) == n) {
					printf("%d\n", n);
				}
			}
		}
	}

	return 0;
}