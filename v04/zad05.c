/* 
*	Zadatak 05
*	Napisati program koji učitava prirodan broj n a zatim
*	koristeći funkciju prost štampa sve proste brojeve
*	manje od datog broja n.
*/

#include <stdio.h>
#include <math.h>

int prost(int);

int main() {
	int n;
	int i;

	do {
		printf("Unesite broj n [n>0]:");
		scanf("%d", &n);
	} while (n <= 0);

	//Ispis prvih n prostih
	for (i = 2; i <= n; i++) { //1 nije ni prost ni složen, zato kreće od 2
		if (prost(i)) {
			printf("broj %d je prost\n", i);
		}
	}

	return 0;

}

//Vraća 0 ako broj nije prost, 1 ako jeste
int prost(int n) {
	int p;
	int i;

	p = 1; //pretpostavljamo da je n prost broj
	//Tražimo broj kojim je n deljiv kako bismo opovrgli da je broj prost
	//Ovaj broj ako postoji mora biti manji (ili jednak) od kvadratnog korena broja n i veći od 2
	for (i = 2; i <= sqrt(n); i++) { 
		if (n % i == 0) {
			p = 0; //našli smo deljiv broj => nije prost
		}
	}

	return p;
}