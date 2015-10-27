/*
*	Zadatak 04
*	Napisati funkciju koja kao parametre uzima jedan string
*	i karakter, a vraća broj pojavljivanja tog karaktera u
*	string. Napisati test program. (Primer: str=“tatatatira”,
*	c=‘a’, povratna vrednost je 4).
*/
#include <stdio.h>
#include <string.h>
#define MAX 50
int izbroji(char*, char);


int main() {
	char str[MAX];
	char ch;
	printf("Unesite string:\n");
	scanf("%s", str);
	printf("Unesite karakter:\n");
	scanf(" %c", &ch); //Razmak kako bi ignorisao <ENTER> i <SPACE>

	printf("Karakter %c se pojavljuje %d puta u stringu \"%s\"\n", ch, izbroji(str, ch), str);

	return 0;
}

//Broji koliko se puta karakter ch nalazi u stringu s
int izbroji(char *s, char ch) {
	int n; //Dužina stringa
	int br = 0; //Broj pojavljivanja
	int i;

	n = strlen(s);

	for (i = 0; i < n; i++) {
		if (s[i] == ch) {
			br++;
		}
	}

	return br;
}