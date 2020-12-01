#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


int main(int argc, char *argv[]) {
    Nameral *treep;
    treep = insert(treep, newitem("smiley", 0x263A));
    treep = insert(treep, newitem("zeta", 0x03b6));
    treep = insert(treep, newitem("Aacute", 0x00c1));
    treep = insert(treep, newitem("Acirc", 0x00c2));
    treep = insert(treep, newitem("AElig", 0x00c6));
    applypostorder(treep, printnv, "%s: %x\n");
    return 0;
}
Nameral *newitem(char *name, int value) {
    Nameral *p;
    p = (Nameral *) malloc(sizeof(Nameral));
    p -> name = name;
    p -> value = value;
    p -> left =  NULL;
    p -> right = NULL;
    return p;
}
Nameral *insert(Nameral *treep, Nameral *newp) {
    int cmp;
    if (treep == NULL)
        return newp;
    cmp = strcmp(newp -> name, treep -> name);
    if (cmp == 0) 
        printf("insert: dulplicated entry %s ignored", newp -> name);
    else if (cmp < 0)
        treep -> left = insert(treep -> left, newp);
    else
        treep -> right = insert(treep -> right, newp);
    return treep;
}
Nameral *lookup(Nameral *treep, char *name) {
    int cmp;
    if (treep == NULL)
        return NULL;
    cmp = strcmp(name, treep -> name);
    if (cmp == 0)
        return treep;
    else if (cmp < 0)
        return lookup(treep -> left, name);
    else
        return lookup(treep -> right, name);
}
Nameral *nrlookup(Nameral *treep, char *name) {
    return NULL;
}
void applyinorder(Nameral *treep, void (*fn)(Nameral *, void *), void *args) {
    if (treep == NULL)
        return;
    applyinorder(treep -> left, fn, args);
    (*fn)(treep, args);
    applyinorder(treep -> right, fn, args);
}
void applypostorder(Nameral *treep, void (*fn)(Nameral *, void *), void *args){
    if (treep == NULL)
        return;
    applypostorder(treep -> left, fn, args);
    applypostorder(treep -> right, fn, args);
    (*fn)(treep, args);
}
void printnv(Nameral *p, void *arg) {
    char *fmt;
    fmt = (char *)arg;
    printf(fmt, p -> name, p -> value);
}
void inccounter(Nameral *p, void *arg) {
    int *ip;
    ip = (int *) arg;
    (*ip)++;
}