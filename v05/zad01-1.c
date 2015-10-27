/* 
*	Zadatak 01
*	Napisati funkciju koja ispisuje string obrnutim redom. 
*	Napraviti kratak test program (u čitati string i ispisati 
*	obrnutim redosledom karaktere) sa i bez upotrebe f-ije strlen().
*	v1 - koristeći f-ju strlen()
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

	return 0;
}

//Ispisuje string s u obrnutom poretku
int ispis(char* s) {
	int n; //Dužina stringa n
	int i;

	n = strlen(s); //strlen vraća dužinu stringa
	for (i = n - 1; i >= 0; i--) {
		printf("%c", s[i]);
	}
	printf("\n");
}