/*
*   Zadatak 01
*   Konvertovati iz binarnog u hexadecimalni
*   zapis:
*       0100 0111 0101 0111
*       1101 0100 1010 1001
*   Konvertovati iz hexadecimalnog u binarni
*   zapis:
*       0x8000
*       0x1234
*       0x9B6C
*/
#include <stdio.h>

void binIspis(int n);
void hexIspis(int n);

int main() {
    int b1 = 0b0100011101010111;
    binIspis(b1);
    printf("= ");
    hexIspis(b1);
    printf("\n");

    int b2 = 0b1101010010101001;
    binIspis(b2);
    printf("= ");
    hexIspis(b2);
    printf("\n");

    int h1 = 0x8000;
    hexIspis(h1);
    printf(" = ");
    binIspis(h1);
    printf("\n");

    int h2 = 0x1234;
    hexIspis(h2);
    printf(" = ");
    binIspis(h2);
    printf("\n");

    int h3 = 0x9B6C;
    hexIspis(h3);
    printf(" = ");
    binIspis(h3);
    printf("\n");

    return 0;
}

//Ispis u binarnom obliku iz v07/zad02.c
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

void hexIspis(int n) {
    printf("0x%x", n);
}
