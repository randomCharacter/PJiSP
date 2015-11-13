/*
*	Zadatak 06
*	Napisati funkciju void kodiraj(char *ul_dat, char
*	*izl_dat) koja kodira ulaznu datoteku tako što svako
*	slovo iz ulazne datoteke pomera za jednu poziciju
*	unapred, u alfabetu. Parametri ul_dat i izl_dat su nazivi
*	ulazne, odn. izlazne datoteke.

**	• Napisati funkciju void dekodiraj(char *ul_dat, char
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

int isSmallChar(char);
int isBigChar(char);
void kodiraj(char*, char*);
void dekodiraj(char*, char*);

int main(int brArg, char *arg[]) {
	//Ukoliko je korisnik uneo manje od 4 argumenta ispisuje se pomoć:
	if (brArg < 4) {
		printf("Za kodiranje: -k ulaz izlaz\nZa dekodiranje: -d ulaz izlaz\n");
		return 0;
	}
	//Ukoliko želi da kodira fajl
	if (strcmp(arg[1], "-k") == 0) {
		kodiraj(arg[2], arg[3]);
	//Ukoliko želi da dekodira fajl
	} else {
		dekodiraj(arg[2], arg[3]);
	}
	return 0;
}

//Proverava da li je karakter malo slovo
int isSmallChar(char ch) {
	return (ch >= 'a' && ch <= 'z');
}

//Proverava da li je karakter veliko slovo
int isBigChar(char ch) {
	return (ch >= 'A' && ch <= 'Z');
}

//Kodira ulaznu datoteku i rezultat ispisuje u izlaznu
void kodiraj(char *ul_dat, char *izl_dat) {
	FILE *f;
	FILE *g;
	char ch;

	if ((f = fopen(ul_dat, "r")) == NULL) { //otvara za čitanje
		printf("Fajl ne postoji!!!\n");
		exit(EXIT_FAILURE); //vraća grešku ako fajlne postoji
	} 
	if ((g = fopen(izl_dat, "w")) == NULL) { //otvara za pisanje
		printf("Nije moguće kreirati fajl!!!\n");
		exit(EXIT_FAILURE); //vraća grešku ako ne uspe na kreira fajl
	} 

	while((ch = fgetc(f)) != EOF) {
		if (isSmallChar(ch)) { //kodira malo slovo
			ch = (ch - 'a' + 1) % 26 + 'a';
		} else if (isBigChar(ch)) { //kodira veliko slovo
			ch = (ch - 'A' + 1) % 26 + 'A';
		}
		fputc(ch, g); //druge karaktere ne dira
	}

	//Zatvaranje fajlova nakon završenog rada sa njima
	fclose(f);
	fclose(g);
}

//Dekodira ulaznu datoteku i rezultat ispisuje u izlaznu
void dekodiraj(char *ul_dat, char *izl_dat) {
	FILE *f;
	FILE *g;
	char ch;

	if ((f = fopen(ul_dat, "r")) == NULL) { //otvara za čitanje
		printf("Fajl ne postoji!!!\n");
		exit(EXIT_FAILURE); //vraća grešku ako fajl ne postoji
	} 
	g = fopen(izl_dat, "w"); //otvara za pisanje

	while((ch = fgetc(f)) != EOF) {
		if (isSmallChar(ch)) { //dekodira malo slovo
			ch = (ch - 'a' - 1 + 26) % 26 + 'a';
		} else if (isBigChar(ch)) { //dekodira veliko slovo
			ch = (ch - 'A' - 1 + 26) % 26 + 'A';
		}
		fputc(ch, g); //druge karaktere ne dira
	}

	//Zatvaranje fajlova nakon završenog rada sa njima
	fclose(f);
	fclose(g);
}