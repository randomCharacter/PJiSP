/*
*	Zadatak 01
*	Napisati funkciju, koja izračunava vrednost
*	izraza, čiji su članovi jednocifreni brojevi,
*	zadatog u ulaznom tekstualnom fajlu u
*	obrnutoj poljskoj notaciji. Na primer, vrednost
*	izraza 395+/472-*+ je jednaka vrednosti:
*	3/(9+5)+4*(7-2)
*	• Funkciju realizovati korišćenjem steka
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef int TIP;
typedef struct cvor_st {
	TIP inf;
	struct  cvor_st *sledeci;
} SCVOR;

int charToDig(char ch);
int isDigit(char ch);
void push(TIP inf, SCVOR **vrh);
TIP pop(SCVOR **vrh);
TIP top(SCVOR **vrh);

int main() {
	SCVOR *stek; //stek na koji se ubacuju brojne vrednosti
	char op[MAX];
	int i, n;
	int op1, op2, res;

	//Učitavanje komandi
	printf("Unesite komandu u obrnutoj poljskoj notaciji:\n");
	scanf("%s", op);
	n = strlen(op);

	//Prolazak kroz komande
	for (i = 0; i < n; i++) {
		if (isDigit(op[i])) { //ako je učitana cifra
			push(charToDig(op[i]), &stek); //gura se na stek
		} else {
			//Ako je učitana operacija skidaju se 2 poslednja broja sa steka
			//na njima se izvršava data operacija i rezultat se vraća na vrh steka
			switch (op[i]) {
				case '*':
					op1 = pop(&stek);
					op2 = pop(&stek);
					res = op2 * op1;
					push(res, &stek);
					break;
				case '/':
					op1 = pop(&stek);
					op2 = pop(&stek);
					res = op2 / op1;
					push(res, &stek);
					break;
				case '+':
					op1 = pop(&stek);
					op2 = pop(&stek);
					res = op2 + op1;
					push(res, &stek);
					break;
				case '-':
					op1 = pop(&stek);
					op2 = pop(&stek);
					res = op2 - op1;
					push(res, &stek);
					break;
			}
		}
	}
	//Ispis rezultata
	printf("Rezultat operacija je: %d\n", pop(&stek));

	return 0;
}

//Pretvara karakter u cifru
int charToDig(char ch) {
	return ch - '0';
}

//Proverava da li je karakter cifra
int isDigit(char ch) {
	return (ch >= '0' && ch <= '9');
}

//Dodaje novi element na vrh steka
void push(TIP inf, SCVOR **vrh) {
	SCVOR *novi;
	novi = (SCVOR*) malloc(sizeof(SCVOR));
	novi->inf = inf;
	novi->sledeci = *vrh;
	*vrh = novi;
}

//Skida element sa vrha steka i vraća ga kao rezultat
TIP pop(SCVOR **vrh) {
	SCVOR *tmp;
	TIP pod;

	if(!(*vrh))
		return '\0';
	//Uzimamo informaciju sa vrha steka
	pod = (*vrh)->inf;
	//Sačuvamo element sa vrha liste da ga vratimo posle brisanja
	tmp = *vrh;
	//Prevežemo element sa vrha
	*vrh = tmp->sledeci;
	//obrišemo element sa vrha
	free(tmp);
	//Vratimo sačuvanu vrednost
	return pod;
}

//Vraća element sa vrha steka pri čemu ga ne skida
TIP top(SCVOR **vrh) {
	if (!(*vrh)) {
		return '\0';
	}
	return (*vrh)->inf;
}
