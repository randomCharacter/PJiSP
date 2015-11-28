#include <stdio.h>
#include <stdlib.h>

typedef struct Tcvor_s {
    struct Tcvor_s *sledeci;
    char znak;
} Tcvor;

int postoji(Tcvor *p, char ch) {
    while (p->next) {
        if (p->znak == ch) {
            return 1;
        }
        p = p->sledeci;
    }
    return 0;
}

void brisi(Tcvor *p, char ch) {
    while (p->next) {
        if (p->next)
    }
}

void unos(Tcvor *p, char ch) {
    if (!postoji(p, ch)) {
        Tcvor *t = (Tcvor *) malloc(sizeof(Tcvor));
        t->sledeci = NULL;
        t->znak = ch;
        while (p->sledeci) {
            p = p->sledeci;
        }
        p->sledeci = t;
    }
}

void

int main(int argc, char *argv[]) {
    Tcvor *p;

    return 0;
}
