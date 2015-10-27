/*
*	Zadatak 05
*	Šta ispisuje sledeći program?
*	
*	-ispisuje grešku, pošto nije inkludovan <string.h>,
*	a kad se inkluduje vraća
*	o
*	go
*	ngo
*	ingo
*	Bingo
*	
*	-pokreni ako ne veruješ
*/
#include <stdio.h>
#include <string.h>
int main() {
	static char ime[] = "Bingo";
	char *pok;
	pok = ime + strlen(ime);
	while(--pok>=ime)
		puts(pok);
	return 0;
}