/*  
*	Zadatak 01
*	Napisati C program koji 
*	ispisuje veći od dva 
*	cela broja.
*/

#include <stdio.h>

int main() {
	int a, b;
	int max;

	printf("Unesite dva broja:\n");
	scanf("%d %d", &a, &b);

	if(a > b) {
		max = a;
	} else {
		max = b;
	}

	printf("Veći od ova dva broja je %d\n", max);

	return 0;
}