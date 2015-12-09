/* 
*	Zadatak 03
*	Napisati program u kome se korišćenjem rekurzivne
*	funkcije izračunava najveći zajednički delilac prirodnih
*	brojeva x i y. Najveći zajednički delilac se rekurzivno
*	definiše sledećom formulom:
*/
#include <stdio.h>

int nzd(int x, int y);

int main() {
	int x, y;
	int n;

	do {
		printf("Unesite x [x>0]: ");
		scanf("%d", &x);
	} while (x <= 0);
	do {
		printf("Unesite y [y>0]: ");
		scanf("%d", &y);
	} while (y <= 0);

	n = nzd(x,y); //poziv rekurzivne funkcije
	printf("NZD(%d, %d) = %d\n", x, y, n);

	return 0;
}

int nzd(int x, int y) {
	if (x == 0) { //trivijalni slučaj
		return y;
	} else {
		return nzd(y % x, x); //rekurzivni poziv
	}
}