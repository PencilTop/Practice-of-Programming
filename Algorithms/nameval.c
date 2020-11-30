#include <stdio.h>
#include <string.h>
#define NELEMS(array) (sizeof(array) / sizeof(array[0]))
typedef struct Nameral Nameral;
struct Nameral {
    char *  name;
    int     value;
};
int lookup(char*, Nameral[], int);
int main(int argc, char *argv[]) {
    /* HTML charactor, e.g. AELig is ligature of A and E. */
    /* Values are Unicode/ISO10646 encoding. */
    Nameral htmlchars[] = {
        "AElig",    0x00c6,
        "Aacute",   0x00c1,
        "Acirc",    0x00c2,
        "zeta",     0x03b6,
    };
    printf("The HTML Table has %ld words.\n", NELEMS(htmlchars));

    char *name = "Aacute";
    printf("%sfind %s in htmlchars.\n", lookup(name, htmlchars, NELEMS(htmlchars)) >= 0 ?  "" : "can't ", name);
    return 0;
}

int lookup(char *name, Nameral tab[], int ntab) {
    int low, mid, high, cmp;
    low = 0;
    high = ntab - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        cmp = strcmp(name, tab[mid].name);
        if (cmp < 0) 
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else
            return mid; 
    }
    return -1;
}





