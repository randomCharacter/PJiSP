/*  
*	Zadatak 06
*	Napisati C program koji računa sumu prvih n 
*	prirodnih brojeva, pri čemu se n zadaje na 
*	početku programa.
* 	[for]
*/

#include <stdio.h>

int main() {
	int n;
	int s = 0; //Suma, na početku 0
	int i; //Brojač koji prolazi kroz prvih n brojeva

	printf("n=");
	scanf("%d", &n);

	for(i = 0; i <= n; i++) {
		s += i; //U svakom prolazu suma se poveca za i
	}

	printf("Suma je %d\n", s);

	return 0;
}