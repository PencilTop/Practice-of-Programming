#ifndef MARKOV_H
#define MARKOV_N

enum {
    NPREF = 2,          // number of prefix words
    NHASH = 4093,       // size of  state hash table array
    MAXGEN = 10000,     // maximum words generated
    MULTIPLIER = 9367
};
typedef struct State State;
typedef struct Suffix Suffix;
struct Suffix {         //suffix list
    char    *word;
    Suffix  *next;
};
struct State {          //prefix + suffix list
    char        *pref[NPREF];
    Suffix      *suf;
    State       *next;
};
State *statetab[NHASH];
char NONWORD[] = "\n";

unsigned int hash(char *s[NPREF]);
State *lookup(char *prefix[NPREF], int create);
void build(char *prefix[NPREF], FILE *f);
void add(char *prefix[NPREF], char *suffix);
void addsuffix(State *sp, char *suffix);
void generate(int nwords);

#endif