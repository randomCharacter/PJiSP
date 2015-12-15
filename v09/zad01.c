/*
*	Zadatak 01
*	Napisati funkciju void ispis(BCVOR *koren) 
*	koja rekurzivno ispisuje sadržaj stabla
*	a) 	prvo ispisati sadržaj čvora a zatim njegovih 
*		podčvorova sa leva na desno
*	b)	prvo ispisujemo sadržaj levog podstabla, zatim 
*		samog čvora i na kraju desnog podstabla 
*		(obilazak sa leva na desno)
*	c)	obilazak sa desna na levo
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cvor_st {
	int inf;
	struct cvor_st *desni;
	struct cvor_st *levi;
} BCVOR;

void ispisA(BCVOR *koren);
void ispisB(BCVOR *koren);
void ispisC(BCVOR *koren);

//Testiranje funkcija
int main() {
	//Kreiranje prostog stabla za svrhe testiranja
	BCVOR *drvo = (BCVOR*) malloc(sizeof(BCVOR));
	drvo->inf = 3;
	drvo->levi = (BCVOR*) malloc(sizeof(BCVOR));
	drvo->desni = (BCVOR*) malloc(sizeof(BCVOR));

	BCVOR *t; //Pomoćni pokazivač
	//levi deo
	t = drvo->levi;
	t->inf = 4;
	t->levi = (BCVOR*) malloc(sizeof(BCVOR));
	//levi deo levog dela
	t = t->levi;
	t->inf = 2;

	//desni deo
	t = drvo->desni;
	t->inf = 5;
	t->levi = (BCVOR*) malloc(sizeof(BCVOR));
	t->desni = (BCVOR*) malloc(sizeof(BCVOR));
	t->levi->inf = 4; //levi deo desnog dela
	t->desni->inf = 1;
	printf("%s%s%s%s%s", 
	"     3       \n",
	"    / \\     \n",
	"   4   5     \n",
	"  /   / \\   \n",
	" 2   4   1   \n" );

	//Poziv funkcija
	printf("cvor->levi->desni:\n");
	ispisA(drvo);
	printf("\nlevi->čvor->desni:\n");
	ispisB(drvo);
	printf("\ndesni->cvor->levi:\n");
	ispisC(drvo);
	printf("\n");
	return 0;
}

//Ispisuje stablo u poredku: čvor->levi->desni
void ispisA(BCVOR *koren) {
	if (koren != NULL) {
		printf("%d ", koren->inf);
		ispisA(koren->levi);
		ispisA(koren->desni);
	}
}

//Ispisuje stablo u poredku: levi->čvor->desni
void ispisB(BCVOR *koren) {
	if (koren != NULL) {
		ispisB(koren->levi);
		printf("%d ", koren->inf);
		ispisB(koren->desni);
	}
}

//Ispisuje stablo u poredku: desni->čvor->levi
void ispisC(BCVOR * koren) {
	if (koren != NULL) {
		ispisC(koren->desni);
		ispisC(koren->levi);
		printf("%d ", koren->inf);
	}
}