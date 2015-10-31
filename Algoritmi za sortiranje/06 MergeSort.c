/*
*	Program predstavlja implementaciju algoritma Insertion Sort
*	u programskom jeziku C, za potrebe predmeta PJISP
*	
*	OVAJ ALGORITAM ZA SORTIRANJE JE DOVOVOLJAN ZA VEĆU OCENU
*/

#include <stdio.h>
#define MAX 50

void MergeSort(int niz[], int n);
void merge(int A[], int L[], int R[], int duzL, int duzR);

int main() {
	int A[MAX];
	int n;
	int i, j;

	do {
		printf("Duzina niz [0<n<%d]: ", MAX);
		scanf("%d", &n);
	} while (n<=0 || n > MAX);

	printf("Unesite niz:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	MergeSort(A, n);

	printf("Sortiran niz:\n[");
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[n - 1]);
}

//Spaja nizove L duzine duzL i R duzine duzR u niz A duzine duzL+duzR
void merge(int A[], int L[], int R[], int duzL, int duzR)
{
	int i = 0; //brojac za L
	int j = 0; //brojac za R
	int k = 0; //brojac za A
	
	while (i < duzL && j < duzR)  //dok god ima elemenata u oba niza
	{
		if (L[i] < R[j])  //ukoliko je sledeci element u L manji od sledeceg elementa u R, u A se ubacuje sledeci element iz L.  Else: ako je R manji onda se on ubacuje. Takodje se povecavaju brojaci za A i za onaj niz iz kog smo ubacili element u A.
		{
			A[k] = L[i];
			k++;
			i++;
		}
		else 
		{
			A[k] = R[j];
			k++;
			j++;
		}
	}

	while (i < duzL)  //ukoliko je ostalo jos elemenata u L oni se ubacuju u A redom. Oni su medjuaobno vec sortirani a i iz prethodnih uslova imamo da su sigutno veci od svih u A, tako da ih mozemo redom ubaciti.   Sledeci while je isto to za R.
	{
		A[k] = L[i];
		k++;
		i++;
	}
	while (j < duzR) 
	{
		A[k] = R[j];
		k++;
		j++;	
	}

}

void MergeSort(int niz[], int n) {  //cepa ulazni niz u dva jednaka +-1 podniza sve dok oni ne budu imali samo po 1 element. tada poziva merge koja ih rredom spaja u veci i veci sortiran niz.

	if(n < 2) 
		return;
	int i;
	int mid = n / 2;   //broj elemenata u L
	int *L;  //levi podniz
	int *R;  //desni podniz

//alociranje memorije za niz. zauzimanje memorije na koju ce L i R da pokazuju
	L = (int*)malloc(mid*sizeof(int));  
	R = (int*)malloc((n-mid)*sizeof(int));
	//pravi L i R podniz
	for(i = 0; i < mid; i++) 
		L[i] = niz[i];
	for(i = mid; i < n; i++) 
		R[i-mid] = niz[i];
	 
	MergeSort(L, mid);  //poziva samu sebe za levi podniz L koji ima mid=n/2  clanova
	MergeSort(R, n-mid);
	merge(niz, L, R, mid, n-mid); //spaja levi i desni niz 
	free(L); //dealocira memoriju 
	free(R);
}