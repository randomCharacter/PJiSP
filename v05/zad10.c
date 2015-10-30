/*
*	Zadatak 10
*	U datom stringu:
*	a) odrediti broj reči;
*	b) broj reči koje počinju sa M;
*	c) broj reči čiji su prvi i poslednji znak jednaki;
*	d) odrediti dužinu najkraće reči
*/
#include <stdio.h>
#include <string.h>
#define MAX 256

int brojReci(char*);
int brojReciM(char*);
int brojReciIstogSlova(char*);
int minRec(char*);

int main() {
	char str[MAX];

	printf("Unesite string:\n");
	gets(str); //Čita string do entera, uključujući i <SPACE>; scanf čita samo do razmaka

	printf("Broj reci: %d\n", brojReci(str));
	printf("Broj reci koje pocinju na m: %d\n", brojReciM(str));
	printf("Broj reci koje pocinju i zavrsavaju se istim slovom: %d\n", brojReciIstogSlova(str));
	printf("Broj karaktera u najkracoj reci: %d\n", minRec(str));

	return 0;
}

//Proverava da li je uneti karakter slovo ili broj
int isChar(char ch) {
	return ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch < 'Z') || (ch >= '0' && ch <= '9'));
}

//Prebrojava broj reči koje se nalaze u stringu
//Reči su odvojene bilo kojim karakterom koji nije slovo ili broj
int brojReci(char *s) {
	int br = 0; //brojač
	int word = 0; //1 ako je trenutno u reči, 0 ako nije

	//Prebrojavanje
	while (*s) { 
		if (!word && isChar(*s)) { //ako nije u reči, a nailazi na slovo ili broj
			word = 1; //ulazi u reč
			br++; //broj reči se povećava za 1
		} else if (word && !isChar(*s)) { //ako je bio u reči i nailazi na karakter koji nije slovo ili broj
			word = 0; //izlazi iz reči
		}
		s++; //prelazak na sledeći karakter
	}

	return br;
}

//Broji reči koje počinju sa slovom "M" u stringu
int brojReciM(char *s) {
	int br = 0; //brojač

	if (*s == 'm' || *s == 'M') {  //ako string počinje sa M
		br++; //brojač se povećava za 1
	}
	s++; //prelazak na sledeći karakter

	//Prebrojavanje
	while(*s) {
		if (!isChar(*s) && (*(s+1) == 'm' || *(s+1) == 'M')) { //ako trenutni karakter nije slovo ili broj, a sledeći je slovo M
			br++; //broj reči se povećava za 1
		}
		s++; //prelazak na sledeći karakter
	}
	return br;
}

//Vraća broj reči koje počinju i završavaju se istim slovom u stringu
int brojReciIstogSlova(char *s) {
	int br = 0; //brojač
	int word = 0; //1 ako je trenutno u reči, 0 ako nije
	char lChar; //karakter kojim je počela poslednja reč
	
	//Prebrojavanje
	while (*(s)) {
		if (word && !isChar(*(s+1))) { //ako je u reči i sledeći karakter nije slovo ili broj
			//Naišli smo na poslednji karakter reči
			if (lChar == *s) { //ako je jednak početnom karakteru
				br++; //brojač se povećava za 1
			}
		} else if (!word && isChar(*s)) { //ako nije u reči i naišao je karakter
			lChar = *s;	//karakter postaje prvo slovo nove reči
			word = 1; //ulazi u reč
		} 
		if (!isChar(*s)) { //ako nije u pitanju karakter
			word = 0; //izlazi iz reči
		}
		s++; //prelazak na sledeći karakter
	}

	return br;
}

//Vraća dužinu reči sa minimalnim brojem karaktera u stringu
int minRec(char *s) {
	int min = MAX; //Pretpostavljamo da je ceo string jedna reč
	int d = 0; //Dužina trenutne reči
	int word = 0; //1 ako je trenutno u reči, 0 ako nije

	//Prebrojavanje
	while (*s) {
		if (isChar(*s)) { //ako je trenutni karakter slovo ili broj
			if (word) { //i trenutno je u reči
				d++; //dužina reči se povećava
			} else { //ako nije u reči
				d = 1; //dužina reči je 1
			}
			word = 1; //ulazak u reč
		} else { //ako trenutni karakter nije slovo ili broj
			if (d < min && d > 0) { //ako je dužina prethodne reči manja od minimalne i pozitivna
				min = d; //minimalna dužina postaje dužina date reči
			}
			word = 0; //izlazak iz reči
		}
		s++; //prelazak na sledeći karakter
	}

	//Za poslednju reč, ako se string ne završava sa <SPACE>
	if (d < min) { //i ako je dužina manja od minimalne
		min = d; //minimalna se menja
	}

	return min;
}