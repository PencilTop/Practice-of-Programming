#ifndef TREE_H
#define TREE_H

typedef struct Nameral Nameral;
struct Nameral {
    char    *name;
    int      value;
    Nameral *left;
    Nameral *right;
};

Nameral *newitem(char *, int);
Nameral *insert(Nameral *, Nameral *);
Nameral *lookup(Nameral *, char *name);
Nameral *nrlookup(Nameral *, char *name);
void printnv(Nameral *, void *);
void inccounter(Nameral *, void *);
void applyinorder(Nameral *, void (*fn)(Nameral *, void *), void *);
void applypostorder(Nameral *, void (*fn)(Nameral *, void *), void *);

#endif