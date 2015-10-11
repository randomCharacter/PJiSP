/*  
*	Zadatak 02
*	Realizovati prethodni primer uz pomoć if selekcije.
*/

#include <stdio.h>

int main() {
	int o; 

	printf("Unesite ocenu:\n");
	scanf("%d", &o);

	if(o == 5) {
		printf("Odlican!\n\n");
	} else if(o == 4) {
		printf("Vrlo dobar!\n\n");
	} else if(o == 3) {
		printf("Dobar!\n\n");
	} else if(o == 2) {
		printf("Dovoljan!\n\n");
	} else if(o == 1) {
		printf("Nedovoljan!\n\n");
	} else {
		printf("Ocena mora biti izmedju 1 i 5.");
	}

	return 0;
}