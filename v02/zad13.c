/*
*	Zadatak 13
*	Napisati program koji za dati prirodan broj n
*	izračunava:
*	S = 1 * 2 + 2*3*4 + ... + (n+0)*(n+1)*...*(n+n).
*/

#include <stdio.h>

int main()
{
	int n;
	int i, j, s, pom;

	printf("n= ");
 	scanf("%d",&n);

	s = 0; //Postavljanje sume na 0
	pom = 1; //Dodeljivanje početne vrednosti pomoćnoj pormenljivi

	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < i + 1; j++) {
			pom *= (i + j);
		}
		s += pom;
		pom = 1;
	}
	printf("Suma je: %d \n", s);

	return 0;
}