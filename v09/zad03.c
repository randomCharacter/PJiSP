/*
*	Zadatak 03
*	Napisati rekurzivnu funkciju koja:
*	-izračunava sumu elemenata nepraznog stabla    
*	 (TIP je float);
*	-izračunava broj elemenata binarnog stabla
*	-ispisuje elemente svih listova binarnog stabla
*	-ispituje da li se element E nalazi u binarnom stablu
*	-određuje maksimalnu vrednost u binarnom stablu 
*	-određuje pokazivač na maksimalnu vrednost u 
*	 binarnom stablu
*	-određuje maksimalnu dubinu nepraznog stabla, tj. 
*	 broj elemenata u najdužem putu od korena do 
*	 lista (koren tretirati kao 0-ti nivo)
*	-određuje broj elemenata na N-tom nivou binarnog 
*	 stabla (koren tretirati kao 0-ti nivo)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cvor_st {
	float inf;
	struct cvor_st *desni;
	struct cvor_st *levi;
} BCVOR;

float suma(BCVOR *koren);
int brElem(BCVOR *koren);
void ispis(BCVOR *koren);
void ispisList(BCVOR *koren);
int uStablu(float elem, BCVOR *koren);
float max(BCVOR *koren);
BCVOR* maxPok(BCVOR *koren);
int dubina(BCVOR *koren);
int brElemNivo(int nivo, BCVOR *koren);

int main() {
	int i;

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
	printf("Vase drvo je: ");
	ispis(drvo); //ispisuhe stablo
	printf("\nSuma elemenata: %.2f\n", suma(drvo));
	printf("Broj elemenata: %d\n", brElem(drvo));
	printf("Listovi: ");
	ispisList(drvo);
	printf("\n");
	for (i = 0; i < 10; i++) {
		if (uStablu(i, drvo)) {
			printf("%d se nalazi u stablu\n", i);
		} else {
			printf("%d se ne nalazi u stablu\n", i);
		}
	}
	printf("Dubina stabla: %d\n", dubina(drvo));
	for (i = 0; i < 10; i++) {
		printf("Broj elemenata na %i. nivou je: %d\n", i, brElemNivo(i, drvo));
	}

	return 0;
}

//Vraća sumu svih elemenata u stablu
float suma(BCVOR *koren) {
	if (koren)
		//Na vrednost cvora treba dodati sume levog i desnog podstabla
		return koren->inf + suma(koren->levi) + suma(koren->desni);
	else
		//Koren ne postoji, ništa ne treba sabrati
		return 0;
}

//Vraća broj elemenata u stablu
int brElem(BCVOR *koren) {
	if (koren) { //ako koren postoji
		return 1 + brElem(koren->levi) + brElem(koren->desni);
	} else { //ako nema korena
		return 0;
	}
}

//IspisA() iz v09/zad01.c
void ispis(BCVOR *koren) {
	if (koren) {
		printf("%.2f ", koren->inf);
		ispis(koren->levi);
		ispis(koren->desni);
	}
}

//Ispisuje samo elemente koji su listovi
void ispisList(BCVOR *koren) {
	if (koren) {
		if (!koren->levi && !koren->desni) { //proverava da li je list
			printf("%.2f ", koren->inf); //ispisuje ako jeste
		} else { //poziva sledeće ako nije
			ispisList(koren->levi);
			ispisList(koren->desni);
		}
	}
}

//Proverava da li je element u stablu
int uStablu(float elem, BCVOR *koren) {
	if (koren) {
		if (koren->inf == elem) { //ako je koren element koji tražimo
			return 1; //vraćamo potvrdnu informaciju
		} else { //ako koren nije tražimo u levom i desnom podstablu
			return (uStablu(elem, koren->levi) || uStablu(elem, koren->desni));
		}
	} else { //ako element ne postoji
		return 0;
	}

}

//Vraća veći od 2 floata
float max2(float x, float y) {
	return x > y ? x : y;
}

//Vraća maksimalni element
float max(BCVOR *koren) {
	if (koren) {
		return max2(koren->inf, max2(max(koren->levi), max(koren->desni)));
	}
}

int dubina(BCVOR *koren) {
	if (koren) {
		return 1 + max2(dubina(koren->levi), dubina(koren->desni)); //ako postoji element povećava broj koji je našao u podstablima za 1
	} else {
		return 0; //vraća 0 ako nema elementa
	}
}

int brElemNivo(int nivo, BCVOR *koren) {
	if (koren) {
		if (nivo == 1) { //ako je na pravom nivou
			return 1; //vraća da je našao element
		} else { //ako nije
			return brElemNivo(nivo - 1, koren->levi) + brElemNivo(nivo - 1, koren->desni); //ide dublje
		}
	} else {
		return 0; //ako element ne postoji
	}
}