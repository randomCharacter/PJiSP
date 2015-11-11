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
#define MAX 256

struct student {
	int index;
	char ime[MAX];
	int ocena;
};

struct student Ucitaj(FILE*);
struct student Najvisi(struct student[], int);
struct student Najnizi(struct student[], int);
void Ispisi(struct student, char*);

int main(int brArg, char *arg[]) {
	struct student s[MAX];
	int n = 0;
	FILE *f = fopen(arg[1], "r");

	while(f) {
		s[n++] = Ucitaj(f);
	}

	struct student najvisi = Najvisi(s, n);
	Ispisi(najvisi, "najvisi.txt");

	struct student najnizi = Najnizi(s, n);
	Ispisi(najnizi, "najnizi.txt");

	fclose(f);

	return 0;
}

struct student Ucitaj(FILE *f) {
	struct student s;
	fscanf(f, "%d", &s.index);
	fscanf(f, "%s", s.ime);
	fscanf(f, "%d", &s.ocena);
	return s;
}

struct student Najvisi(struct student s[], int n) {
	int i;
	int max, maxI;
	max = s[0].ocena;
	maxI = 0;

	for (i = 1; i < n; i++) {
		if (s[i].ocena > max) {
			max = s[i].ocena;
			maxI = i;
		}
	}

	return s[maxI];
}

struct student Najnizi(struct student s[], int n) {
	int i;
	int min, minI;
	min = s[0].ocena;
	minI = 0;

	for (i = 1; i < n; i++) {
		if (s[i].ocena < min) {
			min = s[i].ocena;
			minI = i;
		}
	}

	return s[minI];
}

void Ispisi(struct student s, char *file) {
	FILE *f = fopen(file, "w");
	fprintf(f, "%d\n", s.index);
	fprintf(f, "%s\n", s.ime);
	fprintf(f, "%d\n", s.ocena);
	fclose(f);
}