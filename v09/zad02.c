/*
*	Zadatak 02
*	Napisati program koji manipuliše strukturom
*	auto (Tema 6 - Strukture - Zadatak 3) i  ima
*	sledeće stavke u glavnom meniju:
*	-učitavanje podataka o automobilima iz datoteke u 
*	 binarno stablo
*	-dodavanje novog automobila u stablo, po marki 
*	 automobila
*	-pronalaženje automobila po marki i ispis ostalih 
*	 podataka
	-brisanje zadatog automobila
*	-snimanje podataka o automobilima iz binearnog 
*	 stabla u datoteku
*	-pronalaženje najnovijeg automobila sa kubikažom 
*	 ne većom od zadate i prikaz njegovih podataka na 
*	 standardni izlaz
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
	char marka[MAX];
	int kub;
	int god;
} automobil;

typedef struct cvor_st {
	automobil inf;
	struct cvor_st *desni;
	struct cvor_st *levi;
} BCVOR;


FILE* safe_open(char *ime, char *mod, int greska);
void ucitaj(FILE *f, BCVOR **p);
void dodaj(BCVOR **p, automobil a);
void ispisMarka(BCVOR *p, char *marka);
void izbrisi(BCVOR *p);
void ispisDatoteka(FILE *f, BCVOR *p);
automobil pronadji(BCVOR *p, int kub);
automobil max(automobil a, automobil b);

//Testiranje funkcija
int main() {
	BCVOR *p = NULL;

	FILE *ulaz = safe_open("automobili.txt", "r", 1);
	ucitaj(ulaz, &p);

	ispisMarka(p, "Fiat");

	FILE *izlaz = safe_open("izlaz.txt", "w", 2);
	ispisDatoteka(izlaz, p);

	int kub;
	printf("Unesite maksimalnu kubikazu: ");
	scanf("%d", &kub);
	automobil najnoviji  = pronadji(p, kub);
	printf("Najnoviji automobil je:\n%s %d %d\n", najnoviji.marka, najnoviji.kub, najnoviji.god);

	//Brisanje i zatvaranje fajlova
	izbrisi(p);
	p = NULL;
	fclose(ulaz);
	fclose(izlaz);

	return 0;
}

//Otvara fajl, ukoliko ne uspe izlazi iz programa sa greškom koja je prosleđena
FILE* safe_open(char *ime, char *mod, int greska) {
	FILE *f = fopen(ime, mod);
	if (f == NULL) { //ako fajl nije uspešno otvoren
		exit(greska); //izlaz iz programa
	}
	return f;
}

//Učitava automobil u stablo iz prosleđenog fajla
void ucitaj(FILE *f, BCVOR **p) {
	automobil a;
	while (fscanf(f, "%s %d %d", a.marka, &a.kub, &a.god) != EOF) {
		dodaj(p, a);
	}
}

//Dodaje automobil a u stablo p pri cemu je stablo sortirano
void dodaj(BCVOR **p, automobil a) {
	if (*p == NULL) {
		*p = (BCVOR*) malloc(sizeof(BCVOR));
		(*p)->inf = a;
	} else {
		if ((*p)->inf.marka > a.marka) {
			dodaj(&(*p)->levi, a);
		} else {
			dodaj(&(*p)->desni, a);
		}
	}
}

//Ispisuje sve automobile date marke
void ispisMarka(BCVOR *p, char *marka) {
	if (p != NULL) { //ako nije kraj stabla
		if (strcmp(p->inf.marka, marka) == 0) { //ukoliko su marke jednake
			printf("%s %d %d\n", p->inf.marka, p->inf.kub, p->inf.god); //ispisuje ga
		}
	}
}

//Briše stablo
void izbrisi(BCVOR *p) {
	if (p != NULL) { //ako nije list
		izbrisi(p->levi); //prvo brise levo podstablo
		izbrisi(p->desni); //onda brise desno
		free(p); // i na kraju cvor
		p = NULL;
	}
}

//Ispisuje sve iz stabla u zadati fajl sortirane po marki
void ispisDatoteka(FILE *f, BCVOR *p) {
	if (p != NULL) {  //ako nije kraj stabla
		ispisDatoteka(f, p->levi); //poziv za levo podstablo
		fprintf(f, "%s %d %d\n", p->inf.marka, p->inf.kub, p->inf.god); //ispis cvora
		ispisDatoteka(f, p->desni); //poziv za desno podstablo
	}
}

//Pronalazi najnoviji automobil sa kubikažom ne većom od prosleđene
automobil pronadji(BCVOR *p, int kub) {
	if (p == NULL) { //ako je kraj stabla
		automobil a;
		strcpy(a.marka, "");
		a.god = 0;
		a.kub = 0;
		return a; //vraća element koji je sigurno najmanji
	} else { //ako nije kraj stabla
		automobil leviA = pronadji(p->levi, kub); //najnoviji u levom podstablu
		automobil desniA = pronadji(p->desni, kub); //najnoviji u desnom podstablu
		automobil t = max(leviA, desniA); //najnoviji u oba podstabla
		if (p->inf.kub < kub) { //ako je kubikaža manja od zadate
			t = max(t, p->inf); //vraća čvor ako je manji od svih u podstablima
		}
		return t;
	}
}

//Vraća noviji od 2 automobila
automobil max(automobil a, automobil b) {
	if (a.god > b.god) {
		return a;
	} else {
		return b;
	}
}