/*
*	Zadatak 04
*	Napisati program kojim se štampaju svi trocifreni
*	brojevi (ako ih ima) koji su jednaki sumi faktorijela
*	svojih cifara.
*/

#include <stdio.h>

//Vraća faktorijel unetog broja
int faktorijel(int x) {
	if (x == 0 || x == 1) //0! = 1! = 1
		return 1;
	return x * faktorijel(x - 1); //ne treba nam else pošto se sa return već izlazi metode
}

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