/*
*	Zadatak 03
*	Šta ispisuje sledeći program?
*	
*	Tango argentino
*	ango argentino
*	Tango
*	ngo
*
*	-pokreni ako ne veruješ
*/

#include <stdio.h>
int main() {
	static char film[] = "Tango argentino";
	char *pok;
	pok = film;
	puts(pok);
	puts(++pok);
	film[5]='\0';
	puts(film);
	puts(++pok);
	return 0;
}