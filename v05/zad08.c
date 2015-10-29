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

    if (atof(s, &br)) {
        printf("Vrednost stringa je: %lf\n", br);  
    } else {
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
    double d = 1; 

    int znak = 1; //-1 ako je broj negativan

    double l;
    int iza = 0; //1 ako je prošao decimalni zarez
    double mnoz = 10;
    //Proverava da li string počinje sa minusom
    if (*s == '-') { 
        znak = -1;
        s++;
    }

    while (*s) {
        if (*s == '.') {
            if (iza) {
                return 0; //Drugi pronađen zarez, format nije dobar
            }
          iza++; //Pronašao je zarez
        } else {
            if (ctoi(*s, &l)) { //Ako je karakter broj
                if (!(iza)) { //Celobrojni deo broja
                    x *= mnoz;
                    x += l;
                    //mnoz *= 10;
                }
                else if (iza) {  //ako je prosla tačke, decimalni deo broja
                    d *= 10;
                    x += l / d; 
                }
            } else { //ako je neki nedozvoljeni char
                return 0; 
            }
        }
            s++; //Prelaz na sledeće slovo
    }
    *f = x * znak;
    return 1;
}
