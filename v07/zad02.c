/*Učitati dva pozitivna cela broja. Prikazati ih u 
binarnom zapisu, kao i njihove komplemente i
rezultate logičkog I, logičkog ILI i ekskluzivnog
logičkog ILI. Realizovati funkciju koja 
celobrojnu vrednost prikazuje kao binarnu.
*/

#include <stdio.h>

void binIspis(int n);

int main(int argc, char *argv[]) {
	int a, b;
	
	//Unos brojeva
	do {
		printf("Unesite prvi broj [n>0]: ");
		scanf("%d", &a);
	} while (a <= 0);
	do {
		printf("Unesite prvi broj [n>0]: ");
		scanf("%d", &b);
	} while (b <= 0);
	
	//Ispis
	printf("Prvi broj u binarnom zapisu:  ");
	binIspis(a);

	printf("\nDrugi broj u binarnom zapisu: ");
	binIspis(b);

	printf("\nRezuktat binarnog i:          ");
	binIspis(a & b);

	printf("\nRezuktat binarnog ili:        ");
	binIspis(a | b);

	printf("\nRezuktat binarnog eks ili:    ");
	binIspis(a ^ b);

	printf("\n");

	return 0;
}

//Ispis broja u binarnom obliku
void binIspis(int n) {
	int i;
	for (i=1; i<=16; i++) {
		printf ("%d", (n & 0x8000) != 0);
		n <<= 1;
		if (i % 4 == 0) {
			printf (" ");
		}
	}
}
