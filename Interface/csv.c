#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

char *csvgetline(FILE *fin) {
    int i, c;
    char *newl, *news;
    if (line == NULL) {
        maxline = maxfield = 1;
        line = (char *)malloc(maxline);
        sline = (char *)malloc(maxline);
        field = (char **)malloc(maxfield*sizeof(field[0]));
        if (line == NULL || sline == NULL || field == NULL) {
            reset();
            return NULL;
        } 
    }
    for (i = 0; (c = getc(fin)) != EOF && !endofline(fin, c); i++) {
        if (i >= maxline - 1) {
            maxline *= 2;
            newl = (char *) realloc(line, maxline);
            news = (char *) realloc(sline, maxline);
            if (newl == NULL || news == NULL) {
                reset();
                return NULL;
            }
            line = newl;
            sline = news;
        }
        line[i] = c;
    }
    line[i] = '\0';
    if (split() == NOMEM) {
        reset();
        return NULL;
    }
    return (c == EOF && i == 0) ? NULL : line;
        
}
static void reset(void) {
    free(line);
    free(field);
    line = NULL;
    sline = NULL;
    field = NULL;
    maxline = maxfield = nfield = 0;
}
static int endofline(FILE *fin, int c) {
    int eol;
    eol = (c == '\r' || c == '\n')
    if (c == '\r') {
        c = getc(fin);
        if (c != '\n' && c != EOF) 
            ungetc(c, fin);
    }
    return eol;
}