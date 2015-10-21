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
#define MAX 50

//Računa sumu niza
int suma (int n, int *niz) {
	int i;
	int c;
	for (i=0; i < n; i++)
		c += niz[i];
	return c;
}

//Računa srednju vrednost niza
double sr_vrednost (int n, int *niz) {
	double t = suma(n, niz) / (double)n;
	return t;
}

//Pomoćna metoda koja vraća minimum od 2 int-a
int min(int a, int b) {
	return a < b ? a : b;
}

//Nalazi minimalni elemenat niza
int mini (int n, int *niz) {
	int i, t_min;
	t_min = niz[0];
	for (i = 1; i < n; i++)
		t_min = min(t_min, niz[i]);
	return t_min;
}

//Pomoćna metoda koja vraća maksimum od 2 int-a
int max(int a, int b) {
	return a > b ? a : b;
}

//Nalazi maksimalni elemenat niza
int maxi (int n, int *niz) {
	int i, t_max;
	t_max = niz[0];
	for (i=1; i < n; i++)
		t_max = max(t_max, niz[i]);
	return(t_max);
}

//Ispisuje niz
void ispis (int n, int niz[50]) {
	int i;
	for (i=0; i < n; i++)
		printf("%d  ", niz[i]);
	printf("\n");
}

//Učitava niz
void ucitaj(int n, int *niz) {	
	int i;
	
	//Učitavanje niza
	printf("Unesite niz: ");
	for(i = 0; i < n; i++)
		scanf("%d", &niz[i]);
	int k;
}


int main() {
	int niz[MAX];
	int n, k;
	int i;
	
	do {
		printf("Unesite duzinu niza [0<n<50]: ");
		scanf("%d", &n);
	} while (n < 0 || n > MAX);
	
	ucitaj(n, niz);
	
	//Ispis i interakcija sa menijem
	do {
		printf("\n1 - Suma\n2 - Srednja vrednost\n3 - Min\n4 - Max\n5 - Ispis\n6 - Izlaz\n>> ");
		scanf("%d", &k);
		switch (k) {
			case 1 : 
				printf("Suma niza je: %d\n", suma(n,niz));
				break;
			case 2 : 
				printf("Srednja vrednost niza je: %lf\n", sr_vrednost(n,niz));
				break;
			case 3 : 
				printf("Minimalni ekemenat niza je: %d\n", mini(n,niz));
				break;
			case 4 : 
				printf("Maksimalni elemenat niza je: %d\n", maxi(n,niz));
				break;
			case 5 : 
				printf("Uneti niz je:\n");
				ispis(n, niz);
				break;	
			default :
				if (k != 6) { //6 je komanda za izlaz
					printf("Nepoznata komanda!!!\n");
				}
		}
	} while (k != 6); //Izlaz na uneto 6

	return 0;
}
