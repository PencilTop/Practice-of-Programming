#ifndef LIST_H
#define LIST_H

typedef struct Nameral Nameral;
struct Nameral {
    char    *name;
    int      value;
    Nameral *next;
};

Nameral *newitem(char *, int);
Nameral *addfront(Nameral *, Nameral *);
Nameral *addend(Nameral *, Nameral *);
Nameral *lookup(Nameral *, char *);
Nameral *delitem(Nameral *, char *);
void freeall(Nameral *);
void apply(Nameral *, void (*fn)(Nameral *, void *), void *);
void printnv(Nameral *, void *);
void inccounter(Nameral *, void *);

#endif