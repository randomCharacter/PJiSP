/*  
*	Zadatak 05
*	Tri tačke su zadate koordinatama u ravni. Napisati program 
*	kojim se izračunava površina paralelograma čiji su vrhovi 
*	date tačke
*/

#include <stdio.h>
#include <math.h>

int main() {
	double Ax, Ay, Bx, By, Cx, Cy;
	double a, b, c;
	double s, P;

	printf("Unesite koordinate tacke A:\n");
	scanf("%lf %lf", &Ax, &Ay);
	printf("Unesite koordinate tacke B:\n");
	scanf("%lf %lf", &Bx, &By);
	printf("Unesite koordinate tacke C:\n");
	scanf("%lf %lf", &Cx, &Cy);

	//Računanje dužina stranica
	a = sqrt(pow(Bx - Cx, 2) + pow(By - Cy, 2));
	b = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2));
	c = sqrt(pow(Ax - Bx, 2) + pow(Ay - By, 2));
	//Računanje površine po Heronovom obrascu (v01/zad01)
	s = (a + b + c) / 2;
	P = sqrt(s * (s - a) * (s - b) * (s - c));

	printf("P=%.2lf\n", P);

	return 0;
}