/*  
*	Zadatak 06
*	Napisati C program koji računa sumu prvih n 
*	prirodnih brojeva, pri čemu se n zadaje na 
*	početku programa.
* 	[while]
*/

#include <stdio.h>

int main() {
	int n;
	int s = 0; //Suma, na početku 0
	int i; //Brojač koji prolazi kroz prvih n brojeva

	printf("n=");
	scanf("%d", &n);

	i = 1; //Postavljanje brojača na početak
	while(i <= n) {
		s += i; //U svakom prolazu suma se poveca za i
		i++; //U svakom prolazu i se poveca za 1
	}
	
	printf("Suma je %d\n", s);

	return 0;
}