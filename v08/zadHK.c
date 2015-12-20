/*
*   Zadatak HK
*   •“Hanojska kula”. Na ploci se nalaze tri stuba. Na
*   levom stubu se  nalazi n diskova ciji se
*   poluprecnici smanjuju iduci ka vrhu stuba.
*   Napisati program kojim se ispisuju koraci
*   potrebni da se diskovi sa levog stuba prebace na
*   desni tako da se u jednom koraku moze prebaciti
*   samo jedan disk. Zabranjeno je staviti veci disk
*   preko manjeg
*/
#include <stdio.h>

void kula(int disk, int ulaz, int izlaz, int pom);

int main() {
    int n;
    do {
        printf("Unesite broj diskova [n>0]: ");
        scanf("%d", &n);
    } while (n < 0);
    printf("Na samom pocetku diskovi se nalaze na [1]\n");
    printf("Treba ih prebaciti na [2] uz pomoc [3]\n");
    kula(n, 1, 2, 3);
}

void kula(int disk, int ulaz, int izlaz, int pom) {
    if (disk == 1) {
        printf("disk %d [%d]->[%d]\n",disk, ulaz, izlaz);
    } else {
        kula(disk - 1, ulaz, pom, izlaz);
        printf("disk %d [%d]->[%d]\n", disk, ulaz, izlaz);
        kula(disk - 1, pom, izlaz, ulaz);
    }
}
