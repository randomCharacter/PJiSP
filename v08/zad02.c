/*
*	Zadatak 02
*	Napisati rekurzivnu funkciju kojom se izračunava suma
*	cifara dekadnog broja n.
*/
#include <stdio.h>
#include <stdlib.h>

int suma(int n);

int main() {
	int n;
	int s;

	printf("Unesite n: ");
	scanf("%d", &n);

	s = abs(suma(n)); //poziv rekurzivne funkcije(ako unesemo negativan broj zbir ce biti negativan pa se uzima abs)
	printf("%d\n", s);

	return 0;
}

//Računa sumu cifara broja n
int suma(int n) {
	if (n == 0) { //trivijalni slučaj
		return 0; //broj je 0
	} else {
		int n1 = n / 10; //broj n bez poslednje cifre
		//Rekurzivni poziv
		return n % 10 + suma(n1); //vraća zbir poslednje cifre i zbir cifara broja bez poslednje cifre
	}
}
