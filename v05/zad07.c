/*
*	Zadatak 07
*	Napisati funkciju void updown(char *s) koja
*	mala slova u stringu s pretvara u velika, i
*	obrnuto. Ostale karaktere u stringu (cifre,
*	znakove interpunkcije, itd) funkcija ne sme
*	modifikovati. U glavnom programu od korisnika
*	učitati string. Nakon toga, string obraditi
*	implementiranom funkcijom i ispisati rezultat.
*/
#include <stdio.h>
#include <string.h>
#define MAX 20

void updown(char *);

int main() {
	char str[MAX];
	printf("Unesite string:\n");
	scanf("%s", str);

	updown(str);
	printf("Obrnut string: %s\n", str);
}

//Karakter koji je veliko slovo pretvara u malo
char up2down(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		return ('A' + ch - 'a'); //Pretvara malo slovo u veliko
	}
	if (ch >= 'A' && ch <= 'Z') {
		return ('a' + ch - 'A'); //Malo slovo pretvara u veliko
	}
		return ch; //Vraća karakter koji nije slovo
}

void updown(char *s) {
	int n; //Dužina stringa
	int i;

	n = strlen(s);
	for (i = 0; i < n; i++) {
		s[i] = up2down(s[i]);
	}
}