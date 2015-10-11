/* 	Zadatak 03:
*	Napisati program koji od korisnika traži da 
*	unese tri celobrojne vrednosti, a zatim ispisuje 
*	njihov aritmetičku, harmonijsku, geometrijsku 
*	i kvadratnu sredinu.
*/

#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	double ar, ha, ge, kv;

	//Učitavanje brojeva
	printf("Unesite prvi broj:\n");
	scanf("%d", &a);

	printf("Unesite drugi broj:\n");
	scanf("%d", &b);

	printf("Unesite treci broj:\n");
	scanf("%d", &c);

	//Kastovanje brojeva u double i računanje sredina
	ar = ((double) a + b + b) / 3; //dovoljno je kastovati jedan, ostali se automatski kastuju
	ha = 3.0 / (1.0 / a + 1.0 / b + 1.0 / c);
	ge = pow(a * b * c, 1.0 / 3);
	kv = sqrt((a * a + b * b + c * c) / 3.0);

	//Ispis sredina
	printf("Aritmeticka sredina je %.2lf\n", ar);
	printf("Harmonijska sredina je %.2lf\n", ha);
	printf("Geometrijska sredina je %.2lf\n", ge);
	printf("Kvadratna sredina je %.2lf\n", kv);

	return 0;
}