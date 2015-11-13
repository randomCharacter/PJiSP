/*
*	Zadatak 05
*	Iz ulazne datoteke učitati niz studenata koji su
*	položili ispit (indeks, ime, ocena). Koristiti funkcije,
*	ime ulazne datoteke prihvatiti kroz argumente
*	komandne linije.
*	• U izlaznu datoteku "najvisi.txt" ispisati podatke o
*	studentu sa najvišim prosekom
*	• U izlaznu datoteku "najnizi.txt" ispisati podatke o
*	studentu sa najnižim prosekom
*	• Na standardnom izlazu ispisati prosečnu ocenu
*	svih studenata
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 256

//Definicija tipa student
typedef struct stud {
	int index;
	char ime[MAX];
	double ocena;
} student;

void Ucitaj(student*, FILE*, int*);
student Najvisi(student[], int);
student Najnizi(student[], int);
void Ispisi(student, char*);
double Ocena(student[], int);

int main(int brArg, char *arg[]) {
	student s[MAX]; //niz studenata
	int n = 0;
	FILE *f;
	double prOc; //prosečna ocena svih studenata

	//Ukoliko je korisnik uneo manje od 4 argumenta ispisuje se pomoć:
	if (brArg < 2) {
		printf("Kao argument pozivanja programa unesite ime fajla u kojem se nalaze podaci o studentima.\n");
		return 0;
	}

	
	if ((f = fopen(arg[1], "r")) == NULL) { //otvaranje fajla za čitanje
		printf("Fajl ne postoji!!!\n");
		exit(EXIT_FAILURE); //prekid rada ukoliko fajl ne postoji
	}

	Ucitaj(s, f, &n); //čitanje studenata u fajl

	student najvisi = Najvisi(s, n);
	Ispisi(najvisi, "najvisi.txt"); //ispis studenta sa najvišom ocenom

	student najnizi = Najnizi(s, n);
	Ispisi(najnizi, "najnizi.txt"); //ispis studenta sa najnižom ocenom

	prOc = Ocena(s, n); //računanje prosečne ocene
	printf("Prosecna ocena svih studenata je: %.2lf\n", prOc); //ispis prosečne ocene

	fclose(f); //zatvaranje fajla na kraju programa

	return 0;
}

//Učitava niz studenata iz fajla i računa dužinu niza
void Ucitaj(student s[], FILE *f, int *n) {
	while (fscanf(f, "%d", &s[*n].index) != EOF && fscanf(f, "%s", s[*n].ime) != EOF && fscanf(f, "%lf", &s[*n].ocena) != EOF) { //dok ima šta da učita
		(*n)++; //povećava broj studenata
	}
}

//Vraća studenta sa najvišom ocenom iz niza
student Najvisi(student s[], int n) {
	int i;
	double max; 
	int maxI;
	max = s[0].ocena;
	maxI = 0;

	// v02/zad15.c
	for (i = 1; i < n; i++) {
		if (s[i].ocena > max) {
			max = s[i].ocena;
			maxI = i;
		}
	}

	return s[maxI];
}

//Vraća studenta sa najnižom ocenom iz niza
student Najnizi(student s[], int n) {
	int i;
	double min;
	int minI;
	min = s[0].ocena;
	minI = 0;

	// v02/zad15.c
	for (i = 1; i < n; i++) {
		if (s[i].ocena < min) {
			min = s[i].ocena;
			minI = i;
		}
	}

	return s[minI];
}

//Ispisuje podatke o studentu u fajl
void Ispisi(student s, char *file) {
	FILE *fč
	if ((f = fopen(file, "w")) == NULL) {
		printf("Greska pri pokusaju kreiranja fajla %s\n", file);
		exit(EXIT_FAILURE);
	}
	fprintf(f, "INDEX: %d\n", s.index);
	fprintf(f, "IME  : %s\n", s.ime);
	fprintf(f, "OCENA: %.2lf\n", s.ocena);
	fclose(f);
}

//Računa prosečnu ocenu svih studenata
double Ocena(student s[], int n) {
	double oc = 0.0;
	int i;

	for (i = 0; i < n; i++) {
		oc += s[i].ocena;
	}

	return oc / n;
}