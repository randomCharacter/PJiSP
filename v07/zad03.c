/*
*   Zadatak 03
*   • Napisati funkciju koja omogućava očitavanje n-tog
*   bita registra u procesoru. - getBit
*   • Napisati funkciju koja omogućava “setovanje” n-
*   tog bita registra u procesoru na jedinicu. – setBit
*   • Napisati funkciju koja omogućava postavljanje n-
*   tog bita registra u procesoru na 0. – clearBit
*   • Napisati funkciju koja omogućava promenu (1->0 i
*   0->1) n-tog bita registra u procesoru. - flipBit
*   • Napisati test program koji ilustruje upotrebu ovih
*   funkcija.
*/
#include <stdio.h>
#include <stdlib.h>

void binIspis(int n);
void getBit(unsigned v, int bitNo);
void setBit(unsigned v, int bitNo);
void clearBit(unsigned v, int bitNo);
void flipBit(unsigned v, int bitNo);

int main() {
    unsigned br, bit, val;

    //Unos broja
    printf("Unesite broj: ");
    scanf("%u", &br);

    //Ispis broja u binarnom zapisu
    printf("Broj u binarnom zapisu:");
    binIspis(br);

    //Ispitivanje n-tog bita broja
    do {
        printf("\nUnesite bit kojem zelite da pristupite: ");
        scanf("%u", &bit);
    } while (bit <= 0 || bit > sizeof(int)*4);
    getBit(br, bit);

    //Promena n-tog bita
    do {
        printf("\nUnesite redni broj bita koji zelite da promenite");
        scanf("%u", &bit);
    } while (bit <= 0 || bit > sizeof(int)*4);
    do {
        printf("\nUnesite vrednost na koju zelite da ga postavite [0,1]:");
        scanf("%u", &val);
    } while (val < 0 || val > 1);
    if (val == 1) {
        setBit(br, bit);
    } else {
        clearBit(br, bit);
    }

    //Menjanje n-tog bita
    do {
        printf("\nUnesite redni broj bita koji zelite da flipujete:");
        scanf("%u", &bit);
    } while (bit <= 0 || bit > sizeof(int)*4);
    flipBit(br, bit);

    printf("\n");

    return 0;
}

//Ispisuje broj u binarnom obliku v07/zad02.c
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

//Prikazuje n-ti bit broja
void getBit(unsigned v, int bitNo) {
    unsigned mask = 1;
    mask <<= bitNo -1;

    printf("%d. bit broja %hd je: %d\n", bitNo, v, (v & mask) != 0);

}

//Postavlja n-ti bit broja na 1
void setBit(unsigned v, int bitNo) {
    unsigned mask = 1;
    mask <<= bitNo - 1;

    v = v | mask;
    binIspis(v);
}

//Postavlja n-ti bit broja na 0
void clearBit(unsigned v, int bitNo) {
    unsigned mask = 1;
    mask <<= bitNo - 1;
    mask = ~mask;

    v = v & mask;
    binIspis(v);
}

//Menja vrednost n-tom bitu
void flipBit(unsigned v, int bitNo) {
    unsigned mask = 1;
    mask <<= bitNo - 1;

    v = v ^ mask;
    binIspis(v);
}
