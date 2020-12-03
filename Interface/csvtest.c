#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int csvgetline(FILE *);
char *unquote(char *);

char buf[200];
char *field[20];

int main(int argc, char *argv[]) {
    int i, nf, line = 0;

    while ((nf = csvgetline(stdin)) != -1) {
        if (line == 0) 
            printf("Title Line\n");
        else
            printf("Line %d\n", line);
        line++;
        for (i = 0; i < nf; i++)
            printf("\tfield[%d] = '%s'\n", i, field[i]);
    }   
    return 0;
}

int csvgetline(FILE *fin) {
    int nfield;
    char *p, *q;

    if (fgets(buf, sizeof(buf), fin) == NULL)
        return -1;
    nfield = 0;
    for (q = buf; (p = strtok(q, ",\n\r")) != NULL; q = NULL)
        field[nfield++] = unquote(p);
    return nfield;
}
char *unquote(char *p) {
    if (p[0] == '"') {
        if (p[strlen(p) - 1] == '"')
            p[strlen(p) - 1] = '\0';
        p++;
    }
    return p;
}