/*
*	Zadatak 06
*	Napisati funkciju void kodiraj(char *ul_dat, char
*	*izl_dat) koja kodira ulaznu datoteku tako što svako
*	slovo iz ulazne datoteke pomera za jednu poziciju
*	unapred, u alfabetu. Parametri ul_dat i izl_dat su nazivi
*	ulazne, odn. izlazne datoteke.
*
*	• Napisati funkciju void dekodiraj(char *ul_dat, char
*	*izl_dat) koja dekodira ulaznu datoteku tako što svako
*	slovo iz ulazne datoteke pomera za jednu poziciju
*	unazad, u alfabetu. Parametri ul_dat i izl_dat su nazivi
*	ulazne, odn. izlazne datoteke.
*
*	• Napisati program koji testira prethodno definisane
*	funkcije
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSmallChar(char ch);
int isBigChar(char ch);
void kodiraj(char *ul_dat, char *izl_dat);
void dekodiraj(char *ul_dat, char *izl_dat);

int main(int brArg, char *arg[]) {
	if (brArg < 4) {
		exit(EXIT_FAILURE);
	}
	if (strcmp(arg[1], "-k")) {
		kodiraj(arg[2], arg[3]);
	} else {
		dekodiraj(arg[2], arg[3]);
	}
	return 0;
}

int isSmallChar(char ch) {
	return (ch >= 'a' && ch <= 'z');
}

int isBigChar(char ch) {
	return (ch >= 'A' && ch <= 'Z');
}

void kodiraj(char *ul_dat, char *izl_dat) {
	FILE *f;
	FILE *g;
	char ch;
	f = fopen(ul_dat, "r");
	g = fopen(izl_dat, "w");

	while((ch = fgetc(f)) != EOF) {
		if (isSmallChar(ch)) {
			ch = (ch - 'a' + 1) % 26 + 'a';
		} else if (isBigChar(ch)) {
			ch = (ch - 'A' + 1) % 26 + 'A';
		}
		fputc(ch, g);
	}

	fclose(f);
	fclose(g);
}

void dekodiraj(char *ul_dat, char *izl_dat) {
	FILE *f;
	FILE *g;
	char ch;
	f = fopen(ul_dat, "r");
	g = fopen(izl_dat, "w");

	while((ch = fgetc(f)) != EOF) {
		if (isSmallChar(ch)) {
			ch = (ch - 'a' - 1) % 26 + 'a';
		} else if (isBigChar(ch)) {
			ch = (ch - 'A' - 1) % 26 + 'A';
		}
		fputc(ch, g);
	}

	fclose(f);
	fclose(g);
}