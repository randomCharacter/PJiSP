/*
*	Zadatak 07
*	Realizovati množenje i deljenje pomoću 
*	sabiranja i oduzimanja.
*/

#include <stdio.h>

int main() {
	char op;
	int rez,a,b,i;

	printf("Unesite operaciju (* ili /): ");
	scanf("%c", &op);
	
	
	switch(op)
	{
		//Množenje
		case '*':
			printf("Unesite dva broja: ");
			scanf("%d %d", &a,&b);
			rez = 0;
			for (i = 0; i < b; ++i) {
				rez += a;
			}			
			printf("Rezultat je: %d\n", rez);
			break;
		//Deljenje
		case '/':
			printf("Unesite deljenik: ");
			scanf("%d", &a);
			do { 
			//Provera ukoliko korisnik pokusava da deli nulom
				printf("Unesite delilac: ");
				scanf("%d", &b);
			} while(b == 0);
			rez = 0;
			while(a>=b)	{
				rez +=1;
				a -= b;
			}
			printf("Rezultat je: %d\n", rez);
			break;
		//Pogrešan karakter
		default:
			printf("Pogresna operacija!\n");			
	}

	return 0;
}
