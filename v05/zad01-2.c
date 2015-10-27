/* 
*	Zadatak 01
*	Napisati funkciju koja ispisuje string obrnutim redom. 
*	Napraviti kratak test program (u čitati string i ispisati 
*	obrnutim redosledom karaktere) sa i bez upotrebe f-ije strlen().
*	v2 - bez f-je strlen()
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int ispis(char*);

int main() {
	char str[MAX]; //String maksimalne duzine MAX

	printf("Unesite string:\n");
	scanf("%s", str);

	ispis(str);
	printf("\n");

	return 0;
}

//Ispisuje string s u obrnutom poretku
int ispis(char* s) {
	if (*s) {
		ispis(s+1);  //Rekurzivni poziv
		printf("%c", *s);
	}
}