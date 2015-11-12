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

int main(int brArg, char *arg[]) {
	student s[MAX];
	int n = 0;
	FILE *f = fopen(arg[1], "r");

	Ucitaj(s, f, &n);

	student najvisi = Najvisi(s, n);
	Ispisi(najvisi, "najvisi.txt");

	student najnizi = Najnizi(s, n);
	Ispisi(najnizi, "najnizi.txt");

	fclose(f);

	return 0;
}

void Ucitaj(student s[], FILE *f, int *n) {
	while (fscanf(f, "%d", &s[*n].index) != EOF && fscanf(f, "%s", s[*n].ime) != EOF && fscanf(f, "%lf", &s[*n].ocena) != EOF) {
		(*n)++;
	}
}

student Najvisi(student s[], int n) {
	int i;
	double max; 
	int maxI;
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

student Najnizi(student s[], int n) {
	int i;
	double min;
	int minI;
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

void Ispisi(student s, char *file) {
	FILE *f = fopen(file, "w");
	fprintf(f, "INDEX: %d\n", s.index);
	fprintf(f, "IME  : %s\n", s.ime);
	fprintf(f, "OCENA: %.2lf\n", s.ocena);
	fclose(f);
}