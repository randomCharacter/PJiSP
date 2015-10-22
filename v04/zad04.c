/*
*	Zadatak 04
*	Napisati program kojim se štampaju svi trocifreni
*	brojevi (ako ih ima) koji su jednaki sumi faktorijela
*	svojih cifara.
*/

#include <stdio.h>

int faktorijel(int);

int main() {
	int j, d, s;

	for (j = 1; j < 10; j++) {
		for (d = 0; d < 10; d++) {
			for (s = 0; s < 10; s++) {
				int br = 100 * s + 10 * d + j;
				if (br == faktorijel(s) + faktorijel(d) + faktorijel(j)) {
					printf("broj %d zadovoljava uslov\n", br);
				}
			}
		}
	}

	return 0;
}

//Vraća faktorijel unetog broja
int faktorijel(int x) {
	int fact = 1;
	int i;
	for (i = 2; i <= x; i++) {
		fact *= i;
	}

	return fact;
}