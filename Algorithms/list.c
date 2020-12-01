#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>

int main(int argc, char *argv[]) {
    /*
    Nameral htmlchars[] = {
        "AElig",    0x00c6,
        "Aacute",   0x00c1,
        "Acirc",    0x00c2,
        "zeta",     0x03b6,
    };
    */
    Nameral *item0 = newitem("AElig", 0x00c6);
    Nameral *listnp = addfront(item0, newitem("Aacute", 0x00c1));
    listnp = addend(listnp, newitem("Acirc", 0x00c2));
    listnp = addfront(listnp, newitem("zeta", 0x03b6));
    Nameral *newnp = delitem(listnp, "zeta");
    apply(newnp, printnv, "%s: %x\n");
    int n = 0;
    apply(newnp, inccounter, &n);
    printf("%d elements in nvlist.\n", n);
    return 0;
}

Nameral *newitem(char *name, int value) {
    Nameral *newp;
    newp = (Nameral *) malloc(sizeof(Nameral));
    newp -> name = name;
    newp -> value = value;
    newp -> next = NULL;
    return newp;
}
 Nameral *addfront(Nameral *listp, Nameral *newp) {
     newp -> next = listp;
     return newp;
 }
 Nameral *addend(Nameral *listp, Nameral *newp) {
     Nameral *p;

     if (listp == NULL) 
        return newp;
    for (p = listp; p -> next != NULL; p = p -> next) ;
    p -> next = newp;
    return listp;   //return the list header pointer
 }
 Nameral *lookup(Nameral *listp, char *name) {
     for ( ; listp != NULL; listp = listp -> next)
        if (strcmp(name, listp -> name) == 0)
            return listp;
    return NULL;
 }
 Nameral *delitem(Nameral *listp, char *name) {
     Nameral *p, *prev;
     prev = NULL;
     for (p=listp; p != NULL; p = p -> next) {
         if (strcmp(name, p -> name) == 0) {
             if (prev == NULL)
                listp = p -> next;
            else
                prev -> next = p -> next;
            free(p);
            return listp;
         }
         prev = p;
     }
     printf("delitem: %s not in list", name);
     return NULL;
 }
 void apply(Nameral *listp, void(*fn)(Nameral *, void *), void *arg) {
     for ( ; listp != NULL; listp = listp -> next) 
        (*fn)(listp, arg); //call the function
 }

 void printnv(Nameral *p, void *arg) {
     char *fmt;
     fmt = (char *)arg;
     printf(fmt, p -> name, p -> value);
 }

 void freeall(Nameral *listp) {
     Nameral *next;
     for ( ; listp != NULL; listp = next) {
         next = listp -> next;
         free(listp);
     }
 }

 void inccounter(Nameral *p, void *arg) {
     int *ip;
     ip = (int *) arg;
     (*ip)++;
 }