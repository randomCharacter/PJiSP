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
	//scanf("%s", str);
	gets(str);

	printf("Broj reci: %d\n", brojReci(str));
	printf("Broj reci koje pocinju na m: %d\n", brojReciM(str));
}

int isChar(char ch) {
	return ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch < 'Z') || (ch >= '0' && ch <= '9'));
}

int brojReci(char *s) {
	int br = 0;
	int word = 0;
	while (*s) {
		if (!word && isChar(*s)) {
			word = 1;
			br++;
		} else if (word && !isChar(*s)) {
			word = 0;
		}
		s++;
	}

	return br;
}

int brojReciM(char *s) {
	int br = 0;

	if (*s == 'm' || *s == 'M') {
		br++;
	}
	s++;

	while(*s) {
		if (!isChar(*(s)) && (*(s+1) == 'm' || *(s+1) == 'M')) {
			br++;
		}
		s++;
	}
	return br;
}