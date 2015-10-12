/*
*	Zadatak 10
*	Napisati program koji ispituje da li je dati
*	prirodan broj n prost. Broj je prost ako je deljiv
*	samo sa jedan i sa samim sobom.
*/

#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int i;
	int t = 1; //1 ako je broj prost, 0 inače

	printf("n=");
	scanf("%d", &n);

	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			t = 0; //Našli smo kontra primer
		}
	}

	if (t) {
		printf("Broj je prost\n");
	} else {
		printf("Broj nije prost\n");
	}

	return 0;
}