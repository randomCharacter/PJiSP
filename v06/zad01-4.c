/*
*	Zadatak 01
*	Učitati dva kompleksna broja, realizovati sabiranje i 
*	oduzimanje kompleksnih brojeva.
*	•Za domaći realizovati vektorski proizvod
*/
#include <stdio.h>

struct kompBroj {
	double Re;
	double Im;
};

struct kompBroj sabiranje(struct kompBroj, struct kompBroj);
struct kompBroj oduzimanje(struct kompBroj, struct kompBroj);

int main() {
	struct kompBroj br1, br2, zbir, razlika;

	//Učitavanje prvog broja
	printf("Unesite realni deo 1. kompleksnog broja: ");
	scanf("%lf", &br1.Re);
	printf("Unesite imaginarni deo 1. kompleksnog broja: ");
	scanf("%lf", &br1.Im);
	//Učitavanje drugog broja
	printf("Unesite realni deo 2. kompleksnog broja: ");
	scanf("%lf", &br2.Re);
	printf("Unesite imaginarni deo 2. kompleksnog broja: ");
	scanf("%lf", &br2.Im);

	//Računanje zbira i razlike
	zbir = sabiranje(br1, br2);
	razlika = oduzimanje(br1, br2);

	//Ispis rezultata
	printf("Zbir kompleksnih brojeva je %.2lf+%.2lfi\n", zbir.Re, zbir.Im);
	printf("Razlika kompleksnih brojeva je %.2lf+%.2lfi\n", razlika.Re, razlika.Im);

	return 0;
}

//Vraća zbir 2 kompleksna broja
struct kompBroj sabiranje(struct kompBroj br1, struct kompBroj br2) {
	struct kompBroj rez; //rezultat

	rez.Re = br1.Re + br2.Re; //sabira realne delove
	rez.Im = br1.Im + br2.Im; //sabira imaginarne delove

	return rez;
}

//Vraća razliku 2 kompleksna broja
struct kompBroj oduzimanje(struct kompBroj br1, struct kompBroj br2) {
	struct kompBroj rez; //rezultat

	rez.Re = br1.Re - br2.Re; //oduzima realne delove
	rez.Im = br1.Im - br2.Im; //oduzima imaginarne delove

	return rez;
}
