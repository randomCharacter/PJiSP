/*
*	Zadatak 04
*	Prebrojati reči iz ulazne datoteke. U izlaznoj
*	datoteci ispisati broj reči i najdužu pronađenu
*	reč. Koristiti funkcije, imena datoteka
*	prihvatiti kroz argumente komandne linije.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int isChar(char);
int brReci(char*);
void najduza(char*, char*);

int main(int brArg, char *arg[]) {
	int br; //broj reči u fajlu
	char najRec[MAX]; //najduža reč u fajlu
	FILE *f;

	//Ukoliko je korisnik uneo manje od 3 argumenta ispisuje se pomoć:
	if (brArg < 3) {
		printf("%s ulaz.txt izlaz.txt\n", arg[0]);
		return 0;
	}

	br = brReci(arg[1]);
	najduza(arg[1], najRec);

	if ((f = fopen(arg[2], "w")) == NULL) { //otvaranje fajla za pisanje
		printf("Greska pri kreiranju fajla %s!!!\n", arg[2]);
		exit(EXIT_FAILURE); //vraća grešku ukoliko nije moguće kreirati fajl
	}

	//Ispis rezultata u fajl
	fprintf(f, "Broj reci: %d\n", br);
	fprintf(f, "Najduza rec: %s\n", najRec);

	//Zatvaranje fajla na kraju programa
	fclose(f);

	return 0;
}

//Proverava da li je karakter slovo ili broj
int isChar(char ch) {
	return ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch < 'Z') || (ch >= '0' && ch <= '9'));
}

//Vraća broj reči u nekom fajlu
int brReci(char *input) {
	int br = 0;
	FILE *f;
	char str[MAX];

	if ((f = fopen(input, "r")) == NULL) { //otvaranje fajla za čitanje
		printf("Fajl ne postoji!!!\n");
		exit(EXIT_FAILURE); //vraća grešku ukoliko fajl ne postoji
	}

	//Prebrojavanje reči
	while(fgets(str, MAX, f) != NULL) { //učitava liniju po liniju
		char *s = str;
		int word = 0; //1 ako je u reči, 0 inače

		while (*s) { //prolaz kroz karaktere
			if (!word && isChar(*s)) { //ako nije u reči, a nailazi na slovo ili broj
				word = 1; //ulazi u reč
				br++; //broj reči se povećava za 1
			} else if (word && !isChar(*s)) { //ako jeste u reči, a nailazi na karakter koji nije slovo ili broj
				word = 0; //izlazi iz reči
			}
			s++; //prelazak na sledeći karakter
		}
	}

	fclose(f); //zatvaranje fajla
	return br;
}

void najduza(char *input, char *maxWord) {
	char str[MAX];
	FILE *f;
	int max; //dužina najduže reči

	if ((f = fopen(input, "r")) == NULL) { //otvaranje fajla za čitanje
		printf("Fajl ne postoji!!!\n"); 
		exit(EXIT_FAILURE); //vraća grešku ukoliko fajl ne postoji
	}

	while(fgets(str, MAX, f) != NULL) {
		char *s = str;
		char lWord[MAX]; //trnutna reč
		int word = 0; //1 ako je u reči, 0 inače
		int n = 0; //dužina trenutne reči

		while (*s) { //prolaz kroz karaktere
			if (!word && isChar(*s)) { //ako nije u reči, a nailazi na slovo ili broj
				word = 1; //ulazi u reč
				lWord[n++] = *s; //dodaje slovo u najdužu reč
			} else if (word && isChar(*s)) { //ako je u reči, a nailazi na slovo ili broj
				lWord[n++] = *s; //dodaje slovo u najdužu reč
			} else if (word && !isChar(*s)) {
				word = 0; //izlazi iz reči
				if (n > max) { //ukoliko je reč veća od dotadašnje maksimalne
					int i; //brojač
					max = n;
					for (i = 0; i < n; i++) { //kopiranje nove najduže reči
						maxWord[i] = lWord[i];
					}
					maxWord[n] = '\0'; //kraj reči
				}
				n = 0;
			}
			s++; //prelazak na sledeći karakter
		}
	}

	fclose(f); //zatvaranje fajla
}