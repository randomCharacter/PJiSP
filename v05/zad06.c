/*
*	Zadatak 05
*	Napisati funkciju int jednaki(char *s1, char *s2)
*	koja proverava da li su stringovi s1 i s2 jednaki. U
*	glavnom programu od korisnika učitati dva
*	stringa (maksimalne dužine 20 karaktera) i
*	ispisati da li su jednaki.
*/
#include <stdio.h>
#include <string.h>
#define MAX 20

int jednaki(char*, char*);

int main() {
	char s1[MAX], s2[MAX];

	printf("Unesite 1. string:\n");
	scanf("%s", s1);
	printf("Unesite 2. string:\n");
	scanf("%s", s2);

	if (jednaki(s1, s2)) {
		printf("Stringovi su jednaki\n");
	} else {
		printf("Stringovi nisu jednaki\n");
	}
}

//Vraća 1 ako su stringovi s1 i s2 jednaki, 0 ako nisu
int jednaki(char *s1, char *s2) {
	int jed; //1 ako su jednaki, 0 ako nisu
	int n; //Dužina niza
	int i;

	jed = 1; //Pretpostavimo da su jednaki

	if (strlen(s1) != strlen(s2)) {
		return 0; //Ne mogu biti jednaki ako nisu iste dužine
	}

	
	n = strlen(s1); //Utvrdili smo da su isti
	for (i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			jed = 0;
		}
	}

	return jed;
}
