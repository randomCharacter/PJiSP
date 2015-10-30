/*
*   Zadatak 08
*   Napisati funkciju int atof(char *s, float *f) koja string s
*   pretvara u realan broj i rezultat vraća u parametru f.
*   Realan broj se definiše kao niz od jedne ili više cifara,
*   nakon koje može biti tačka, nakon koje može biti još nula
*   ili više cifara. Ukoliko string nije dobro formatiran (npr.
*   sadrži dve tačke, zarez, slovo, itd) funkcija vraća 0. Inače,
*   vraća 1. U glavnom programu od korisnika učitati dužinu
*   stringa, pa i sam string, a zatim ga konvertovati u realan
*   broj i ispisati rezultat. Ukoliko je prilikom konverzije došlo
*   do greške (tj. ako string sadrži nedozvoljeni karakter),
*   ispisati odgovarajuću poruku.
*/
#include <stdio.h>
#include <string.h>
#define MAX 256

int ctoi(char, double*);
int atof(char*, double*);

int main() {
    char s[MAX];
    double br;

    printf("Unesite string:\n");
    scanf("%s", s);

    if (atof(s, &br)) { //ako je konverzija uspela
        printf("Vrednost stringa je: %lf\n", br);  
    } else { //konverzija nije uspela, vraćamo grešku
        printf("Uneti string nije broj!!!\n");
    }

    return 0;
}

//Konvertuje karakter u double
//Vraća 1 ako je konverzija uspešna, 0 ako nije
int ctoi(char c, double *x) {
    if (c >= '0' && c <= '9') { //Da li je karakter broj
        *x = c - '0';
        return 1;
    }
    return 0; //Ako karakter nije broj
}

//Konvertuje string u double
//Vraća 1 ako je konverzija uspešna, 0 ako nije
int atof(char *s, double *f) {
    double x = 0; //Broj koji ćemo kasnije vratiti
    double d = 1; //Decimala na koju upisujemo

    int znak = 1; //-1 ako je broj negativan, 1 ako je pozitivan

    double l;
    int iza = 0; //1 ako je prošao decimalni zarez
    
    //Proverava da li string počinje sa minusom
    if (*s == '-') { 
        znak = -1;
        s++;
    }

    while (*s) {
        if (*s == '.') {
            if (iza) {
                return 0; //drugi pronađen zarez, format nije dobar
            }
          iza++; //pronašao je zarez
        } else {
            if (ctoi(*s, &l)) { //ako je karakter broj
                if (!(iza)) { //celobrojni deo broja
                    x *= 10; //prethodni deo broja pomeramo udesno
                    x += l; //dodajemo novu cifru
                }
                else if (iza) {  //ako je prosla tačke, decimalni deo broja
                    d *= 10; //pomeramo na sledeću decimalu
                    x += l / d; //dodajemo novu cifru
                }
            } else { //ako je neki nedozvoljeni char
                return 0; 
            }
        }
            s++; //prelazak na sledeći karakter
    }
    *f = x * znak; //ukoliko je broj bio negaivan
    return 1;
}
