/* 
*	Zadatak 07
*	Napisati program za obrtanje redosleda
*	elemenata (zamena prvog sa poslednjim, drugog
*	sa pretposlednjim, itd.) zadatog niza celih
*	brojeva. Za pristup elementima niza koristiti
*	pokazivače. (Zadatak 4.2 iz zbirke L. K.)
*/

#include <stdio.h>
#define MAX 10

int main() {
	int A[MAX];
	int n;
	int *pA;
	int i;

	printf("n= ");
	scanf("%d", &n);

	//Učitavanje niza
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	//Postavljanje pokazivača na početak niza
	pA = A;

	/* 
	*	Kada je pokazivač definisan ovako
	*	važi sledeće:
	* 	A[i] = *(pA + i)
	*/

	//Menjanje mesta elementima
	for (i = 0; i < n / 2 + 1; i++) {
		int t = *(pA + i); //A[i]
		*(pA + i) = *(pA + n - i - 1); //A[i] = A[n-i-1]
		*(pA + n- i - 1) = t; //A[n-i-1]
	}

	//Ispis niza
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}