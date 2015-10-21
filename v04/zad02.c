/*
*	Zadatak 02
*	Dat je niz od maksimalno 30 celobrojnih
*	elemenata. Učitati n elemenata,a zatim omogućiti
*	korisniku da bira neku od sledećih radnji:
*	izračunavanje sume elemenata niza, računanje
*	srednje vrednosti elemenata, nalaženje minimuma,
*	nalaženje maksimuma. Omogućiti izvršavanje više
*	radnji (jedna za drugom).
*/

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 50

void unosNiza(int *, int *);
int suma(int *, int);
double avg(int *, int);
void ispis(int *, int);
int mini(int *, int);
int maxi(int *, int);

int main() {
	int a[MAX_SIZE];
	int n = 0, k;
			
	//Ispis i interakcija sa menijem
	do {
		printf("    Opcije:\n\t1. Unos elemenata niza.\n\t2. Izracunavanje sume\n\t3. Racunanje srednje vrednosti\n\t4. Ispis niza\n\t5. Nalazenje maksimalnog elementa niza\n\t6. Nalazenje minimalnog elementa niza\n\t7. Izlaz iz programa\n\t>> ");
		scanf("%d", &k);
		switch (k) {
			case 1 : 
				unosNiza(a, &n);
				break;
			case 2 : 
				printf("Suma je: %d.\n\n", suma(a, n));
				break;
			case 3 : 
				printf("Srednja vrednost je: %.2lf.\n", avg(a, n));
				break;
			case 4 : 
				ispis(a, n);
				break;	
			case 5 :
				printf("Maksimalni element niza je: %d.\n\n", maxi(a, n));
				break;
			case 6 :
				printf("Minimalni element niza je: %d.\n\n", mini(a, n));
				break;
			default :
				if (k != 7) { //7 je komanda za izlaz
					printf("Nepoznata komanda!!!\n");
				}
		}
	} while (k != 7); //Izlaz na uneto 7

	return 0;
}

//Učitava niz
void unosNiza(int *A, int *n) {
	int i;
	
	do {
		printf("Unesite duzinu niza [0<n<50]: ");
		scanf("%d", n);
	} while (*n < 0 || *n > MAX_SIZE);
	
	//Učitavanje niza
	printf("Unesite niz: ");
	for(i = 0; i < *n; i++)
		scanf("%d", &A[i]);
}

//Računa sumu niza
int suma(int *A, int n) {
	int i;
	int s = 0;
	for (i = 0; i < n; i++)
		s += A[i];
	return s;
}

//Računa srednju vrednost niza
double avg(int *A, int n) {
	double t = suma(A, n) / (double)n;
	return t;
}

//Pomoćna metoda koja vraća minimum od 2 int-a
int min(int a, int b) {
	return a < b ? a : b;
}

//Nalazi minimalni elemenat niza
int mini(int *A, int n) {
	int i, t_min;
	t_min = A[0];
	for (i = 1; i < n; i++)
		t_min = min(t_min, A[i]);
	return t_min;
}

//Pomoćna metoda koja vraća maksimum od 2 int-a
int max(int a, int b) {
	return a > b ? a : b;
}

//Nalazi maksimalni elemenat niza
int maxi(int *A, int n) {
	int i, t_max;
	t_max = A[0];
	for (i=1; i < n; i++)
		t_max = max(t_max, A[i]);
	return(t_max);
}

//Ispisuje niz
void ispis(int *A, int n) {
	int i;
	for (i=0; i < n; i++)
		printf("%d  ", A[i]);
	printf("\n");
}



