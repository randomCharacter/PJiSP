/*
*   Zadatak 04
*   • Napisati funkciju za zaštitu podataka neparnim
*     paritetom. Podaci su dužine 7 bita. Napisati test
*     program koji ilustruje rad prethodne funkcije nad
*     nizom podataka.
*   • Napisati funkciju za zaštitu podataka parnim
*     paritetom. Podaci su dužine 7 bita. Napisati test
*     program koji ilustruje rad prethodne funkcije nad
*     nizom podataka.
*/
#include <stdio.h>

void binIspis(int n);
void printData(char *data, int n);
void neparniParitet(char *data, int n);

int main () {
    char data[] = {'0', 'Q', '(', 'f', ','};
    int n = 5;

    // funkcija printData ispisuju podatke u binarnom obliku
    // funkcija neparniParitet postavlja bite pariteta
    printData(data, n);
    neparniParitet(data, n);
    printData(data, n);

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

//Ispisuje podatke u binarnom obliku
void printData(char *data, int n) {
    int i;
    for (i = 0; i < n; i++) {
        binIspis(data[i]);
    }
}

//Postavlja bite partiteta
void neparniParitet(char *data, int n) {
    int i;
    int mask = 1;
    for (i = 0; i < n; i++) {
        data[i] = data[i] | (mask <<= 7);
        mask = 1;
    }
    printData(data, n);
}
