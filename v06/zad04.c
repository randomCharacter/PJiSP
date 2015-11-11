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

int brReci(char[]);
void najRec(FILE*, char*);

//Argumenti su ime ulazne datoteke i ime izlazne datoteke
//Ukoliko nisu navedeni program se prekida
//Ukoliko ih ima više od 2 zanemaruju se
int main(int brArg, char *arg[]) {
	//Ukoliko nema argumenata rad programa se prkida
	if (brArg < 2) {
		exit(5);
	}

	//if (brReci(arg[0]) != -1) {
		printf("Br reci: %d\n", brReci(arg[0]));
	//} else {
	//	printf("GRESKA 344\n");
	//}

	return 0;
}

int isChar(char ch) {
	return ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch < 'Z') || (ch >= '0' && ch <= '9'));
}

int brReci(char fName[]) {
	FILE* f;
	char* s;

	if (f = fopen(fName, "r")/* == NULL*/) {
		return -1; //Desila se greška
	} else {
		int br = 0; //brojač
		int word = 0; //1 ako je trenutno u reči, 0 ako nije

		//Prebrojavanje (v05/zad10.c)
		while (fgets(s, MAX, f) != NULL) {
			while (*s) { 
				if (!word && isChar(*s)) { //ako nije u reči, a nailazi na slovo ili broj
					word = 1; //ulazi u reč
					br++; //broj reči se povećava za 1
				} else if (word && !isChar(*s)) { //ako je bio u reči i nailazi na karakter koji nije slovo ili broj
					word = 0; //izlazi iz reči
				}
				s++; //prelazak na sledeći karakter
			}
		}

		return br;
	}
}