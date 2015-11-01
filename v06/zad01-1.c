/*
*	Zadatak 01
*	Učitati niz tačaka u ravni (maksimalno 30). Naći 
*	tačku koja je najbliža koordinatnom početku. 
*	Koristiti funkcije.
*/
#include <stdio.h>
#include <math.h>
#define MAX 30

//Definicija tačke iz primera 1
struct tacka {
	float x;
	float y;
};

struct tacka najbliza(struct tacka t[], int n);
float rastojanje(struct tacka, struct tacka);

int main() {
	struct tacka t[MAX]; //Niz tačaka
	int n; //Broj elemenata niza
	int i;

	printf("Unesite broj tacaka [n<=%d]: ", MAX);
	do {
		scanf("%d", &n);
	} while (n <= 0 || n > MAX);

	//Učitavanje tačaka
	for (i = 0; i < n; i++) {
		printf("Unesite koordinate tacke %d:\n", i + 1);
		scanf("%f %f", &t[i].x, &t[i].y);
	}

	//Najbliža tačka
	struct tacka naj = najbliza(t, n);

	printf("Najbliza tacka je: %.2f %.2f\n", naj.x, naj.y);

	return 0;
}

//Vraća rastojanje između dve tačke u ravni
float rastojanje(struct tacka t1, struct tacka t2) {
	return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}

//Vraća najbližu tačku koordinatnom početku iz niza
struct tacka najbliza(struct tacka t[], int n) {
	float d[MAX]; //i-ti član niza je rastojanje i-te tačke od koordinatnog početka
	float min; //minimalno rastojanje
	int minI; //index tačke sa minimalnim rastojanjem
	int i;

	//Kreiranje tačke O koja predstavlja koordinatni početak
	struct tacka O;
	O.x = 0; 
	O.y = 0;

	//Računanje rastojanja
	for (i = 0; i < n; i++) {
		d[i] = rastojanje(O, t[i]);
	}

	//Traženje minimuma (v02/zad15.c)
	min = d[0];
	minI = 0;
	for (i = 1; i < n; i++) {
		if (d[i] < min) {
			min = d[i];
			minI = i;
		}
	}

	//Vraćanje tražene tačke
	return t[minI];
}