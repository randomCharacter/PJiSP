/*
*	Zadatak 02
*	Napisati program koji proverava da li je učitani string 
*	palindrom. Program napraviti tako da radi za reči a 
*	potom ga proširiti da radi i sa rečenicama (ignorišući 
*	znakove razmaka) kako bi string “Ana voli Milovana”
*	program registrovao kao palindrom
*	v2 - poboljšana verzija
*/

#include <stdio.h>
#include <string.h>
#define MAX 256

int palindrom(char*);
void noSpace(char*, char*);
void toUpper(char*);

int main() {
	char str[MAX];
	char s1[MAX];

	//Učitavanje stringa
	printf("Unesite string:\n");
	gets(str); //scanf čita string dok se ne pritisne <SPACE> kako se u ovom slučaju vrši učitavanje cele rečenice to neće raditi

	//Izbacivanje <SPACE> karaktera iz stringa
	noSpace(str, s1); 

	//Prebacivanje svih slova u string u velika
	toUpper(s1);

	//Provera da li je novodobijeni string palindrom
	if (palindrom(s1)) {
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

//U string s1 vraća string s bez karaktera <SPACE>
void noSpace(char *s, char *s1) {
	int n = 0;

	while (*s) {
		if (*s != ' ') { //ukoliko karakter nije <SPACE>
			s1[n++] = *s; //dodaje se u novi string
		}
		s++; //prelazak na sledeći karakter
	}
	s1[n] = '\0'; //oznaka za kraj stringa, kako ne bi čitao karaktere koji ne bi trebali biti tu
}

//Sva slova u stringu pretvara u velika
void toUpper(char *s) {
	char s1[MAX];

	while (*s) {
		if (*s >= 'a' && *s <= 'z') { //ako je karakter malo slovo
			*s = *s + 'A' - 'a'; //pretvara se u veliko
		}
		s++; //prelazak na sledeći karakter
	}
}