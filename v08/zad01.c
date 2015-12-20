/*
*	Zadatak 01
*	Napisati rekurzivnu funkciju za izračunavanje n-tog
*	člana Fibonačijevog niza:
*	f[1] = 1, f[2] = 1, f[i] = f[i-1] + f[i-2] , i = 3,4...
*	Prirodan broj n se unosi sa tastature.
*/
#include <stdio.h>

int fib(int n);

int main() {
	int n;
	int f;

	do {
		printf("Unesite n [n>0]: ");
		scanf("%d", &n);
	} while (n <= 0);

	f = fib(n); //poziv rekurzivne funkcije
	printf("%d-ti clan fibonacijevog niza je: %d\n", n, fib(n));
	
	return 0;
}

//Računa n-ti član fibonačijevog niza
int fib(int n) {
	if (n == 1 || n == 2) { //trivijalni slučaj
		return 1; //prva dva člana su 1
	} else {
		//Rekurzivni poziv
		return fib(n - 1) + fib(n - 2); //ostali članovi su zbir prethodna dva
	}
}