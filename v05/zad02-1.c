/*
*	Zadatak 02
*	Napisati program koji proverava da li je učitani string 
*	palindrom. Program napraviti tako da radi za reči a 
*	potom ga proširiti da radi i sa rečenicama (ignorišući 
*	znakove razmaka) kako bi string “Ana voli Milovana”
*	program registrovao kao palindrom
*	v1 - neoptimizovana verzija
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int palindrom(char *s);

int main() {
	char str[MAX];

	printf("Unesite string:\n");
	scanf("%s", str);

	if (palindrom(str)) {
		printf("\"%s\" je palindrom\n", str);
	} else {
		printf("\"%s\" nije palindrom\n", str);
	}

	return 0;
}

//Vraća 1 ako string jeste palindrom, 0 ako nije
int palindrom(char *s) {
	int n; //dužina stringa
	int p; //1 ako je palindrom, 0 ako nije
	int i;

	p = 1; //Pretpostavljamo da je string palindrom
	n = strlen(s);

	for (i = 0; i < n / 2; i++) { 
		if (s[i] != s[n-i-1]) { 
			p = 0; //našli smo kontra primer, tako da string nije palindrom
		}
		return p;
	}
}