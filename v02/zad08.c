/*  
*	Zadatak 08
*	Napisati program kojim se za dato n izračunava 
*	faktorijel prirodnog broja n. Koristeći do-while 
*	napraviti zaštitu za unos broja n:
*	fakt = n! = 1*2*3*...*n
*/

#include <stdio.h>

int main() {
	int n;
	int f = 1; //Proizvod, na početku 1
	int i;
	do {
		printf("Unesite n:\n");
		scanf("%d", &n);
	} while (n < 0);
	for(i = 2; i <= n; i++) {
		f *= i; //U svakom prolazu proizvod se poveca i puta
	}

	printf("Fakrorijel je %d\n", f);

	return 0;
}