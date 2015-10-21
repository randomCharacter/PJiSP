/*
*	Zadatak 03
*	Dati su prirodni brojevi n,m (n <= m). Napisati program
*	koji određuje koji od brojeva od n do m predstavljaju
*	prestupne godine. Godina je prestupna ako je
*	zadovoljen sledeći skup uslova:
*	1. broj godine je deljiv sa četiri, i
*	2. važi jedno od sledećih pravila:
*	  - broj godine nije deljiv sa 100
*	  - broj godine je deljiv sa 400
*/

#include <stdio.h>

//Proverava da li je godina prestupna
int prestupna (int);

int main() {
	int n, m;
	int i;

	do {
		printf("Unesite dva broja [n<m]: ");
		scanf("%d %d", &n, &m);
	} while (n >= m);

	//Ispis samo prestupnih godina
	for(i = n; i <= m; i++)
		if (prestupna(i))
			printf("%d je prestupna\n", i);

	return 0;
}

int prestupna (int x) {
	return (x % 4 == 0) && (x % 100 != 0 || x % 400 == 0);
}